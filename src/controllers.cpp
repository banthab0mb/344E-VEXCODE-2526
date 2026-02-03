#include "vex.h"
#include "robot-config.h"
#include <cmath>
#include <utility>

using namespace vex;

// Tuning constants
const double curvatureFactor = 1.0;   // Higher = more turn response
const double accelRate = 0.1;         // Smoothing (0–1), smaller = smoother

// Previous smoothed speeds
double lastLeft = 0, lastRight = 0;

void curvatureDrive(double forward, double curvature) {
    double leftPower, rightPower;

    // Curvature affects how sharply it turns
    leftPower = forward + fabs(forward) * curvature * curvatureFactor;
    rightPower = forward - fabs(forward) * curvature * curvatureFactor;

    // Normalize values
    double maxMag = fmax(fabs(leftPower), fabs(rightPower));
    if (maxMag > 1.0) {
    leftPower /= maxMag;
    rightPower /= maxMag;
    }

    // Apply smoothing
    leftPower = lastLeft + (leftPower - lastLeft) * accelRate;
    rightPower = lastRight + (rightPower - lastRight) * accelRate;
    lastLeft = leftPower;
    lastRight = rightPower;

    // Send to motors with voltage control
    double leftVolt = leftPower * 12.0;
    double rightVolt = rightPower * 12.0;

    leftFront.spin(fwd, leftVolt, voltageUnits::volt);
    leftMiddle.spin(fwd, leftVolt, voltageUnits::volt);
    leftBack.spin(fwd, leftVolt, voltageUnits::volt);
    rightFront.spin(fwd, rightVolt, voltageUnits::volt);
    rightMiddle.spin(fwd, rightVolt, voltageUnits::volt);
    rightBack.spin(fwd, rightVolt, voltageUnits::volt);
}

void updateCurvatureDrive() {
  double forward = Controller.Axis3.position(percent) / 100.0;
  double curvature = Controller.Axis1.position(percent) / 100.0;
  curvatureDrive(forward, curvature);
}

void exponential() {
    // x₁ = Left Motors X = [Controller] [3] position + [Controller] [1] position
    // x₂ = Right Motors X = [Controller] [3] position - [Controller] [1] position
    // Sets each motor's velocity (in rpm) to 0.0001x³ (shown as 0.0001 * x * x * x)
    leftFront.spin(forward, (0.0001 * (((Controller.Axis3.position() + Controller.Axis1.position()) * (Controller.Axis3.position() + Controller.Axis1.position())) * (Controller.Axis3.position() + Controller.Axis1.position()))), percent);
    leftMiddle.spin(forward, (0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() + Controller.Axis1.position()))), percent);
    leftBack.spin(forward, (0.0001 * (((Controller.Axis3.position() + Controller.Axis1.position()) * (Controller.Axis3.position() + Controller.Axis1.position())) * (Controller.Axis3.position() + Controller.Axis1.position()))), percent);
    rightFront.spin(forward, (0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() - Controller.Axis1.position()))), percent);
    rightMiddle.spin(forward, (0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() - Controller.Axis1.position()))), percent);
    rightBack.spin(forward, (0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() - Controller.Axis1.position()))), percent);
}

// CHEESY DRIVE

// Constants
#define PI 3.14159265358979323846
#define DRIVE_DEADBAND 0.05
#define DRIVE_SLEW 0.05
#define CD_TURN_NONLINEARITY 0.5
#define CD_NEG_INERTIA_SCALAR 4.0
#define CD_SENSITIVITY 0.85

// We apply a sinusoidal curve (twice) to the joystick input to give finer
// control at small inputs.
static double _turnRemapping(double iturn) {
	double denominator = sin(PI / 2 * CD_TURN_NONLINEARITY);
	double firstRemapIteration =
	    sin(PI / 2 * CD_TURN_NONLINEARITY * iturn) / denominator;
	return sin(PI / 2 * CD_TURN_NONLINEARITY * firstRemapIteration) / denominator;
}

// On each iteration of the drive controller (where we aren't point turning) we
// constrain the accumulators to the range [-1, 1].
double quickStopAccumlator = 0.0;
double negInertiaAccumlator = 0.0;
static void _updateAccumulators() {
	if (negInertiaAccumlator > 1) {
		negInertiaAccumlator -= 1;
	} else if (negInertiaAccumlator < -1) {
		negInertiaAccumlator += 1;
	} else {
		negInertiaAccumlator = 0;
	}

	if (quickStopAccumlator > 1) {
		quickStopAccumlator -= 1;
	} else if (quickStopAccumlator < -1) {
		quickStopAccumlator += 1;
	} else {
		quickStopAccumlator = 0.0;
	}
}

double prevTurn = 0.0;
double prevThrottle = 0.0;
std::pair<double, double> cheesyDrive(double ithrottle, double iturn) {
	bool turnInPlace = false;
	double linearCmd = ithrottle;
	if (fabs(ithrottle) < DRIVE_DEADBAND && fabs(iturn) > DRIVE_DEADBAND) {
		// The controller joysticks can output values near zero when they are
		// not actually pressed. In the case of small inputs like this, we
		// override the throttle value to 0.
		linearCmd = 0.0;
		turnInPlace = true;
	} else if (ithrottle - prevThrottle > DRIVE_SLEW) {
		linearCmd = prevThrottle + DRIVE_SLEW;
	} else if (ithrottle - prevThrottle < -(DRIVE_SLEW * 2)) {
		// We double the drive slew rate for the reverse direction to get
		// faster stopping.
		linearCmd = prevThrottle - (DRIVE_SLEW * 2);
	}

	double remappedTurn = _turnRemapping(iturn);

	double left, right;
	if (turnInPlace) {
		// The remappedTurn value is squared when turning in place. This
		// provides even more fine control over small speed values.
		left = remappedTurn * std::abs(remappedTurn);
		right = -remappedTurn * std::abs(remappedTurn);

	} else {
		double negInertiaPower = (iturn - prevTurn) * CD_NEG_INERTIA_SCALAR;
		negInertiaAccumlator += negInertiaPower;

		double angularCmd =
		    std::abs(linearCmd) *  // the more linear vel, the faster we turn
		        (remappedTurn + negInertiaAccumlator) *
		        CD_SENSITIVITY -  // we can scale down the turning amount by a
		                          // constant
		    quickStopAccumlator;

		right = left = linearCmd;
		left += angularCmd;
		right -= angularCmd;

		_updateAccumulators();
	}

	prevTurn = iturn;
	prevThrottle = ithrottle;
	
	return std::make_pair(left, right);
}

void cheesy() {
  // Get joystick values from the controller
  double throttle = Controller.Axis3.position(percent) / 100.0; // -1 to 1
  double turn = Controller.Axis1.position(percent) / 100.0;     // -1 to 1

  // Run the cheesy drive
  auto motorPower = cheesyDrive(throttle, turn);

  // Apply to all left motors
  leftFront.spin(forward, motorPower.first * 100, percent);
  leftMiddle.spin(forward, motorPower.first * 100, percent);
  leftBack.spin(forward, motorPower.first * 100, percent);

  // Apply to all right motors
  rightFront.spin(forward, motorPower.second * 100, percent);
  rightMiddle.spin(forward, motorPower.second * 100, percent);
  rightBack.spin(forward, motorPower.second * 100, percent);
}
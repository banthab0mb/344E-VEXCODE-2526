#include "vex.h"
#include "robot-config.h"

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
    leftFront.setVelocity((0.0001 * (((Controller.Axis3.position() + Controller.Axis1.position()) * (Controller.Axis3.position() + Controller.Axis1.position())) * (Controller.Axis3.position() + Controller.Axis1.position()))), percent);
    leftMiddle.setVelocity((0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() + Controller.Axis1.position()))), percent);
    leftBack.setVelocity((0.0001 * (((Controller.Axis3.position() + Controller.Axis1.position()) * (Controller.Axis3.position() + Controller.Axis1.position())) * (Controller.Axis3.position() + Controller.Axis1.position()))), percent);
    rightFront.setVelocity((0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() - Controller.Axis1.position()))), percent);
    rightMiddle.setVelocity((0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() - Controller.Axis1.position()))), percent);
    rightBack.setVelocity((0.0001 * (((Controller.Axis3.position() - Controller.Axis1.position()) * (Controller.Axis3.position() - Controller.Axis1.position())) * (Controller.Axis3.position() - Controller.Axis1.position()))), percent);
}
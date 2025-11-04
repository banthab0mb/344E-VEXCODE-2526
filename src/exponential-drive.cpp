#include "vex.h"
#include "robot-config.h"


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
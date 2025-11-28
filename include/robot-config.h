#pragma once

#include <cmath>
#include <cstdint>
#include <string>
#include <vector>

using namespace vex;

extern brain Brain;

extern controller Controller;

// Drive motors

extern motor leftFront;
extern motor leftMiddle;
extern motor leftBack;
extern motor rightFront;
extern motor rightMiddle;
extern motor rightBack;

// Devices

extern motor conveyor;
extern motor scorer;

extern digital_out matchLoader;
extern digital_out trapdoor;
extern digital_out park;
extern digital_out wings;

// Formulas

void vexcodeInit( void );

void conveyorControl();
void scorerControl();
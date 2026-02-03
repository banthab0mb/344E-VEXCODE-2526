#include "vex.h"
#include "sylib/sylib.hpp"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

// Main controller
controller Controller;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

motor leftFront = motor(PORT1, ratio6_1, true);
motor leftMiddle = motor(PORT2, ratio6_1, false);
motor leftBack = motor(PORT3, ratio6_1, true);
motor rightFront = motor(PORT4, ratio6_1, false);
motor rightMiddle = motor(PORT5, ratio6_1, true);
motor rightBack = motor(PORT6, ratio6_1, false);

// Other devices

motor conveyor = motor(PORT7, ratio6_1, false);
motor scorer = motor(PORT8, ratio6_1, true);

digital_out matchLoader = digital_out(Brain.ThreeWirePort.B);
digital_out trapdoor = digital_out(Brain.ThreeWirePort.C);
digital_out park = digital_out(Brain.ThreeWirePort.D);
digital_out wings = digital_out(Brain.ThreeWirePort.E);

// Functions

void vexcodeInit( void ) {
  // nothing to initialize
}

// Control for conveyor
void conveyorControl() {
  if(Controller.ButtonR1.pressing()) {
    conveyor.spin(forward, 12, volt);
  } else if(Controller.ButtonR2.pressing()) {
    conveyor.spin(reverse, 12, volt);
  } else {
    conveyor.stop();
  }
}

// Control for scorer
void scorerControl() {
  if(Controller.ButtonL1.pressing()) {
    scorer.spin(forward, 12, volt);
  } else if(Controller.ButtonL2.pressing()) {
    scorer.spin(reverse, 12, volt);
  } else {
    scorer.stop();
  }
}

// Pneumatic toggles

bool userLoaderState = false;
// Toggle for loader
void userLoaderToggle() {
  userLoaderState = !userLoaderState;
  matchLoader.set(userLoaderState);
}

bool userParkState = false;
// Toggle for double park
void userParkToggle() {
  userParkState = !userParkState;
  park.set(userParkState);
}

bool userTrapdoorState = false;
// Toggle for trapdoor
void userTrapdoorToggle() {
  userTrapdoorState = !userTrapdoorState;
  trapdoor.set(userTrapdoorState);
}

bool userWingsState = false;
// Toggle for wings
void userWingsToggle() {
  userWingsState = !userWingsState;
  wings.set(userWingsState);
}
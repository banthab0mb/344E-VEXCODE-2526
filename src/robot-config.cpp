#include "vex.h"
#include "sylib/sylib.hpp"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

controller Controller;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

motor leftFront = motor(PORT1, ratio6_1, false);
motor leftMiddle = motor(PORT2, ratio6_1, false);
motor leftBack = motor(PORT3, ratio6_1, false);
motor rightFront = motor(PORT4, ratio6_1, true);
motor rightMiddle = motor(PORT5, ratio6_1, true);
motor rightBack = motor(PORT6, ratio6_1, true);

//Add your devices below, and don't forget to do the same in robot-config.h:

motor conveyor = motor(PORT7, ratio6_1, false);
motor scorer = motor(PORT8, ratio6_1, false);

digital_out matchLoader = digital_out(Brain.ThreeWirePort.B);
digital_out trapdoor = digital_out(Brain.ThreeWirePort.C);
digital_out park = digital_out(Brain.ThreeWirePort.D);

bool matchLoaderState = false;
bool trapdoorState = false;
bool parkState = false;

void vexcodeInit( void ) {
  // nothing to initialize
}

void conveyorControl() {
  if(Controller.ButtonR1.pressing()) {
    conveyor.spin(forward, 12, volt);
  } else if(Controller.ButtonR2.pressing()) {
    conveyor.spin(reverse, 12, volt);
  } else {
    conveyor.stop();
  }
}

void scorerControl() {
  if(Controller.ButtonL1.pressing()) {
    scorer.spin(forward, 12, volt);
  } else if(Controller.ButtonL2.pressing()) {
    scorer.spin(reverse, 12, volt);
  } else {
    scorer.stop();
  }
}

void matchLoaderControl() {
  if(Controller.ButtonY.pressing()) {
    matchLoader.set(!matchLoaderState);
  } else if(Controller.ButtonY.pressing()) {
    matchLoader.set(matchLoaderState);
  }
}

void trapdoorControl() {
  if(Controller.ButtonB.pressing()) {
    trapdoor.set(!trapdoorState);
  } else if(Controller.ButtonB.pressing()) {
    trapdoor.set(trapdoorState);
  }
}

void parkControl() {
  if(Controller.ButtonDown.pressing()) {
    park.set(!parkState);
  } else if(Controller.ButtonDown.pressing()) {
    park.set(parkState);
  }
}
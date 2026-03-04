#include "vex.h"
#include "sylib/sylib.hpp"
#include <cmath>
#include <cstdint>
#include <string>
#include <vector>

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

bool loaderState = false;
// Toggle for loader
void loaderToggle() {
  loaderState = !loaderState;
  matchLoader.set(loaderState);
}

bool parkState = false;
// Toggle for double park
void parkToggle() {
  parkState = !parkState;
  park.set(parkState);
}

bool hoodState = false;
// Toggle for hood
void hoodToggle() {
  hoodState = !hoodState;
  hood.set(hoodState);
}

bool wingsState = false;
// Toggle for wings
void wingsToggle() {
  wingsState = !wingsState;
  wings.set(wingsState);
}

// Drives forward X inches
void drive_forward(){
  parkToggle();
  chassis.drive_distance(7);
}

// Solo AWP on red side
void red_solo_awp(){
  // win point auto, 
  odom_constants();

  chassis.set_coordinates(-46.274, -14.764, 0);
  chassis.drive_max_voltage = 12;
  //parkToggle();

  chassis.drive_to_pose(-46.561, -46.859, 0);
  chassis.turn_to_angle(270);
  loaderToggle(); //loader down
  chassis.drive_max_voltage = 4;
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_to_pose(-59.169, -47.145, 270); //at loader
  wait(500, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_max_voltage = 12;
  chassis.drive_to_pose(-31.086, -47.145, 270); // at long goal
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  loaderToggle(); //loader up
  hoodToggle(); //hood up
  scorer.spin(forward, 200, rpm);
  wait(1000, msec); //unloading time
  hoodToggle(); // hood down
  chassis.drive_to_pose(-32.233, -33.39, 75);
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_to_pose(-13.319, -28.519, 75);
  chassis.drive_max_voltage = 4;
  chassis.turn_to_angle(300);
  chassis.drive_to_pose(-30.227, -15.91, 300); // pick up 3 stack
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_to_pose(-11.887, -11.898, 45); // go to bottom middle goal
  conveyor.spin(reverse, 12, volt);
  conveyor2.spin(reverse, 200, rpm);
  scorer.spin(reverse, 85, rpm);
  wait(1500, msec); //unloading time
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_max_voltage = 12;
  chassis.drive_to_pose(-37.677, -4.161, 0);
  chassis.drive_to_pose(33.665, 14.179, 45);
  chassis.drive_max_voltage = 4;
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_to_pose(-12.746, 29.367, 45); // picked up second 3 stack
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_to_pose(-9.881, 9.594, 315); // go to top middle goal
  scorer.spin(reverse, 200, rpm); //unload
  wait(100, msec);
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  wait(1000, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_max_voltage = 12;
  chassis.drive_to_pose(-47.134, 46.847, 315);
  chassis.turn_to_angle(270);
  loaderToggle(); //loader down
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_max_voltage = 4;
  chassis.drive_to_pose(-57.737, 46.847, 270); // at loader
  wait(500, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_max_voltage = 12;
  chassis.drive_to_pose(-30.8, 46.847, 270); // at long goal
  hoodToggle();
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 200, rpm);
}

/** 
 * Solo AWP on blue side
 * Calls the corresponding red side function 
 * b/c of symmetrical field
 */
void blue_solo_awp(){
  red_solo_awp();
}

// Auton for red left start
void red_left(){
  
}

// Auton for red right start
void red_right(){
  //4 block long goal, 3 block mid goal split with long goal push.
  //might need to make loader go down to help grab the 3 stack of blocks
  odom_constants();

  chassis.set_coordinates(-46.274, -14.764, 0);
  chassis.drive_max_voltage = 8;
  //parkToggle();

  chassis.drive_to_pose(-46.561, -46.245, 0);
  chassis.turn_to_angle(270);
  loaderToggle();
  wait(500, msec);  
  chassis.drive_max_voltage = 4;
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_distance(10); //at loader
  wait(500, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_distance(-29); // at long goal
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  loaderToggle();
  hoodToggle(); //hood up
  scorer.spin(forward, 200, rpm);
  wait(2000, msec); //unloading time
  chassis.drive_distance(10);
  hoodToggle(); // hood down
  chassis.drive_to_pose(-32.233, -33.39, 75); 
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_to_pose(-13.319, -22.519, 75); //not working from here
  chassis.turn_to_angle(300); //turns after the 3 stack //this is tghe issue
  chassis.drive_to_pose(-30.227, -15.91, 300);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_to_pose(-8.887, -13.898, 280); // at middle goal
  conveyor.spin(reverse, 12, volt);
  conveyor2.spin(reverse, 200, rpm);
  scorer.spin(reverse, 85, rpm);
  wait(2500, msec); //unloading time
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  //chassis.drive_to_pose(-31.086, -36.256, 270); // ready for wing push
  //chassis.drive_to_pose(-9.881, -36.829, 270); // wing push
  //wholeDrivetrain.stop(hold);
}

/** 
 * Blue left start
 * Calls the corresponding red side function 
 * b/c of symmetrical field
 */
void blue_left(){
  red_left();
}

/** 
 * Blue right start
 * Calls the corresponding red side function 
 * b/c of symmetrical field
 */
void blue_right(){
  red_right();
}

// Skills auton
void skills(){
  //skills auto, one full long goal with two loaders and a park
  odom_constants();
  chassis.set_coordinates(-46.274, -14.764, 0);
  chassis.drive_max_voltage = 8;
  parkToggle();

  chassis.drive_to_pose(-46.561, -46.859, 0);
  chassis.turn_to_angle(270);
  loaderToggle();
  chassis.drive_max_voltage = 4;
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_to_pose(-59.169, -47.145, 270); //at loader 1
  chassis.drive_distance(-3); // loading sequence
  chassis.drive_distance(3);
  wait(2000, msec);
  chassis.drive_distance(-3);
  chassis.drive_distance(3);
  wait(2000, msec);
  chassis.drive_distance(-3);
  chassis.drive_distance(3);
  wait(2000, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  chassis.drive_to_pose(-25.928, -60.327, 270);
  chassis.drive_to_pose(32.244, -59.754, 270);
  chassis.drive_to_pose(46.286, -47.432, 270);
  chassis.turn_to_angle(90);
  chassis.drive_to_pose(30.238, -47.432, 90); // at goal first time
  hoodToggle(); //lift hood up
  conveyor.spin(forward, 12, volt); //unloading sequence for skills (just for safety)
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 200, rpm);
  wait(2500, msec);
  conveyor.spin(reverse, 12, volt);
  conveyor2.spin(reverse, 200, rpm);
  scorer.spin(reverse, 200, rpm);
  wait(100, msec);
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 200, rpm);
  wait(5000, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  wait(1000, msec);
  hoodToggle(); // hood back down
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_to_pose(58.894, -47.432, 90); // at second loader
  chassis.drive_distance(-3); //loading sequence
  chassis.drive_distance(3);
  wait(2000, msec);
  chassis.drive_distance(-3);
  chassis.drive_distance(3);
  wait(2000, msec);
  chassis.drive_distance(-3);
  chassis.drive_distance(3);
  wait(2000, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  hoodToggle(); // hood up
  chassis.drive_to_pose(30.238, -47.432, 90); // at goal second time
  conveyor.spin(forward, 12, volt); //unloading sequence for skills (just for safety)
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 200, rpm);
  wait(2500, msec);
  conveyor.spin(reverse, 12, volt);
  conveyor2.spin(reverse, 200, rpm);
  scorer.spin(reverse, 200, rpm);
  wait(100, msec);
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 200, rpm);
  wait(5000, msec);
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
  wait(1000, msec);
  hoodToggle(); //hood down
  chassis.drive_to_pose(38.262, -33.104, 0); // leave goal
  chassis.drive_to_pose(-62.035, -31.957, 270);
  chassis.turn_to_angle(0); // next to park zone
  conveyor.spin(forward, 12, volt);
  conveyor2.spin(forward, 200, rpm);
  scorer.spin(forward, 85, rpm);
  chassis.drive_max_voltage = 12;
  chassis.drive_to_pose(-63.181, 5, 0); // in park zone with it hopefully cleared.
  conveyor.stop();
  conveyor2.stop();
  scorer.stop();
}
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

bool trapdoorState = false;
// Toggle for trapdoor
void trapdoorToggle() {
  trapdoorState = !trapdoorState;
  trapdoor.set(trapdoorState);
}

bool wingsState = false;
// Toggle for wings
void wingsToggle() {
  wingsState = !wingsState;
  wings.set(wingsState);
}

// Drives forward X inches
void drive_forward(){
  chassis.drive_distance(5);
}

// Solo AWP on red side
void red_solo_awp(){
  odom_constants();

  chassis.set_coordinates(46.5, -16.5, 180);
	chassis.drive_to_pose(45, -34, 900);
	chassis.left_swing_to_angle(700);
	
	loaderToggle();
	trapdoorToggle();
	sylib::delay(250);
	chassis.drive_to_pose(54, -53, 600);
	conveyor.spin(forward, 12, volt);
	
	sylib::delay(250);
	chassis.drive_to_pose(17, -54, 1000);
	
	scorer.spin(forward, 12, volt);
	sylib::delay(800);
	scorer.stop();
	loaderToggle();
	chassis.left_swing_to_angle(900);
	chassis.drive_to_pose(20, -30 , 800);
	chassis.turn_to_angle(135, 800);
	
	sylib::delay(20);
	chassis.drive_to_pose(0, -14 , 700);
	
	scorer.spin(forward, 7.56, volt);
	conveyor.spin(forward, 9, volt);
	trapdoorToggle();
	sylib::delay(700);
	scorer.stop();
	chassis.drive_to_pose(13, -24 , 800);
	trapdoorToggle();
	chassis.turn_to_angle(0, 600);
	chassis.drive_to_pose(16.5, 10 , 1000);
	chassis.turn_to_angle(80, 600);
	chassis.drive_to_pose(35, 39.2, 1000);
	chassis.turn_to_angle(90, 400);
	
	loaderToggle();
	sylib::delay(180);
	chassis.drive_to_pose(55, 40, 700);
	conveyor.spin(forward, 12, volt);
	
	sylib::delay(570);
	conveyor.stop();
	chassis.drive_to_pose(9, 44.5, 800);
	
	conveyor.spin(forward, 12, volt);
	scorer.spin(forward, 12, volt);
	sylib::delay(700);
	chassis.drive_to_pose(25, 44.5, 1000);
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
  odom_constants();

  chassis.set_coordinates(52,-18, 260);
  chassis.drive_to_pose(24, -21, 250);

  conveyor.spin(forward, 12, volt);
  sylib::delay(3000);
  conveyor.stop();

  chassis.drive_to_pose(8, -6, 310);

  conveyor.spin(forward, 12, volt);
  scorer.spin(forward, 12, volt);
  sylib::delay(5000);
  conveyor.stop();
  scorer.stop();

  chassis.drive_to_pose(59, -48, 90);

  loaderToggle();
  chassis.drive_distance(5);
  
  conveyor.spin(forward, 12, volt);
  sylib::delay(5000);
  conveyor.stop();
  loaderToggle();

  chassis.drive_to_pose(25, -47, 90);

  conveyor.spin(forward, 12, volt);
  scorer.spin(forward, 12, volt);
  sylib::delay(5000);
  conveyor.stop();
  scorer.stop();

  chassis.drive_distance(5);
  chassis.drive_distance(-5);
}

// Auton for red right start
void red_right(){
  odom_constants();

  chassis.set_coordinates(46.5, 16.5, 270);

  conveyor.spin(forward, 12, volt);

  chassis.drive_to_pose(12, 25, 1100);
  chassis.drive_to_pose(17, 23, 700);
  chassis.turn_to_angle(-135, 700);

  conveyor.stop();

  chassis.drive_to_pose(9, 20.5, 800);

  conveyor.spin(reverse, 12, volt);

  sylib::delay(1000);

  chassis.drive_to_pose(7, 18, 500);

  conveyor.stop();

  chassis.drive_to_pose(32, 51, 1500);
  chassis.turn_to_angle(90, 900);

  loaderToggle();

  chassis.drive_to_pose(55, 48, 800);
  conveyor.spin(forward, 12, volt);

  sylib::delay(700);

  conveyor.stop();

  chassis.drive_to_pose(10, 49, 1000);

  conveyor.spin(forward, 12, volt);

  scorer.spin(forward, 12, volt);

  sylib::delay(2100);

  chassis.drive_to_pose(27, 49.5, 800);
  chassis.drive_to_pose(10, 49.5, 1500);

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
  
}
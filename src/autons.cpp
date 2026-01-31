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
  parkToggle();
  chassis.drive_distance(7);
}

// Solo AWP on red side
void red_solo_awp(){
  odom_constants();
  chassis.set_coordinates(0,0,0);
  chassis.drive_to_point(0,)

  // chassis.set_coordinates(46.5, -16.5, 180);
	// chassis.drive_to_point(45, -34);
	// chassis.left_swing_to_angle(700);
	
	// loaderToggle();
	// trapdoorToggle();
	// sylib::delay(250);
	// chassis.drive_to_point(54, -53);
	// conveyor.spin(forward, 12, volt);
	
	// sylib::delay(250);
	// chassis.drive_to_point(17, -54);
	
	// scorer.spin(forward, 12, volt);
	// sylib::delay(800);
	// scorer.stop();
	// loaderToggle();
	// chassis.left_swing_to_angle(-45);
	// chassis.drive_to_point(20, -30);
	// chassis.turn_to_angle(135);
	
	// sylib::delay(20);
	// chassis.drive_to_point(0, -14);
	
	// scorer.spin(forward, 7.56, volt);
	// conveyor.spin(forward, 9, volt);
	// trapdoorToggle();
	// sylib::delay(700);
	// scorer.stop();
	// chassis.drive_to_point(13, -24);
	// trapdoorToggle();
	// chassis.turn_to_angle(0);
	// chassis.drive_to_point(16.5, 10);
	// chassis.turn_to_angle(80);
	// chassis.drive_to_point(35, 39.2);
	// chassis.turn_to_angle(90);
	
	// loaderToggle();
	// sylib::delay(180);
	// chassis.drive_to_point(55, 40);
	// conveyor.spin(forward, 12, volt);
	
	// sylib::delay(570);
	// conveyor.stop();
	// chassis.drive_to_point(9, 44.5);
	
	// conveyor.spin(forward, 12, volt);
	// scorer.spin(forward, 12, volt);
	// sylib::delay(700);
	// chassis.drive_to_point(25, 44.5);
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

  wingsToggle();

  chassis.set_coordinates(52,-18, 270);

  chassis.drive_max_voltage = 4;
  conveyor.spin(forward, 12, volt);
  chassis.drive_to_pose(23.287, -23, 250);
  chassis.drive_max_voltage = 8;

  sylib::delay(1000);
  conveyor.stop();

  chassis.turn_to_angle(90);
  loaderToggle();
  
  chassis.drive_max_voltage = 8;
  chassis.drive_to_pose(62, -47, 90);
  
  conveyor.spin(forward, 12, volt);

  sylib::delay(1200);
  conveyor.stop();

  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-30);

  conveyor.spin(forward, 12, volt);
  scorer.spin(forward, 12, volt);
  sylib::delay(2500);
  conveyor.spin(reverse, 12, volt);
  sylib::delay(250);
  conveyor.spin(forward, 12, volt);
  sylib::delay(2500);
  conveyor.spin(reverse, 12, volt);
  sylib::delay(250);
  conveyor.spin(forward, 12, volt);
  loaderToggle();
  sylib::delay(5000);
  conveyor.stop();
  scorer.stop();
}

// Auton for red right start
void red_right(){
  //4 Block Push
  /*odom_constants();

  chassis.set_coordinates(52,18, 270);

  chassis.drive_max_voltage = 4;
  conveyor.spin(forward, 12, volt);
  chassis.drive_to_pose(23.287, 23, 250);
  chassis.drive_max_voltage = 8;

  //sylib::delay(1000);
  //conveyor.stop();

  chassis.drive_to_point(47, 49);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-24);

  conveyor.spin(forward, 12, volt);
  scorer.spin(forward, 12, volt);
  sylib::delay(2000);
  conveyor.stop();
  scorer.stop();

  //chassis.drive_to_pose(47, 47, 270);

  //chassis.drive_to_point(37, 34);
  
  //chassis.turn_to_angle(270);

  //chassis.drive_to_pose(11, 36, 270);
 */
 odom_constants();

  wingsToggle();

  chassis.set_coordinates(52,-18, 270);

  chassis.drive_max_voltage = 4;
  conveyor.spin(forward, 12, volt);
  chassis.drive_to_pose(23.287, -13, 250);
  chassis.drive_max_voltage = 8;

  sylib::delay(1000);
  conveyor.stop();

  chassis.turn_to_angle(90);
  loaderToggle();
  
  chassis.drive_max_voltage = 8;
  chassis.drive_to_pose(62, 11, 90);
  
  conveyor.spin(forward, 12, volt);

  sylib::delay(1200);
  conveyor.stop();

  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-30);

  conveyor.spin(forward, 12, volt);
  scorer.spin(forward, 12, volt);
  sylib::delay(2500);
  conveyor.spin(reverse, 12, volt);
  sylib::delay(250);
  conveyor.spin(forward, 12, volt);
  sylib::delay(2500);
  conveyor.spin(reverse, 12, volt);
  sylib::delay(250);
  conveyor.spin(forward, 12, volt);
  loaderToggle();
  sylib::delay(5000);
  conveyor.stop();
  scorer.stop();
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
  odom_constants();

  // Deploy scraper mech
  //loaderToggle(); 
  
  chassis.drive_max_voltage = 12;
  chassis.drive_distance(20);

  // // Set inital coordinates
  // chassis.set_coordinates(0, 0, 180); 
  
  // // Drive to loader 1
  // chassis.drive_to_pose(0, 31.456, 270);

  // // Line up with loader 1
  // chassis.drive_to_pose(11.543, 31.456, 270);

  // // Empty loader 1
  // conveyor.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  
  // // Drive around goal 1
  // chassis.drive_to_pose(-11.254, 40.111, 110);
  // chassis.drive_to_pose(-42.131, 45.593, 90);
  
  // chassis.drive_to_pose(-97.824, 32.319, 270);
  
  // // Line up with goal 1
  // chassis.drive_to_pose(-77.336, 31.456, 90);

  // // Score load 1
  // conveyor.spin(forward, 12, volt);
  // scorer.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  // scorer.stop();

  // // Line up with loader 2
  // chassis.drive_to_pose(-111.964, 31.456, 90);

  // // Empty loader 2
  // conveyor.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  
  // // Line back up with goal 1
  // chassis.drive_to_pose(-77.336, 31.456, 270);

  // // Score load 2
  // conveyor.spin(forward, 12, volt);
  // scorer.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  // scorer.stop();

  // // Drive to loader 3
  // chassis.drive_to_pose(-87.147, -2.02, 10);

  // // Line up with loader 3
  // chassis.drive_to_pose(-110.809, -62.33, 90);

  // // Empty loader 3
  // conveyor.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  
  // // Drive to goal 2
  // chassis.drive_to_pose(-66.082, -77.624, 270);
  // chassis.drive_to_pose(0, -62.33, 270);
  
  // // Line up with goal 2
  // chassis.drive_to_pose(-22.797, -62.33, 270);

  // // Score load 3
  // conveyor.spin(forward, 12, volt);
  // scorer.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  // scorer.stop();

  // // Line up with loader 4
  // chassis.drive_to_pose(11.254, -61.753, 270);

  // // Empty loader 4
  // conveyor.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  
  // // Line back up with goal 2
  // chassis.drive_to_pose(-23.374, -62.042, 270);

  // // Score load 4
  // conveyor.spin(forward, 12, volt);
  // scorer.spin(forward, 12, volt);
  // sylib::delay(500);
  // conveyor.stop();
  // scorer.stop();

  // // Line up for park
  // chassis.drive_to_pose(12.985, -41.842, 180);

  // // Retract scraper mech
  // loaderToggle();

  // // Park
  // chassis.drive_to_pose(12.985, -17.314, 180);
}
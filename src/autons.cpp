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

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
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
	
	matchLoader.set(true);
	trapdoor.set(false);
	sylib::delay(250);
	chassis.drive_to_pose(54, -53, 600);
	conveyor.spin(forward, 12, volt);
	
	sylib::delay(250);
	chassis.drive_to_pose(17, -54, 1000);
	
	scorer.spin(forward, 12, volt);
	sylib::delay(800);
	scorer.stop();
	matchLoader.set(false);
	chassis.left_swing_to_angle(900);
	chassis.drive_to_pose(20, -30 , 800);
	chassis.turn_to_angle(135, 800);
	
	sylib::delay(20);
	chassis.drive_to_pose(0, -14 , 700);
	
	scorer.spin(forward, 7.56, volt);
	conveyor.spin(forward, 9, volt);
	trapdoor.set(true);
	sylib::delay(700);
	scorer.stop();
	chassis.drive_to_pose(13, -24 , 800);
	trapdoor.set(false);
	chassis.turn_to_angle(0, 600);
	chassis.drive_to_pose(16.5, 10 , 1000);
	chassis.turn_to_angle(80, 600);
	chassis.drive_to_pose(35, 39.2, 1000);
	chassis.turn_to_angle(90, 400);
	
	matchLoader.set(true);
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

  matchLoader.set(true);
  chassis.drive_distance(5);
  
  conveyor.spin(forward, 12, volt);
  sylib::delay(5000);
  conveyor.stop();

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
  chassis.drive_distance(24);
  chassis.turn_to_angle(90);
  chassis.drive_distance(36);
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
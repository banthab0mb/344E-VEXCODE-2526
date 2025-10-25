#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

// JAR Examples
void drive_test();
void turn_test();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();

// Custom Autons
void drive_forward();
void red_solo_awp();
void blue_solo_awp();
void red_left();
void red_right();
void blue_left();
void blue_right();
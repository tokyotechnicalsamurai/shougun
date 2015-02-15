#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * For Teleoperated Mode
 */

//Math Setting
#define PI 3.141592
#define SQRT2 1.414213

//Controller Mode
//1.normal 2.kawabata
#define CONTRLLOER_MODE 2

//Move Robot when these value is true
#define DRIVEMOVE true
#define ELEVATORMOVE true

//SPEED Setting
#define SPEED 0.45//0.3 //for normal Speed in Teleoperated Mode
#define SLOWSPEED 0.2//0.15 //for SLOWMODE Speed in Teleoperated Mode

/*
   Auto mode
             */
//Move2Container Command Setting
#define BACKTIME 0.3
#define CONTAINERDIST 45.0
#define MOVE2CONTAINERTIME 2.0

//BringBurden Command Setting
#define MOVETIME 5.0
#define MOVESPEED 0.3


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
//JoyStick
const int JOYSTICK = 0;

//Controller Button
const int A_BUTTON = 1;
const int B_BUTTON = 2;
const int X_BUTTON = 3;
const int Y_BUTTON = 4;
const int L_BUTTON = 5;
const int R_BUTTON = 6;
const int BACK_BUTTON = 7;
const int START_BUTTON = 8;

//Controller Sticks
const int LEFT_X_STICK = 0;
const int LEFT_Y_STICK = 1;
const int L_STICK = 2;
const int R_STICK = 3;
const int RIGHT_X_STICK = 4;
const int RIGHT_Y_STICK = 5;

//Motors
const int RIGHT_FRONT = 0;
const int LEFT_FRONT = 1;
const int RIGHT_BACK = 2;
const int LEFT_BACK = 3;

//Elevator motors

const int PULL_MOTOR_RIGHT = 4;
const int PULL_MOTOR_LEFT = 5;

//Analog Sensors
const int GYRO_SENSOR = 3;
const int DIST_RIGHT = 1;
const int DIST_LEFT = 2;

//Digital Sensors
const int UNDER_LIMIT = 0;
const int UP_LIMIT = 1;


#endif

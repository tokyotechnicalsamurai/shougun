#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * For Teleoperated Mode
 */
//Move Robot when these value is true
#define DRIVEMOVE true
#define ELEVATORMOVE true

//SPEED Setting
#define SPEED 0.3 //for normal Speed in Teleoperated Mode
#define SLOWSPEED 0.15 //for SLOWMODE Speed in Teleoperated Mode

//Auto mode
#define CONTAINERDIST 20.0
#define MOVE2CONTAINERTIME 0.3

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
//JoyStick
const int JOYSTICK = 0;

//Motors
const int RIGHT_FRONT = 0;
const int LEFT_FRONT = 1;
const int RIGHT_BACK = 2;
const int LEFT_BACK = 3;

//Elevator motors

const int PULL_MOTOR_RIGHT = 4;
const int PULL_MOTOR_LEFT = 5;

//Analog Sensors
const int GYRO_SENSOR = 0;
const int DIST_RIGHT = 1;
const int DIST_LEFT = 2;

//Digital Sensors
const int UNDER_LIMIT = 0;
const int UP_LIMIT = 1;


#endif

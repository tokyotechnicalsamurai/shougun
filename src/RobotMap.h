#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//コントローラーから入ってくる値に掛ける数
//これを大きくすることでスピードを早くすることが出来る
#define SPEED 0.2

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
const int PULL_MOTOR_LEFT = 4;
const int PULL_MOTOR_RIGHT = 5;

//Analog Sensors
const int GYRO_SENSOR = 0;
const int DIST_RIGHT = 1;
const int DIST_LEFT = 2;

//Digital Sensors
const int UNDER_LIMIT = 0;
const int UP_LIMIT = 1;


#endif

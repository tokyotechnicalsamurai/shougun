#ifndef DriveSubsystem_H
#define DriveSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class DriveSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Talon DriveRightFront,DriveLeftFront,DriveRightBack,DriveLeftBack;

public:
	DriveSubsystem();
	void InitDefaultCommand();
	void DriveMotors(float rightFrontSpeed,float leftFrontSpeed,float rightBackSpeed,float leftBackSpeed);
	void Stop();
};

#endif

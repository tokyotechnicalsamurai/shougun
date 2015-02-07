#ifndef ElevatorSubsystem_H
#define ElevatorSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class ElevatorSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Talon pullMotor;

public:
	DigitalInput underSwitch,upSwitch;

	ElevatorSubsystem();
	void InitDefaultCommand();
	void DriveElevator(float pullSpeed);
};

#endif

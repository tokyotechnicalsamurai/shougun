#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() :
		Subsystem("ElevatorSubsystem"),
		pullMotorRight(PULL_MOTOR_RIGHT),pullMotorLeft(PULL_MOTOR_LEFT),
		underSwitch(UNDER_LIMIT),upSwitch(UP_LIMIT)
{

}

void ElevatorSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ElevatorSubsystem::DriveElevator(float pullSpeed){
	pullMotorLeft.Set(pullSpeed);
	pullMotorRight.Set(pullSpeed);
}

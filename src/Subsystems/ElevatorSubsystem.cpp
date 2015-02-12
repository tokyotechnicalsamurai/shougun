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
	//if underSwitch is pushed and pullspeed is plus, elevator doesn't move
	//if upSwitch is pushed and pullspeed is minus, elevator doesn't move
	if(!(underSwitch.Get() && pullSpeed > 0) && !(upSwitch.Get() && pullSpeed < 0)){
		pullMotorLeft.Set(pullSpeed);
		pullMotorRight.Set(pullSpeed);
	}
}

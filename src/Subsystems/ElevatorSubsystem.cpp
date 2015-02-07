#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() :
		Subsystem("ElevatorSubsystem"),pullMotor(PULL_MOTOR),underSwitch(UNDER_LIMIT)
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
	while(!underSwitch.Get()){
	  pullMotor.Set(pullSpeed);
	}
}

#include "DriveSubsystem.h"
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem"),DriveRightFront(RIGHT_FRONT),DriveLeftFront(LEFT_FRONT),
			DriveRightBack(RIGHT_BACK),DriveLeftBack(LEFT_BACK)
{

}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

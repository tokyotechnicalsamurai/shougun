/* This Subsystem is Robot's Motor's system. */
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

/*Drive Each Motor Speed */
void DriveSubsystem::DriveMotors(float speedRightFront,float speedLeftFront,
									float speedRightBack,float speedLeftBack)
{
	DriveRightFront.Set(speedRightFront);
	DriveLeftFront.Set(speedLeftFront);
	DriveRightBack.Set(speedRightBack);
	DriveLeftBack.Set(speedLeftBack);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

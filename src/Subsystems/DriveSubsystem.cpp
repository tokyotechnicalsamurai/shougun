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

// Drive Each Motor Speed
void DriveSubsystem::DriveMotors(float rightFrontSpeed,float leftFrontSpeed,float rightBackSpeed,float leftBackSpeed)
{
	if(DRIVEMOVE){
		// for Left Motor
		leftFrontSpeed = -1 * leftFrontSpeed;
		leftBackSpeed = -1 * leftBackSpeed;

		DriveRightFront.Set(rightFrontSpeed);
		DriveLeftFront.Set(leftFrontSpeed);
		DriveRightBack.Set(rightBackSpeed);
		DriveLeftBack.Set(leftBackSpeed);
	}
}

// Stop ALL Motor
void DriveSubsystem::Stop(){
	DriveRightFront.Disable();
	DriveLeftFront.Disable();
	DriveRightBack.Disable();
	DriveLeftBack.Disable();
}

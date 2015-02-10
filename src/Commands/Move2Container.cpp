#include "Move2Container.h"

Move2Container::Move2Container()
{
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
}

// Called just before this Command runs the first time
void Move2Container::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move2Container::Execute()
{
	while(sensorSubsystem->GetDistLeft() > 10.0 && sensorSubsystem->GetDistRight() > 10.0){
		driveSubsystem->DriveMotors(0.3,-0.3,-0.3,0.3);
	}
	driveSubsystem->DriveMotors(0.3,-0.3,-0.3,0.3);
	Wait(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool Move2Container::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Move2Container::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move2Container::Interrupted()
{

}

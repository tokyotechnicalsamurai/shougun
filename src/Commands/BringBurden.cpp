#include "BringBurden.h"
#include "../RobotMap.h"

BringBurden::BringBurden(float time,float speed)
{
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
	moveTime = time;
	moveSpeed = speed;

}

// Called just before this Command runs the first time
void BringBurden::Initialize()
{
	SetTimeout(moveTime);
}

// Called repeatedly when this Command is scheduled to run
void BringBurden::Execute()
{
	if(moveSpeed > 0){
		driveSubsystem->DriveMotors(-moveSpeed,-moveSpeed,-moveSpeed,-moveSpeed);
	}else{
		driveSubsystem->DriveMotors(moveSpeed,moveSpeed,moveSpeed,moveSpeed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BringBurden::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void BringBurden::End()
{
	driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BringBurden::Interrupted()
{

}

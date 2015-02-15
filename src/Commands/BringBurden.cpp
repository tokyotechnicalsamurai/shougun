#include "BringBurden.h"
#include "../RobotMap.h"

BringBurden::BringBurden()
{
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
	firstZValue = secondZValue =  0;
	ZChangeCount = 0;
}

// Called just before this Command runs the first time
void BringBurden::Initialize()
{
	firstZValue = sensorSubsystem->GetZacceleration();
	SetTimeout(MOVETIME);
}

// Called repeatedly when this Command is scheduled to run
void BringBurden::Execute()
{
	driveSubsystem->DriveMotors(-MOVESPEED,-MOVESPEED,-MOVESPEED,-MOVESPEED);
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

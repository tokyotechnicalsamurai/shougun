#include "BringBurden.h"

BringBurden::BringBurden()
{
	Requires(driveSubsystem);
}

// Called just before this Command runs the first time
void BringBurden::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BringBurden::Execute()
{
	driveSubsystem->DriveMotors(0.3,0.3,0.3,0.3);
	Wait(5.0); // kimeuti
}

// Make this return true when this Command no longer needs to run execute()
bool BringBurden::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BringBurden::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BringBurden::Interrupted()
{

}

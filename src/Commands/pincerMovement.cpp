#include "pincerMovement.h"

pincerMovement::pincerMovement(float time,float speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveSubsystem);
	moveTime = time;
	moveSpeed = speed;

}

// Called just before this Command runs the first time
void pincerMovement::Initialize()
{
	SetTimeout(moveTime);
}

// Called repeatedly when this Command is scheduled to run
void pincerMovement::Execute()
{
	if(moveSpeed > 0){
			driveSubsystem->DriveMotors(moveSpeed,-moveSpeed,-moveSpeed,moveSpeed);
	}else{
			driveSubsystem->DriveMotors(-moveSpeed,moveSpeed,moveSpeed,-moveSpeed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool pincerMovement::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void pincerMovement::End()
{
	driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void pincerMovement::Interrupted()
{

}

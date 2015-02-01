#include "DriveCommand.h"

DriveCommand::DriveCommand()
{
	Requires(DriveSubsystem);
	rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed = 0.0;
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
	rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftFrontSpeed = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
	rightFrontSpeed = oi->GetStickY() * 0.1 + oi->GetStickX() * 0.1 + oi->GetStickZ() * -0.1;
	leftFrontSpeed = oi->GetStickY() * 0.1 + oi->GetStickX() * -0.1 + oi->GetStickZ() * 0.1;
	rightBackSpeed = oi->GetStickY() * 0.1 + oi->GetStickX() * -0.1 + oi->GetStickZ() * -0.1;
	leftBackSpeed = oi->GetStickY() * 0.1 + oi->GetStickX() * 0.1 + oi->GetStickZ() * 0.1;

	DriveSubsystem->DriveMotors(rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{

}

/* 	y-‘O:1,1,1,1
	y-Œã‚ë:-1,-1,-1,-1
	x-‰E‚ÉˆÚ“®:1,-1,-1,1
	x-¶‚ÉˆÚ“®:-1,1,1,-1
	z-‰Eù‰ñ:-1,1,-1,1
	z-¶ù‰ñ:1,-1,1,-1  */

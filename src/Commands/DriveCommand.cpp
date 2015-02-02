#include "DriveCommand.h"

DriveCommand::DriveCommand()
{
	Requires(driveSubsystem);
	rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed = 0.0;
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
	//それぞれのモーターの速度をコントローラーの状態により調整
	rightFrontSpeed = oi->GetStickY() * SPEED + oi->GetStickX() * SPEED + oi->GetStickZ() * SPEED;
	leftFrontSpeed = oi->GetStickY() * SPEED + oi->GetStickX() * -SPEED + oi->GetStickZ() * -SPEED;
	rightBackSpeed = oi->GetStickY() * SPEED + oi->GetStickX() * -SPEED + oi->GetStickZ() * SPEED;
	leftBackSpeed = oi->GetStickY() * SPEED + oi->GetStickX() * SPEED + oi->GetStickZ() * -SPEED;

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

/* 	y-前:1,1,1,1
	y-後ろ:-1,-1,-1,-1
	x-右に移動:1,-1,-1,1
	x-左に移動:-1,1,1,-1
	z-右旋回:1,-1,1,-1
	z-左旋回:-1,1,-1,1  */

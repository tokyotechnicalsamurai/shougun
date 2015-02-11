#include "MoveElevator.h"

MoveElevator::MoveElevator(float moveTime,bool upOrDown)
{
	Requires(elevatorSubsystem);
	time = moveTime;
	up = upOrDown;

}

// Called just before this Command runs the first time
void MoveElevator::Initialize()
{
	SetTimeout(time);
}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute()
{
	if(up){
				elevatorSubsystem->DriveElevator(-1);
	}else{
				elevatorSubsystem->DriveElevator(1);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void MoveElevator::End()
{
	elevatorSubsystem->DriveElevator(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted()
{
	elevatorSubsystem->DriveElevator(0);
}

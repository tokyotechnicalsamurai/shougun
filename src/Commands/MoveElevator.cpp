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

}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute()
{
	if(up){
		elevatorSubsystem->DriveElevator(-1);
	}else{
		elevatorSubsystem->DriveElevator(1);
	}
	Wait(time);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveElevator::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted()
{

}

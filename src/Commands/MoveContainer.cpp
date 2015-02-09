#include "MoveContainer.h"

MoveContainer::MoveContainer()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevatorSubsystem);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
}

// Called just before this Command runs the first time
void MoveContainer::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveContainer::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool MoveContainer::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveContainer::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveContainer::Interrupted()
{

}

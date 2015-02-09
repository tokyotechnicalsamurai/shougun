#include "RaiseContainer.h"

RaiseContainer::RaiseContainer()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevatorSubsystem);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
}

// Called just before this Command runs the first time
void RaiseContainer::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RaiseContainer::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RaiseContainer::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RaiseContainer::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseContainer::Interrupted()
{

}

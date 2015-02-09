#include "DownTrash.h"

DownTrash::DownTrash()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevatorSubsystem);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
}

// Called just before this Command runs the first time
void DownTrash::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DownTrash::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DownTrash::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DownTrash::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DownTrash::Interrupted()
{

}

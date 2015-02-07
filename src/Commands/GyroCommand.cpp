#include "GyroCommand.h"

GyroCommand::GyroCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(sensorSubsystem);
	Requires(driveSubsystem);
}

// Called just before this Command runs the first time
void GyroCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GyroCommand::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool GyroCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GyroCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroCommand::Interrupted()
{

}

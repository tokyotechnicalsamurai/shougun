#include "ElevatorDownCommand.h"

ElevatorDownCommand::ElevatorDownCommand()
{
	Requires(elevatorSubsystem);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ElevatorDownCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorDownCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorDownCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ElevatorDownCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorDownCommand::Interrupted()
{

}

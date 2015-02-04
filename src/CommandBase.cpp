#include "Subsystems/DriveSubsystem.h"
#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveSubsystem* CommandBase::driveSubsystem = NULL;
ElevatorSubsystem* CommandBase::elevatorSubsystem = NULL;

OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

	oi = new OI();

	driveSubsystem = new DriveSubsystem();
	elevatorSubsystem = new ElevatorSubsystem();
}

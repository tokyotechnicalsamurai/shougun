#include "PivotCommand.h"

PivotCommand::PivotCommand(bool isRight,int Angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
	isRightPovit = isRight;
	isFinishPovit = false;
	povitAngle = Angle;
}

// Called just before this Command runs the first time
void PivotCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PivotCommand::Execute()
{
	if(isRightPovit){
		while(sensorSubsystem->GetDegree() < 90){
			driveSubsystem->DriveMotors(SPEED,-SPEED,SPEED,-SPEED);
		}
		isFinishPovit = true;
	}else{
		while(sensorSubsystem->GetDegree() > -90){
			driveSubsystem->DriveMotors(-SPEED,SPEED,-SPEED,SPEED);
		}
		isFinishPovit = true;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool PivotCommand::IsFinished()
{
	return isFinishPovit || oi->GetUregetButton();
}

// Called once after isFinished returns true
void PivotCommand::End()
{
	driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PivotCommand::Interrupted()
{

}

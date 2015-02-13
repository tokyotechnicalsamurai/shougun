#include "AdjustAngle.h"

AdjustAngle::AdjustAngle()
{
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
	rightDist = leftDist = 0;
	isStraighten = false;
}

// Called just before this Command runs the first time
void AdjustAngle::Initialize()
{
	rightDist = sensorSubsystem->GetDistRight();
	leftDist = sensorSubsystem->GetDistLeft();
	SetTimeout(4.0);
}

// Called repeatedly when this Command is scheduled to run
void AdjustAngle::Execute()
{
	rightDist = sensorSubsystem->GetDistRight();
	leftDist = sensorSubsystem->GetDistLeft();
	if(abs(rightDist - leftDist) < 5){
		isStraighten = true;
	}else{
		if(rightDist > leftDist){
			driveSubsystem->DriveMotors(SPEED,0,SPEED,0);
		}else{
			driveSubsystem->DriveMotors(0,SPEED,0,SPEED);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AdjustAngle::IsFinished()
{
	return isStraighten || IsTimedOut();
}

// Called once after isFinished returns true
void AdjustAngle::End()
{
	driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AdjustAngle::Interrupted()
{
	driveSubsystem->Stop();
}

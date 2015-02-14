#include "Move2Container.h"
#include "../RobotMap.h"

Move2Container::Move2Container()
{
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
	countCenter = 0;
}

// Called just before this Command runs the first time
void Move2Container::Initialize()
{
	driveSubsystem->DriveMotors(0.1,0.1,0.1,0.1);
	Wait(BACKTIME);
	SetTimeout(6.0);
}

// Called repeatedly when this Command is scheduled to run
void Move2Container::Execute()
{
	if(sensorSubsystem->GetDistLeft() <= CONTAINERDIST && sensorSubsystem->GetDistRight() <= CONTAINERDIST){
		countCenter++;
	}else{
		countCenter = 0;
	}
	if(countCenter >= 10){
		std::cout << "Success!" << std::endl;
		SetTimeout(MOVE2CONTAINERTIME);
	}
	driveSubsystem->DriveMotors(0.3,-0.3,-0.3,0.3);
	std::cout << "Right" << sensorSubsystem->GetDistRight() << "  Left" << sensorSubsystem->GetDistLeft() << std::endl;

}

// Make this return true when this Command no longer needs to run execute()
bool Move2Container::IsFinished()
{
	return  IsTimedOut();
}

// Called once after isFinished returns true
void Move2Container::End()
{
	driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move2Container::Interrupted()
{
	driveSubsystem->Stop();
}

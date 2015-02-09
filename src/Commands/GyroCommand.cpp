#include "GyroCommand.h"

GyroCommand::GyroCommand()
{
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	clock = new Timer;
	base = 0;
	prespeed = 0;
	deg = 0;
	beforetime = clock->Get();
}

// Called just before this Command runs the first time
void GyroCommand::Initialize()
{
	driveSubsystem->Stop();
	Wait(0.5);
	for(short i = 0  ;  i < 10  ;  i++){
		base += sensorSubsystem->GetGyro();
	}
	base /= 10;
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
//this function is used in loop.  In the loop, we can check degree of robot by using this.
float GyroCommand::GetValue()
{
	float data = 0;
	float time;
	int speed;

	for(short i = 0  ;  i < 10  ;  i++){
		data = sensorSubsystem->GetGyro();
	}
	data /= 10;
	data -= base;
//	if(-3 < data  &&  data < 3) data = 0;
	time = clock->Get() - beforetime;
	speed = data / 4095 * 5 / 0.0067;
	deg += (prespeed + speed) / 2 * time;
	beforetime = clock->Get();
	prespeed = speed;

	return(deg);
}

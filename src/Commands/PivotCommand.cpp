#include "PivotCommand.h"

PivotCommand::PivotCommand(bool isRight,int Angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);
	isRightPovit = isRight;

	isFinishPovit = false;
	/*
	povitAngle = Angle;
	clock.Start();
	baseTime = base = 0;
	for(short i = 0;i < 10;i++){
		base += gyro.GetVoltage();
	}
	base /= 10.0;
	baseTime = clock.Get();
	deg = 0;
	prespeed = 0;
	*/
}

// Called just before this Command runs the first time
void PivotCommand::Initialize()
{
	SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void PivotCommand::Execute()
{
	/*float data = 0;
	float time;
	float speed;
	*/
	while(!isFinishPovit || !IsTimedOut()){
		/*
		for(short i = 0  ;  i < 10  ;  i++){
			data += gyro.GetVoltage();
		}
		data /= 10.0;
		data -= base;
		if(-0.006 < data  &&  data < 0.006) data = 0;
		speed = data / 0.0067;
		time = clock.Get() - baseTime;
		baseTime = clock.Get();
		deg += (prespeed + speed) / 2.0 * time;
		prespeed = speed;
		std::cout << deg << std::endl;
		*/
		if(isRightPovit){
			if(sensorSubsystem->GetDegree() > -90){
				driveSubsystem->DriveMotors(SPEED,-SPEED,SPEED,-SPEED);
			}else{
				isFinishPovit = true;
			}
		}else{
			if(sensorSubsystem->GetDegree() < 90){
				driveSubsystem->DriveMotors(-SPEED,SPEED,-SPEED,SPEED);
			}else{
				isFinishPovit = true;
			}
		}
	}

}

// Make this return true when this Command no longer needs to run execute()
bool PivotCommand::IsFinished()
{
	return isFinishPovit || oi->GetUregetButton() || IsTimedOut();
}

// Called once after isFinished returns true
void PivotCommand::End()
{
	driveSubsystem->Stop();
	std::cout << "End" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PivotCommand::Interrupted()
{

}

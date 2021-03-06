#include "PivotCommand.h"
//if state is true, this command uses to rotate angle.
//if not, this command is used to parallel move
PivotCommand::PivotCommand(float Angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);

	isFinishPovit = false;
	povitAngle = Angle;
	if(povitAngle > 0){
		isRightPovit = false;
	}else{
		isRightPovit = true;
	}
	deg = 0;
	base = 0;
	prespeed = 0;
	clock = new Timer();

	clock->Start();
	driveSubsystem->DriveMotors(0 , 0 , 0 , 0);
	Wait(0.2);
	for(short i = 0  ;  i < 10  ;  i++){
		base += sensorSubsystem->GetGyro();
	}
	base /= 10.0;
	beforetime = clock->Get();
}

// Called just before this Command runs the first time
void PivotCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PivotCommand::Execute()
{
	float data = 0;
	float time , speed;

	for(short i = 0  ;  i < 10  ;  i++){
		data += sensorSubsystem->GetGyro();
	}
	std::cout << "data : " << data;
	data /= 10.0;
	data -= base;
	if(-0.005 < data  &&  data < 0.005) data = 0;
	speed = data / 0.0067;
	time = clock->Get() - beforetime;
	beforetime = clock->Get();
	deg += (prespeed + speed) / 2.0 * time;
	prespeed = speed;
	std::cout << "  deg : " <<  deg << std::endl;

	if(isRightPovit){
		if(deg > povitAngle){
			driveSubsystem->DriveMotors(0.35 , -0.35 , 0.35 , -0.35);
		}else{
			isFinishPovit = true;
		}
	}else{
		if(deg < povitAngle){
			driveSubsystem->DriveMotors(-0.35 , 0.35 , -0.35 , 0.35);
		}else{
			isFinishPovit = true;
		}
	}
	Wait(0.01);
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
	std::cout << "End" << std::endl;
	isFinishPovit = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PivotCommand::Interrupted()
{

}

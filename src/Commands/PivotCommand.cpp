#include "PivotCommand.h"
//if state is true, this command uses to rotate angle.
//if not, this command is used to parallel move
PivotCommand::PivotCommand(float Angle , bool state , bool state2/* , bool state3*/)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);

	isFinishPovit = false;
	povitAngle = Angle;
	breaktime = abs(Angle);
	if(povitAngle > 0){
		isRightPovit = false;
	}else{
		isRightPovit = true;
	}
	parallel_state = state;
	dist_state = state2;
}

// Called just before this Command runs the first time
void PivotCommand::Initialize()
{
  	SetTimeout(1.2);
}

// Called repeatedly when this Command is scheduled to run
void PivotCommand::Execute()
{
	Timer* clock = new Timer();
	float deg , base , prespeed , beforetime , starttime;

	clock->Start();
	deg = 0;
	base = 0;
	prespeed = 0;
	driveSubsystem->DriveMotors(0 , 0 , 0 , 0);
	Wait(0.2);
	for(short i = 0  ;  i < 10  ;  i++){
		base += sensorSubsystem->GetGyro();
	}
	base /= 10.0;
	std::cout << "base " << base << std::endl;
	starttime = clock->Get();
	beforetime = clock->Get();

	while(!isFinishPovit){
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

		if(!parallel_state){ //right angle
			if(isRightPovit){
				if(deg > povitAngle){
					driveSubsystem->DriveMotors(0.35 , -0.35 , 0.35 , -0.35);
				}else{
					break;
				}
			}else{
				if(deg < povitAngle){
					driveSubsystem->DriveMotors(-0.35 , 0.35 , -0.35 , 0.35);
				}else{
					break;
				}
			}
			if(IsTimedOut()) break;
		}else{
			float gap;
			if(-10.0 < deg  &&  deg < 10.0){
				gap = deg * 0.01;
			}else{
				gap = ((gap > 0) ? 0.1 : -0.1);
			}
			driveSubsystem->DriveMotors(-(MOVESPEED - gap) , -(MOVESPEED + gap) , -(MOVESPEED - gap) , -(MOVESPEED + gap));
			if(clock->Get() - starttime > breaktime) isFinishPovit = true;
			if(dist_state){
				float left , right;
				left = sensorSubsystem->GetDistLeft();
				right = sensorSubsystem->GetDistRight();
				if(left <= CONTAINERDIST  &&  right <= CONTAINERDIST){
					break;
				}
			}
		}

		Wait(0.01);
	}
	std::cout << povitAngle << "   finish\n";

}

// Make this return true when this Command no longer needs to run execute()
bool PivotCommand::IsFinished()
{
	return isFinishPovit || oi->GetUregetButton() || (!parallel_state && IsTimedOut());
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

#include "PivotCommand.h"

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
	std::cout << "hello world\n";
	SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void PivotCommand::Execute()
{
	Timer* clock = new Timer();
	float deg , base , prespeed , beforetime , starttime;

	std::cout << "wey soiya\n";
	clock->Start();
	deg = 0;
	base = 0;
	prespeed = 0;
	for(short i = 0  ;  i < 10  ;  i++){
		base += sensorSubsystem->GetGyro();
	}
	base /= 10.0;
	starttime = clock->Get();
	beforetime = clock->Get();

	while(!isFinishPovit || !IsTimedOut()){
		float data = 0;
		float time , speed;

		for(short i = 0  ;  i < 10  ;  i++){
			data += sensorSubsystem->GetGyro();
		}
		data /= 10.0;
		data -= base;
		if(-0.006 < data  &&  data < 0.006) data = 0;
		speed = data / 0.0067;
		time = clock->Get() - beforetime;
		beforetime = clock->Get();
		deg += (prespeed + speed) / 2.0 * time;
		prespeed = speed;
		std::cout << "deg : " <<  deg << std::endl;

		if(!parallel_state){
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
		}else{
			float gap;
			if(-10.0 < deg  &&  deg < 10.0){
				gap = deg * 0.01;
			}else{
				gap = ((gap > 0) ? 0.1 : -0.1);
			}
			if(isRightPovit){
				driveSubsystem->DriveMotors(SPEED + gap , -SPEED + gap , -SPEED + gap , SPEED + gap);
			}else{
				driveSubsystem->DriveMotors(-SPEED + gap , SPEED + gap , SPEED + gap , -SPEED + gap);
			}
			if(IsTimedOut()  ||  clock->Get() - starttime > 2.0) break;
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
	std::cout << "finish\n";

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

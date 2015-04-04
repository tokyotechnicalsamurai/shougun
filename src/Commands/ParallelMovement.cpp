#include "ParallelMovement.h"
//if state is true, this command uses to rotate angle.
//if not, this command is used to parallel move
ParallelMovement::ParallelMovement(float Time , short state)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveSubsystem);
	Requires(sensorSubsystem);

	breaktime = Time;
	vector_state = state;
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
void ParallelMovement::Initialize()
{
  	SetTimeout(breaktime);
}

// Called repeatedly when this Command is scheduled to run
void ParallelMovement::Execute()
{
	float data = 0;
	float time , speed , gap;

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

	if(-10.0 < deg  &&  deg < 10.0){
		gap = deg * 0.01;
	}else{
		gap = ((deg > 0) ? 0.1 : -0.1);
	}
	switch(vector_state){
		case GO : {
			driveSubsystem->DriveMotors(-( MOVESPEED - gap) , -( MOVESPEED + gap) , -( MOVESPEED - gap) , -( MOVESPEED + gap));
			break;
		}
		case BACK : {
			driveSubsystem->DriveMotors(-(-MOVESPEED - gap) , -(-MOVESPEED + gap) , -(-MOVESPEED - gap) , -(-MOVESPEED + gap));
			break;
		}
		case RIGHT : {
			driveSubsystem->DriveMotors(-(-MOVESPEED - gap) , -( MOVESPEED + gap) , -( MOVESPEED - gap) , -(-MOVESPEED + gap));
			break;
		}
		case LEFT : {
			driveSubsystem->DriveMotors(-( MOVESPEED - gap) , -(-MOVESPEED + gap) , -(-MOVESPEED - gap) , -( MOVESPEED + gap));
			break;
		}
	}

	Wait(0.01);
}

// Make this return true when this Command no longer needs to run execute()
bool ParallelMovement::IsFinished()
{
	return oi->GetUregetButton() || IsTimedOut();
}

// Called once after isFinished returns true
void ParallelMovement::End()
{
	driveSubsystem->Stop();
	std::cout << "End" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ParallelMovement::Interrupted()
{

}

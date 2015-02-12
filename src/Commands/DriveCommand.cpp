#include "DriveCommand.h"
#include <iostream>

DriveCommand::DriveCommand()
{
	Requires(driveSubsystem);
	Requires(elevatorSubsystem);
	Requires(sensorSubsystem);
	rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed  = 0.0;
	speed = SPEED;
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
	//それぞれのモーターの速度をコントローラーの状態により調整
	speed = SPEED;
	if(oi->GetStickRightButton()){
		speed = SLOWSPEED;
	}
	rightFrontSpeed = oi->GetXplusY() * speed + oi->GetStickThrottle() * speed - oi->GetStickTwist() * speed;
	leftFrontSpeed = oi->GetXminusY() * speed + oi->GetStickTwist() * speed - oi->GetStickThrottle() * speed;
	rightBackSpeed = oi->GetXminusY() * speed + oi->GetStickThrottle() * speed - oi->GetStickTwist() * speed;
	leftBackSpeed = oi->GetXplusY() * speed + oi->GetStickTwist() * speed - oi->GetStickThrottle() * speed;

	driveSubsystem->DriveMotors(rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed);

	if(elevatorSubsystem->underSwitch.Get()){
		elevatorSubsystem->DriveElevator(-0.1);
		Wait(0.05);
	}else if(elevatorSubsystem->upSwitch.Get()){
		elevatorSubsystem->DriveElevator(0.1);
		Wait(0.05);
	}
	if(elevatorSubsystem->underSwitch.Get() && oi->GetStcikRightY() > 0){
		elevatorSubsystem->DriveElevator(0);
	}else if(elevatorSubsystem->upSwitch.Get() && oi->GetStcikRightY() < 0){
		elevatorSubsystem->DriveElevator(0);
	}else{
		elevatorSubsystem->DriveElevator(oi->GetStcikRightY());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
	return oi->GetUregetButton();
}

// Called once after isFinished returns true
void DriveCommand::End()
{
	driveSubsystem->Stop();
	elevatorSubsystem->DriveElevator(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{

}

/* 	y-前:1,1,1,1
	y-後ろ:-1,-1,-1,-1
	x-右に移動:1,-1,-1,1
	x-左に移動:-1,1,1,-1
	z-右旋回:1,-1,1,-1
	z-左旋回:-1,1,-1,1  */

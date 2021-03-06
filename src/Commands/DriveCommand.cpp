#include "DriveCommand.h"
#include <iostream>
#include <math.h>

DriveCommand::DriveCommand()
{
	Requires(driveSubsystem);
	Requires(elevatorSubsystem);
	Requires(sensorSubsystem);
	rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed  = 0.0;
	speed = SPEED;
	direction = 0;
	isFinishAdjust = false;
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{

}
// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
	std::cout << "Right" << sensorSubsystem->GetDistRight() << "  Left" << sensorSubsystem->GetDistLeft() << std::endl;
	while(oi->GetButton(A_BUTTON) && !isFinishAdjust){
		AdjustAngle();
	}
	isFinishAdjust = false;
	speed = SPEED;
	if(oi->GetStickRightButton()){
		speed = SLOWSPEED;
	}
	/*
	if(oi->GetSitckLeftButton()){
		AbsAngleDriveCommand();
	}else */
	if(oi->GetStickPov() != -1){
		POVAngleDriveCommand(oi->GetStickPov());
	}else{
		switch(CONTRLLOER_MODE){
			//normal mode
			case 1:{
				NormalDriveCommand();
				break;
			}
			//kawabata mode
			case 2:{
				KawabataDriveCommand();
				break;

			}
		}
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
	driveSubsystem->Stop();
	elevatorSubsystem->DriveElevator(0);

}

void DriveCommand::AdjustAngle(){
	float rightDist,leftDist;
	rightDist = sensorSubsystem->GetDistRight();
	leftDist = sensorSubsystem->GetDistLeft();
	if(abs(rightDist - leftDist) < 2){
		isFinishAdjust = true;
	}else{
		if(rightDist < leftDist){
			driveSubsystem->DriveMotors(0,-SPEED,0,-SPEED);
		}else{
			driveSubsystem->DriveMotors(-SPEED,0,-SPEED,0);
		}
	}

}

//Normal Command Function
void DriveCommand::NormalDriveCommand()
{
	rightFrontSpeed = pow(oi->GetXplusY(),3.0) * speed + oi->GetStickThrottle() * speed - oi->GetStickTwist() * speed;
	leftFrontSpeed = pow(oi->GetXminusY(),3.0) * speed + oi->GetStickTwist() * speed - oi->GetStickThrottle() * speed;
	rightBackSpeed = pow(oi->GetXminusY(),3.0) * speed + oi->GetStickThrottle() * speed - oi->GetStickTwist() * speed;
	leftBackSpeed = pow(oi->GetXplusY(),3.0) * speed + oi->GetStickTwist() * speed - oi->GetStickThrottle() * speed;
	driveSubsystem->DriveMotors(rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed);
	if(elevatorSubsystem->underSwitch.Get()){
		elevatorSubsystem->DriveElevator(-0.1);
		Wait(0.05);
	}else if(elevatorSubsystem->upSwitch.Get()){
		elevatorSubsystem->DriveElevator(0.1);
		Wait(0.05);
	}
	elevatorSubsystem->DriveElevator(oi->GetStickRightY());
}

//Kawabata mode Command Function
void DriveCommand::KawabataDriveCommand()
{
	rightFrontSpeed = oi->GetXplusY() * speed + (1.4 * oi->GetStickRightX())  * speed;
	leftFrontSpeed = oi->GetXminusY() * speed - (1.4 * oi->GetStickRightX())  * speed;
	rightBackSpeed = oi->GetXminusY() * speed + (1.4 * oi->GetStickRightX())  * speed;
	leftBackSpeed = oi->GetXplusY() * speed - (1.4 * oi->GetStickRightX())  * speed;
	driveSubsystem->DriveMotors(rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed);
	if(elevatorSubsystem->underSwitch.Get()){
		elevatorSubsystem->DriveElevator(-0.1);
		Wait(0.05);
	}else if(elevatorSubsystem->upSwitch.Get()){
		elevatorSubsystem->DriveElevator(0.1);
		Wait(0.05);
	}
	elevatorSubsystem->DriveElevator(oi->GetStickTwist() - oi->GetStickThrottle() );
}

void DriveCommand::AbsAngleDriveCommand()
{
	float xSpeed,ySpeed,power;
	xSpeed = oi->GetStickX();
	ySpeed = oi->GetStickY();
	if(ySpeed == 0 && xSpeed > 0) direction = 0;
	else if(ySpeed == 0 && xSpeed < 0) direction = PI;
	else if(ySpeed > 0 && xSpeed == 0) direction = PI / 2;
	else if(ySpeed < 0 && xSpeed == 0) direction = PI * 3 / 2;
	else direction = atan( xSpeed / ySpeed );

	direction -= sensorSubsystem->GetCompass() * PI / 180.0;
	power = abs(xSpeed) + abs(ySpeed);
	rightFrontSpeed = speed * ((sin(direction) - cos(direction)*SQRT2)) * (power - oi->GetStickRightX());
	leftFrontSpeed = speed *((sin(direction) - cos(direction)*SQRT2)) * (power + oi->GetStickRightX());
	rightBackSpeed = speed * ((sin(direction) - cos(direction)*SQRT2)) * (power + oi->GetStickRightX());
	leftBackSpeed = speed * ((sin(direction) - cos(direction)*SQRT2)) * (power + oi->GetStickRightX());
	driveSubsystem->DriveMotors(rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed);

	elevatorSubsystem->DriveElevator(oi->GetStickThrottle() - oi->GetStickTwist());
}

void DriveCommand::POVAngleDriveCommand(int angle){
	switch(angle){
		case 0:
			rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed = -speed;
			break;
		case 90:
			rightFrontSpeed = leftBackSpeed = speed;
			leftFrontSpeed = rightBackSpeed = -speed;
			break;
		case 180:
			rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed = speed;
			break;
		case 270:
			rightFrontSpeed = leftBackSpeed = -speed;
			leftFrontSpeed = rightBackSpeed = speed;
			break;
		default:
			rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed = 0;
			break;
	}
	driveSubsystem->DriveMotors(rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed);

	elevatorSubsystem->DriveElevator(oi->GetStickThrottle() - oi->GetStickTwist());
}
/* 	y-前:1,1,1,1
	y-後ろ:-1,-1,-1,-1
	x-右に移動:1,-1,-1,1
	x-左に移動:-1,1,1,-1
	z-右旋回:1,-1,1,-1
	z-左旋回:-1,1,-1,1  */

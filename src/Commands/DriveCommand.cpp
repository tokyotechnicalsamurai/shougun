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
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{

}
// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{

	speed = SPEED;
	if(oi->GetStickRightButton()){
		speed = SLOWSPEED;
	}

	if(oi->GetSitckLeftButton()){
		AbsAngleDriveCommand();
	}else if(oi->GetStickPov() != -1){
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

}

//Normal Command Function
void DriveCommand::NormalDriveCommand()
{
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
	elevatorSubsystem->DriveElevator(oi->GetStickRightY());
}

//Kawabata mode Command Function
void DriveCommand::KawabataDriveCommand()
{
	rightFrontSpeed = oi->GetXplusY() * speed + oi->GetStickRightX()  * speed;
	leftFrontSpeed = oi->GetXminusY() * speed - oi->GetStickRightX()  * speed;
	rightBackSpeed = oi->GetXminusY() * speed + oi->GetStickRightX()  * speed;
	leftBackSpeed = oi->GetXplusY() * speed - oi->GetStickRightX()  * speed;
	driveSubsystem->DriveMotors(rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed);
	if(elevatorSubsystem->underSwitch.Get()){
		elevatorSubsystem->DriveElevator(-0.1);
		Wait(0.05);
	}else if(elevatorSubsystem->upSwitch.Get()){
		elevatorSubsystem->DriveElevator(0.1);
		Wait(0.05);
	}
	elevatorSubsystem->DriveElevator(oi->GetStickThrottle() - oi->GetStickTwist());
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
			rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed = speed;
			break;
		case 90:
			rightFrontSpeed = leftBackSpeed = speed;
			leftFrontSpeed = rightBackSpeed = -speed;
			break;
		case 180:
			rightFrontSpeed = leftFrontSpeed = rightBackSpeed = leftBackSpeed = -speed;
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
/* 	y-‘O:1,1,1,1
	y-Œã‚ë:-1,-1,-1,-1
	x-‰E‚ÉˆÚ“®:1,-1,-1,1
	x-¶‚ÉˆÚ“®:-1,1,1,-1
	z-‰Eù‰ñ:1,-1,1,-1
	z-¶ù‰ñ:-1,1,-1,1  */

#include "SensorSubsystem.h"
#include "../RobotMap.h"
#include <iostream>
#include <math.h>
#define PI 3.141592

SensorSubsystem::SensorSubsystem() :
		Subsystem("SensorSubsystem")
{
	gyro = new AnalogInput(GYRO_SENSOR);
	dist_left = new AnalogInput(DIST_LEFT);
	dist_right = new AnalogInput(DIST_RIGHT);
	acceleration = new I2C(I2C::kOnboard , 0b0011000);
	compass = new I2C(I2C::kOnboard , 0x1E);
	clock = new Timer();

	deg = 0;
	base = 0;
	prespeed = 0;
	beforetime = 0;

	acceleration->Write(0x20 , 0x7F);
	acceleration->Write(0x23 , 0x08);
	compass->Write(0x02 , 0x00);
	clock->Start();
	for(short i = 0  ;  i < 10  ;  i++){
		base += GetGyro();
	}
	base /= 10.0;
	beforetime = clock->Get();
}

void SensorSubsystem::InitDefaultCommand()
{
	//b Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

int SensorSubsystem::GetGyro(void)
{
	return(gyro->GetValue());
}

//Dist sensor is unsustainable, so we may calculate average value.
float SensorSubsystem::GetDistLeft(void)
{
	float ans = 0;
	for(short i = 0  ;  i < 10  ;  i++){
		ans += dist_left->GetVoltage();
	}
	ans /= 10.0;
	ans = 30.0 / ans; //for meter from input
	return(ans);
}

float SensorSubsystem::GetDistRight(void)
{
	float ans = 0;
	for(short i = 0  ;  i < 10  ;  i++){
		ans += dist_right->GetVoltage();
	}
	ans /= 10.0;
	ans = 30.0 / ans; //for meter from input
	return(ans);
}

int SensorSubsystem::GetXacceleration(void)
{
	unsigned char array[2];
	short x;

	acceleration->Write(0x20 , 0x7F);//These sentenses should be always done?
	acceleration->Write(0x23 , 0x08);//
	acceleration->Read(0x28 , 1 , &array[0]);
	acceleration->Read(0x29 , 1 , &array[1]);

	x = (array[1] << 8) | array[0];

	std::cout << "x = " << x << std::endl;
	return(x);
}

int SensorSubsystem::GetYacceleration(void)
{
	unsigned char array[2];
	short y;

	acceleration->Write(0x20 , 0x7F);
	acceleration->Write(0x23 , 0x08);
	acceleration->Read(0x30 , 1 , &array[0]);
	acceleration->Read(0x31 , 1 , &array[1]);

	y = (array[1] << 8) | array[0];

	std::cout << "y = " << y << std::endl;
	return(y);
}

int SensorSubsystem::GetZacceleration(void)
{
	unsigned char array[2];
	short z;

	acceleration->Write(0x20 , 0x7F);
	acceleration->Write(0x23 , 0x08);
	acceleration->Read(0x32 , 1 , &array[0]);
	acceleration->Read(0x33 , 1 , &array[1]);

	z = (array[1] << 8) | array[0];

	std::cout << "z = " << z << std::endl;
	return(z);
}

//This function is used in loop to check degree.
float SensorSubsystem::GetDegree(void)
{
	float data = 0;
	float time;
	float speed;

	for(short i = 0  ;  i < 10  ;  i++){
		data += gyro->GetVoltage();
	}
	data /= 10.0;
	data -= base;
	if(-0.006 < data  &&  data < 0.006) data = 0;
	speed = data / 0.0067;
	time = clock->Get() - beforetime;
	beforetime = clock->Get();
	deg += (prespeed + speed) / 2.0 * time;
	prespeed = speed;
	std::cout << deg << std::endl;
	return(deg);
}

float SensorSubsystem::GetCompass(void)
{
	unsigned char array[4];
	short x , y;
	float tan;
	for(short i = 0  ;  i < 4  ;  i++){
		compass->Read(0x03 + i , 1 , &array[i]);
	}
	x = (array[0] << 8) | array[1];
	y = (array[2] << 8) | array[3];
	if(x){
		tan = y;
		tan /= x;
		return((atan(tan) / PI * 180) + ((y > 0) ? 0 : 180));
	}else{
		return((y > 0) ? 90 : 270);
	}
}

#include "SensorSubsystem.h"
#include "../RobotMap.h"
#include <iostream>

SensorSubsystem::SensorSubsystem() :
		Subsystem("SensorSubsystem")
{
	gyro = new AnalogInput(GYRO_SENSOR);
	dist_left = new AnalogInput(DIST_LEFT);
	dist_right = new AnalogInput(DIST_RIGHT);
	acceleration = new I2C(I2C::kOnboard , 0b0011000);
	acceleration->Write(0x20 , 0x7F);
}

void SensorSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
int SensorSubsystem::GetGyro(void)
{
	return(gyro->GetValue());
}
//Dist sensor is unsustainable, so we may calculate average value.
int SensorSubsystem::GetDistLeft(void)
{
	unsigned int ans = 0;
	for(short i = 0  ;  i < 10  ;  i++){
		ans += dist_left->GetValue();
	}
	ans /= 10;
	ans = 30 / ans; //for meter from input
	return(ans);
}

int SensorSubsystem::GetDistRight(void)
{
	unsigned int ans = 0;
	for(short i = 0  ;  i < 10  ;  i++){
		ans += dist_right->GetValue();
	}
	ans /= 10;
	ans = 30 / ans;
	return(ans);
}
//At first, we only check the value of X.  If it succeed, this function return X value.
int SensorSubsystem::GetXacceleration(void)
{
	unsigned char array1[10] = "";
	unsigned char array2[10] = "";
	acceleration->Read(0x28 , 2 , array1);
	acceleration->Read(0x29 , 2 , array2);
	for(short i = 0  ;  i < 10  ;  i++){
		if(array1[i] == '\0') break;
		std::cout << "X_L[" << i << "]" << " = " << array1[i] << std::endl;
	}
	std::cout << std::endl;
	for(short i = 0  ;  i < 10  ;  i++){
		if(array2[i] == '\0') break;
		std::cout << "X_H[" << i << "]" << " = " << array2[i] << std::endl;
	}
	return(0);
}
//Y and Z are not written yet because I am tired.
int SensorSubsystem::GetYacceleration(void)
{
	return(0);
}

int SensorSubsystem::GetZacceleration(void)
{
	return(0);
}
//This is a test whether we can use I2C.
void SensorSubsystem::AccelerationTest(void)
{
	unsigned char array[2];
	acceleration->Read(0x0F , 2 , array);
	for(short i = 0  ;  i < 2  ;  i++){
		std::cout << "array[" << i << "]" << " = " << array[i] << std::endl;
	}
}

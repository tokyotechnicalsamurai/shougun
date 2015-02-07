#ifndef SensorSubsystem_H
#define SensorSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SensorSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AnalogInput* gyro;
	AnalogInput* dist_left;
	AnalogInput* dist_right;
	I2C* acceleration;
public:
	SensorSubsystem();
	void InitDefaultCommand();
	int GetGyro(void);
	int GetDistLeft(void);
	int GetDistRight(void);
	int GetXacceleration(void);
	int GetYacceleration(void);
	int GetZacceleration(void);
	void AccelerationTest(void);
};

#endif

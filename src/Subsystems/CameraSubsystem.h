#ifndef CameraSubsystem_H
#define CameraSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CameraSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	USBCamera usbCamera;

public:
	CameraSubsystem();
	void InitDefaultCommand();
};

#endif

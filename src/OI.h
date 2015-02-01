#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include <math.h>

class OI
{
private:
	Joystick Joystick;

public:
	OI();
	inline float GetStickX(){ return FractionOmitted(Joystick.GetX()); }
	inline float GetStickY(){ return FractionOmitted(Joystick.GetY()); }
	inline float GetStickZ(){ return FractionOmitted(Joystick.GetZ()); }

	inline float FractionOmitted(float original){
		if(fabsf(original) < 0.01 ){
			original = 0;
		}
		return original;
	}
};

#endif

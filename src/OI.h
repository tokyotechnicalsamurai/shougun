#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include <math.h>

class OI
{
private:

public:
	Joystick joystick;
	OI();
	inline float GetXplusY(){
		float val;
		val = FractionOmitted(joystick.GetY() + joystick.GetX());
		if(val > 1.2) val = 1.2;
		if(val < -1.2) val = -1.2;
		return val;
	}
	inline float GetXminusY(){
		float val;
		val = FractionOmitted(joystick.GetY() - joystick.GetX());
		if(val > 1.2) val = 1.2;
		if(val < -1.2) val = -1.2;
		return val;
	}


	inline float GetStickX(){ return FractionOmitted(joystick.GetX()); }
	inline float GetStickY(){ return FractionOmitted(joystick.GetY()); }
	inline float GetStickTwist(){ return FractionOmitted(joystick.GetTwist()); }
	inline float GetStickThrottle(){ return FractionOmitted(joystick.GetThrottle()); }
	inline float GetStcikRightY(){ return RightStickOmitted(joystick.GetRawAxis(5)); }

	inline float RightStickOmitted(float origin){
		if(fabsf(origin) < 0.5){
			origin = 0;
		}
		return origin;
	}

	inline float FractionOmitted(float original){
		if(fabsf(original) < 0.01 ){
			original = 0;
		}
		return original;
	}
};

#endif

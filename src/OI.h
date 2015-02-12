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

	//Sticks
	inline float GetStickX(){ return FractionOmitted(joystick.GetX()); }
	inline float GetStickY(){ return FractionOmitted(joystick.GetY()); }
	inline float GetStickTwist(){ return FractionOmitted(joystick.GetTwist()); }
	inline float GetStickThrottle(){ return FractionOmitted(joystick.GetThrottle()); }
	inline float GetStcikRightY(){ return RightStickOmitted(joystick.GetRawAxis(5)); }
	//Button
	inline bool GetSitckLeftButton(){ return joystick.GetRawButton(5); }
	inline bool GetStickRightButton(){ return joystick.GetRawButton(6); }
	//Ureget button
	inline bool GetUregetButton(){ return joystick.GetRawButton(7) && joystick.GetRawButton(8); }

	//Omitted for RightStick(Elevator Subsystem)
	inline float RightStickOmitted(float origin){
		if(fabsf(origin) < 0.5){
			origin = 0;
		}
		return origin;
	}

	//Omitted for LeftStick(Drive Subsystem)
	inline float FractionOmitted(float original){
		if(fabsf(original) < 0.01 ){
			original = 0;
		}
		return original;
	}

};

#endif

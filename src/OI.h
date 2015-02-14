#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include <math.h>

class OI
{
private:
	//Omitted for Elevator Stick(Elevator Subsystem)
	inline float ElevatorStickOmitted(float origin){
		if(fabsf(origin) < 0.5){
			origin = 0;
		}
		return origin;
	}

	//Omitted for LeftStick(Drive Subsystem)
	inline float FractionOmitted(float original){
		if(fabsf(original) < 0.2 ){
			original = 0;
		}
		return original;
	}

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

	///Sticks
	inline float GetStickX(){ return FractionOmitted(joystick.GetX()); }
	inline float GetStickY(){ return FractionOmitted(joystick.GetY()); }

	inline float GetStickTwist(){
		switch(CONTRLLOER_MODE){
			case 1:
				return FractionOmitted(joystick.GetTwist());
			case 2:
				return ElevatorStickOmitted(joystick.GetTwist());
		}
	}

	inline float GetStickThrottle(){
		switch(CONTRLLOER_MODE){
			case 1:
				return FractionOmitted(joystick.GetThrottle());
			case 2:
				return ElevatorStickOmitted(joystick.GetThrottle());
		}
	}

	//for kawabata mode:moving of Drive turn
	inline float GetStickRightX(){ return FractionOmitted(joystick.GetRawAxis(RIGHT_X_STICK)); }
	//for normal mode:moving of Elevator
	inline float GetStickRightY(){ return ElevatorStickOmitted(joystick.GetRawAxis(RIGHT_Y_STICK)); }

	/// POV
	inline int GetStickPov(){ return joystick.GetPOV(); }
	/*  Button */
 	inline bool GetSitckLeftButton(){ return joystick.GetRawButton(L_BUTTON); }
	inline bool GetStickRightButton(){ return joystick.GetRawButton(R_BUTTON); }
	//Ureget button
	inline bool GetUregetButton(){ return joystick.GetRawButton(BACK_BUTTON) && joystick.GetRawButton(START_BUTTON); }

};

#endif

#include "OI.h"
#include "RobotMap.h"

#include "Commands/AdjustAngle.h"
#include "Commands/PivotCommand.h"

OI::OI() : joystick(JOYSTICK)
{

	stick4Button = new Joystick(JOYSTICK);

	AButton = new JoystickButton(stick4Button,A_BUTTON);
	BButton = new JoystickButton(stick4Button,B_BUTTON);
	XButton = new JoystickButton(stick4Button,X_BUTTON);
	// Process operator interface input here.
	AButton->WhileHeld(new AdjustAngle());
	/*
	BButton->WhenPressed(new PivotCommand(true,90));
	XButton->WhenPressed(new PivotCommand(false,90));
	*/
}

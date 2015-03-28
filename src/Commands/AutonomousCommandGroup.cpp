#include "AutonomousCommandGroup.h"
#include "MoveElevator.h"
#include "Move2Container.h"
#include "AdjustAngle.h"
#include "BringBurden.h"
#include "PivotCommand.h"
#include "pincerMovement.h"

#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	AddSequential(new pincerMovement(1.5 , SPEED));
	Wait(1.0);
	AddSequential(new pincerMovement(1.5 , -SPEED));
	Wait(1.0);
	/*
	 * MoveElevator(float time,bool up) = move elevator while #{time} time. If #{up} is true, elevator is up. If not, elevator is down *
	 * BringBurden(float time,float speed) = move front and back. if #{speed} is plus, move front, and if not, move back while #{time} time.
	 * PincerMovement(float time,float speed) = move right or left. if #{speed} is plus, move right, and if not move left while #{time} time.
	 * */
}

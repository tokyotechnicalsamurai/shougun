#include "AutonomousCommandGroup.h"
#include "MoveElevator.h"
#include "Move2Container.h"
#include "AdjustAngle.h"
#include "BringBurden.h"
#include "PivotCommand.h"

#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	//AddSequential(new PivotCommand(-90));

	AddSequential(new MoveElevator(3.0,true));
	AddSequential(new Move2Container());
	AddSequential(new AdjustAngle());
	//AddSequential(new BringBurden());

}

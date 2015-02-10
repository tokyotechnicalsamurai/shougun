#include "AutonomousCommandGroup.h"
#include "MoveElevator.h"
#include "Move2Container.h"
#include "BringBurden.h"

#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	AddSequential(new MoveElevator(2.0,true));
	AddSequential(new Move2Container());
	AddSequential(new BringBurden());
}

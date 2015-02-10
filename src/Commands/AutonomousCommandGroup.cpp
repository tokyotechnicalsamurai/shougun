#include "AutonomousCommandGroup.h"
#include "MoveElevator.h"

#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	AddSequential(new MoveElevator(2.0,true));
}

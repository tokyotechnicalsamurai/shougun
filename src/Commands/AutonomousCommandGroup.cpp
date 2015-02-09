#include "AutonomousCommandGroup.h"

#include "RaiseContainer.h"
#include "DownContainer.h"
#include "RaiseTrash.h"
#include "DownTrash.h"
#include "MoveContainer.h"
#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	AddSequential(new RaiseTrash());
	AddSequential(new DownTrash());
	AddSequential(new RaiseContainer());
	AddSequential(new MoveContainer());
	AddSequential(new DownContainer());
}

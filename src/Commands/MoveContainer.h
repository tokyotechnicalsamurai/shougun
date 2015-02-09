#ifndef MoveContainer_H
#define MoveContainer_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveContainer: public CommandBase
{
public:
	MoveContainer();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

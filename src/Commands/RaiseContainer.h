#ifndef RaiseContainer_H
#define RaiseContainer_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseContainer: public CommandBase
{
public:
	RaiseContainer();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

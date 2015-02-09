#ifndef DownContainer_H
#define DownContainer_H

#include "../CommandBase.h"
#include "WPILib.h"

class DownContainer: public CommandBase
{
public:
	DownContainer();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

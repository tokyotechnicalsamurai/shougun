#ifndef RaiseTrash_H
#define RaiseTrash_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseTrash: public CommandBase
{
public:
	RaiseTrash();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

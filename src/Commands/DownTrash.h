#ifndef DownTrash_H
#define DownTrash_H

#include "../CommandBase.h"
#include "WPILib.h"

class DownTrash: public CommandBase
{
public:
	DownTrash();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

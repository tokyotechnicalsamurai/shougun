#ifndef GyroCommand_H
#define GyroCommand_H

#include "../CommandBase.h"
#include "WPILib.h"
//This command is not completed yet.
class GyroCommand: public CommandBase
{

public:
	GyroCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

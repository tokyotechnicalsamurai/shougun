#ifndef Move2Container_H
#define Move2Container_H

#include "../CommandBase.h"
#include "WPILib.h"

class Move2Container: public CommandBase
{
public:
	Move2Container();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isCenter;
};

#endif

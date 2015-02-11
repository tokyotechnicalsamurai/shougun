#ifndef BringBurden_H
#define BringBurden_H

#include "../CommandBase.h"
#include "WPILib.h"

class BringBurden: public CommandBase
{
public:
	BringBurden();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

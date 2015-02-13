#ifndef BringBurden_H
#define BringBurden_H

#include "../CommandBase.h"
#include "WPILib.h"

class BringBurden: public CommandBase
{
private:
	float firstZValue,secondZValue;
	int ZChangeCount;
public:
	BringBurden();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

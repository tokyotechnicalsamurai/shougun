#ifndef BringBurden_H
#define BringBurden_H

#include "../CommandBase.h"
#include "WPILib.h"

class BringBurden: public CommandBase
{
private:
	float moveTime;
	bool front;
public:
	BringBurden(float time,bool isFront);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

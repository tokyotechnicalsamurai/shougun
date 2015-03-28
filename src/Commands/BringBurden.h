#ifndef BringBurden_H
#define BringBurden_H

#include "../CommandBase.h"
#include "WPILib.h"

class BringBurden: public CommandBase
{
private:
	float moveTime,moveSpeed;
public:
	BringBurden(float time,float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef MoveElevator_H
#define MoveElevator_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveElevator: public CommandBase
{
public:
	MoveElevator(float moveTime,bool upOrDown);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float time;
	bool up;

};

#endif

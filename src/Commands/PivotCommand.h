#ifndef PivotCommand_H
#define PivotCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class PivotCommand: public CommandBase
{
private:
	float povitAngle;
	float breaktime;
	bool isRightPovit,isFinishPovit;
	bool parallel_state;//true:parallel movement , false:turn setted degree
	bool dist_state;//true:look distance and stop , false:not look distance

public:
	PivotCommand(float , bool = false , bool = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

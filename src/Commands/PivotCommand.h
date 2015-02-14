#ifndef PivotCommand_H
#define PivotCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class PivotCommand: public CommandBase
{
private:
	bool isRightPovit,isFinishPovit;
	int povitAngle;
public:
	PivotCommand(bool isRight,int Angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

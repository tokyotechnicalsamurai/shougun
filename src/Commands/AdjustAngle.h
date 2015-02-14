#ifndef AdjustAngle_H
#define AdjustAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class AdjustAngle: public CommandBase
{
private:
	float rightDist,leftDist;
	bool isStraighten;

public:
	AdjustAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

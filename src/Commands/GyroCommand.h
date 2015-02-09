#ifndef GyroCommand_H
#define GyroCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class GyroCommand: public CommandBase
{
public:
	GyroCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float GetValue();
private:
	int base;
	int prespeed;
	float deg;
	float beforetime;
	Timer* clock;
};

#endif

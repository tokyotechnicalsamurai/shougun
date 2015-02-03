#ifndef DriveCommand_H
#define DriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCommand: public CommandBase
{
private:
	float rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed,pullSpeed,angleSpeed;

public:
	DriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

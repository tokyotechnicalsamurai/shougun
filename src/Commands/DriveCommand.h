#ifndef DriveCommand_H
#define DriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCommand: public CommandBase
{
private:
	float speed,direction,rightFrontSpeed,leftFrontSpeed,rightBackSpeed,leftBackSpeed;

public:
	DriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void NormalDriveCommand();
	void KawabataDriveCommand();
	void AbsAngleDriveCommand();
	void POVAngleDriveCommand(int angle);
};

#endif

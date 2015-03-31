#ifndef pincerMovement_H
#define pincerMovement_H

#include "../CommandBase.h"
#include "WPILib.h"

class pincerMovement: public CommandBase
{
private:
	float moveTime,moveSpeed;
public:
	pincerMovement(float time,float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

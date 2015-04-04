#ifndef ParallelMovement_H
#define ParallelMovement_H

#include "../CommandBase.h"
#include "WPILib.h"

class ParallelMovement: public CommandBase
{
private:
	short vector_state;
	float breaktime;
	float deg , base , prespeed , beforetime;
	Timer* clock;
public:
	ParallelMovement(float , short = GO);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

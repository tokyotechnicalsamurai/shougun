#ifndef PivotCommand_H
#define PivotCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class PivotCommand: public CommandBase
{
private:
	float povitAngle;
	bool isRightPovit,isFinishPovit;
	float deg , base , prespeed , beforetime;
	Timer* clock;
/* in constructer, if the second argument is true, the first argument becomes the time to move directly.
 * for example: PivotCommand(3.0 , true);  ===>  Robot go straight for three seconds by using gyro sensor.
 */
public:
	PivotCommand(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

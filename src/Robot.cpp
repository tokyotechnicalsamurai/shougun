/*Tokyo Technical Samurai */

#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
//Command and CommandGroup
#include "Commands/DriveCommand.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *driveCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		driveCommand = new DriveCommand();
		//Camera Capture send to Dashboard

		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
		driveCommand->Start();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);


#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
	Brain.Screen.print("Hey Ellison, good Luck!!");
	Ellisons_Controller.Screen.print("Hey Ellison, good Luck!!");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void LiftController() {
	//Lift Control
		if (Ellisons_Controller.ButtonL1.pressing())
		{
			LiftMotor.spin()vex::directionType::fwd, 100, vex::velocityUnits::pct);
		}
		if (Ellisons_Controller.ButtonL2.pressing())
		{
			LiftMotor.spin()vex::directionType::rev, 100, vex::velocityUnits::pct);
		}
		else
		{
			LiftMotor.stop(vex::brakeType::hold);
		}
}
void usercontrol(void) {
	while (1) {

		LeftMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
		RightMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);

		LiftController();

		vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
	}
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

	//Run the pre-autonomous function. 
	pre_auton();

	//Set up callbacks for autonomous and driver control periods.
	Competition.autonomous(autonomous);
	Competition.drivercontrol(usercontrol);

	//Prevent main from exiting with an infinite loop.                        
	while (1) {
		vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
	}

}
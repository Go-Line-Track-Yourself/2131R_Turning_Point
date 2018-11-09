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
	Brain.Screen.print("Hey Ellison, good Luck!!:)");
	Ellisons_Controller.Screen.print("Hey Ellison, good Luck!!:)");
	JawMotor.setStopping(vex::brakeType::coast);
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

void LiftController()
{
	//Control for the Lift

	if (Ellisons_Controller.ButtonL2.pressing())
	{
		LiftMotor1.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
		LiftMotor2.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
	}
	else if (Ellisons_Controller.ButtonL1.pressing())
	{
		LiftMotor1.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
		LiftMotor2.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
	}
	else
	{
		LiftMotor1.stop(vex::brakeType::hold);
		LiftMotor2.stop(vex::brakeType::hold);
	}
}

void JawIntake()
{
	//Control for the Jaw 

	if (Ellisons_Controller.ButtonR1.pressing() && JawIntakePressed == false) {
		JawIntakePressed = true;
		JawMotor.startRotateTo(JawIntakeInverse ? 60 : 160, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
		JawIntakeInverse = !JawIntakeInverse;
	}

	if (!Ellisons_Controller.ButtonR1.pressing() && JawIntakePressed == true)
	{
		JawIntakePressed = false;
	}

}
void ArmIntake()
{
	//Control for the Arm

	if (Ellisons_Controller.ButtonR2.pressing() && ArmIntakePressed == false)
	{
		ArmIntakePressed = true;
		ArmMotor.startRotateFor(ArmIntakeInverse ? -180 : 180, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
		ArmIntakeInverse = !ArmIntakeInverse;
	}

	if (!Ellisons_Controller.ButtonR2.pressing() && ArmIntakePressed == true)
	{
		ArmIntakePressed = false;
	}
}

void usercontrol(void) {
	while (1) {
		Brain.Screen.newLine();
		Brain.Screen.print(JawMotor.rotation(vex::rotationUnits::deg));
		LeftBackMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
		LeftFrontMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
		RightBackMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);
		RightFrontMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);
		LiftController();
		JawIntake();
		ArmIntake();

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
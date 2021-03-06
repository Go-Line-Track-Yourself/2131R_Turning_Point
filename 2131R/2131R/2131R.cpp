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
void pre_auton(void)
{
	Brain.Screen.print("Hey Ellison, good Luck!!:)");
	Ellisons_Controller.Screen.print("Hey Ellison, good Luck!!:)");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* int HoodCalTask(){
HoodCal();
return 1;
}*/
int Auto_Intaking() {
	AutoIntakeEnabled = true;
	while (true) {
		while (AutoIntakeEnabled) {
			Auto_Intake();
			vex::task::sleep(20);
		}
		vex::task::sleep(20);
	}
	return 1;
}

int Drive_Ramping() {
	DriveRampingEnabled = true;
	while (DriveRampingEnabled) {
		LDR.TaskRun();
		RDR.TaskRun();
		setDrivePower(LDR.Pct, RDR.Pct);
		vex::task::sleep(LDR.ChangeMsec);
	}
	return 1;
}
void drive(double Distance, int Pct = 75, int EndWait = 250, int Correction = 1) {
	//calculation for distance in inches
	double WheelCir = 4 * 3.1415926535;
	int Direction = sgn(Distance);
	double Rev = std::abs(Distance) / WheelCir;
	int LPowerSend = 0;
	int RPowerSend = 0;
	//Clearing encoders
	LeftFrontMotor.resetRotation();
	LeftBackMotor.resetRotation();
	RightBackMotor.resetRotation();
	RightFrontMotor.resetRotation();
	//checking if it is at the right distance
	while (std::abs(RightBackMotor.rotation(vex::rotationUnits::rev))<std::abs(Rev)) {
		double LMotorEncValue = LeftBackMotor.rotation(vex::rotationUnits::deg);
		double RMotorEncValue = RightBackMotor.rotation(vex::rotationUnits::deg);
		//auto straighten
		if (std::abs(LMotorEncValue)>std::abs(RMotorEncValue)) {
			LPowerSend = Pct - Correction;
			RPowerSend = Pct;
		}
		else if (std::abs(LMotorEncValue)<std::abs(RMotorEncValue)) {
			LPowerSend = Pct;
			RPowerSend = Pct - Correction;
		}
		else if (std::abs(LMotorEncValue) == std::abs(RMotorEncValue)) {
			LPowerSend = Pct;
			RPowerSend = Pct;
		}

		//correct direction
		LPowerSend = LPowerSend * Direction;
		RPowerSend = RPowerSend * Direction;
		//Sends to SetDRpower
		SetDRpower(LPowerSend, RPowerSend);
		vex::task::sleep(1);
	}
	SetDRpower(0, 0);
	vex::task::sleep(EndWait);
}
void TimeAutoDrive(int time, int power) {//DriveRecon
	LeftBackMotor.resetRotation();
	RightBackMotor.resetRotation();

	DI(power, power);
	vex::task::sleep(time);
	RightBackMotor.stop(vex::brakeType::coast);
	LeftBackMotor.stop(vex::brakeType::coast);
	RightFrontMotor.stop(vex::brakeType::coast);
	LeftFrontMotor.stop(vex::brakeType::coast);
	DI(0, 0);
	RightBackMotor.stop(vex::brakeType::brake);
	RightFrontMotor.stop(vex::brakeType::brake);
	LeftBackMotor.stop(vex::brakeType::brake);
	LeftFrontMotor.stop(vex::brakeType::brake);
}
void Turn(double deg, int LPowerSend = 25, int RPowerSend = 25, int EndWait = 500) {//Turn
	int Dir = sgn(deg);
	deg = abs(deg) / 12.56;
	LPowerSend = LPowerSend * Dir;
	RPowerSend = RPowerSend * Dir;
	RightBackMotor.resetRotation();
	LeftBackMotor.resetRotation();
	while (abs(RightBackMotor.rotation(vex::rotationUnits::rev))<abs(deg)) {
		DI(LPowerSend, -RPowerSend);
		vex::task::sleep(1);
	}
	DI(0, 0);
	RightBackMotor.stop(vex::brakeType::brake);
	LeftBackMotor.stop(vex::brakeType::brake);
	vex::task::sleep(EndWait);

	RightBackMotor.stop(vex::brakeType::coast);
	LeftBackMotor.stop(vex::brakeType::coast);
}

/*int IntakeAuton(){
IntakeAutonEnabled=true;
IntakeAutoEnabled=true;//for intakeauto void
while(IntakeAutonEnabled){
Variableupdt();
IntakeAuto();
setIndexPower(Indexpwr);
setIntakePower(Feedpwr);
vex::task::sleep(20);
}
return 1;*/

//Clean ups and starts---------------------
void AutoClean() {
	//  IntakeAutonEnabled=false;
}
void UserClean() {
	//  VariableupdtEnabled=false;
	//   ControllerScreenEnabled=false;
}
void UserStart() {

	//   vex::task VariableupdtTask(Variableupdt);
	//   vex::task printDis(ControllerScreen);


	//    IntakeAutoEnabled=true;
}
void AutoStart() {

	Ellisons_Controller.Screen.print("auto started");


	//  vex::task IntakeAutonTask(IntakeAuton);
}
void PotAuto()
{
	int Valueselector = Pot.value(vex::percentUnits::pct);
	if (Valueselector > 90) //Blue Front Auton
	{

		//FlyChargeUpWait();
		setFlyPower(600);
		drive(32);
		wait(300);
		drive(-32);
		TimeAutoDrive(800, -30);
		drive(2.5, 50);
		Turn(9);
		wait(200);
		drive(-0.09);
		wait(400);
		AutoIndexFiring = true;
		wait(400);
		drive(16.5);
		wait(400);
		AutoIndexFiring = true;
		wait(400);
		Turn(1.8);
		drive(20);
		TimeAutoDrive(220, -50);
		Turn(5.7);
		wait(200);
		drive(-15);
		wait(200);
		Turn(-9.4);
		wait(200);
		AutoIndexFiring = true;
		setFlyPower(0);
	}
	else if (Valueselector > 65) //Red Front Auton
	{
		//FlyChargeUpWait();
		setFlyPower(600);
		drive(32);
		wait(400);
		drive(-32);
		TimeAutoDrive(700, -30);
		drive(1.85, 50);
		Turn(-8.8);
		wait(200);
		drive(-0.1);
		wait(400);
		AutoIndexFiring = true;
		wait(400);
		drive(16.5);
		wait(400);
		AutoIndexFiring = true;
		wait(400);
		Turn(-1);
		drive(20);
		TimeAutoDrive(220, -50);
		Turn(-1);
		wait(200);
		drive(-20);
		wait(200);
		Turn(7);
		wait(200);
		AutoIndexFiring = true;
		setFlyPower(0);
	}
	else if (Valueselector > 40)//Skills
	{

		setFlyPower(600);
		wait(200);
		drive(32);
		wait(300);
		drive(-32);
		TimeAutoDrive(700, -30);
		drive(1.8, 50);
		Turn(-8.6);
		wait(200);
		drive(-0.25);
		wait(400);
		AutoIndexFiring = true;
		wait(400);
		drive(16.5);
		wait(400);
		AutoIndexFiring = true;
		wait(400);
		Turn(-0.8);
		drive(20);
		TimeAutoDrive(1050, -50);
		//Turn (-1);
		wait(200);
		drive(-45);
		wait(200);
		Turn(9);
		wait(200);
		TimeAutoDrive(-750, -50);
		wait(200);
		drive(66);
		wait(200);
		setFlyPower(0);
		/*wait (200);
		Turn (9);
		wait (200);
		drive (40);
		wait (200);
		drive (-7);
		wait(200);
		Turn (-9);
		wait (200);
		drive (-1);
		wait(200);
		AutoIndexFiring = true;
		wait (200);
		drive (12.5);
		wait (200);
		AutoIndexFiring = true;
		wait (200);
		drive (-23);
		wait (200);
		Turn (-11);
		wait (200);
		drive (5);
		wait (200);
		Turn (-9);
		wait (200);
		drive (25);
		wait (200);
		Turn (-9);
		wait (200);
		drive (25);
		wait (200);
		setFlyPower (0);*/

	}
	else if (Valueselector > 15) //Blue Back Auton
	{
		setFlyPower(600);
		drive(33);
		wait(200);
		drive(-2);
		wait(300);
		Turn(8.3);
		wait(400);
		drive(-0.9);
		wait(200);
		AutoIndexFiring = true;
		wait(200);
		Turn(1.5);
		wait(200);
		drive(-5);
		Turn(-1.9);
		wait(300);
		drive(56.5);
		wait(200);
		Turn(-4);
		wait(200);
		//AutoIndexFiring = true;
		//wait (200);
		setFlyPower(0);
	}
	else if (Valueselector > 0) //Red Back Auton
	{
		setFlyPower(600);
		drive(33);
		wait(200);
		drive(-2);
		wait(300);
		Turn(-7.3);
		wait(400);
		drive(-0.9);
		wait(200);
		AutoIndexFiring = true;
		wait(200);
		Turn(-1.5);
		wait(200);
		drive(-5);
		Turn(2);
		wait(300);
		drive(49);
		wait(200);
		Turn(3.899);
		wait(200);
		//AutoIndexFiring = true;
		//wait (200);
		setFlyPower(0);
	}
	/*else if (Valueselector = 0);//back auton
	{
	//FlyChargeUpWait();
	setFlyPower(600);
	drive(32);
	wait (300);
	drive(-32);
	TimeAutoDrive (800,-30);
	drive(2.5,50);
	Turn(9);
	wait (200);
	drive(25);
	wait(400);
	AutoIndexFiring = true;
	wait(400);
	drive(16.5);
	wait(400);
	AutoIndexFiring = true;
	wait (400);
	Turn (1.8);
	drive(20);
	TimeAutoDrive (220,-50);
	Turn (5.7);
	wait (200);
	drive (-15);
	wait (200);
	Turn (-9.4);
	wait (200);
	AutoIndexFiring = true;
	setFlyPower(0);
	}*/
}
void autonomous(void) {
	//vex::task calibration(HoodCalTask);
	vex::task autoFeedSensing(Auto_Intaking);
	vex::task Ramping(Drive_Ramping);
	PotAuto();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/
void Hood()
{
	if (Ellisons_Controller.ButtonL1.pressing() && ReversableHoodPressed == false)
	{
		ReversableHoodPressed = true;
		ReversableHood = !ReversableHood;
	}
	if (!Ellisons_Controller.ButtonX.pressing() && ReversableHoodPressed == true)
	{
		ReversableHoodPressed = false;
	}

	if (ReversableHood)
	{
		HoodMotor.rotateTo(-176, vex::rotationUnits::deg, 100, ::vex::velocityUnits::pct);
		HoodMotor.stop(vex::brakeType::brake);
	}
	else if (!ReversableHood)
	{
		HoodMotor.rotateTo(-40, vex::rotationUnits::deg, 100, ::vex::velocityUnits::pct);
		HoodMotor.stop(vex::brakeType::coast);
	}

	/*if (Ellisons_Controller.ButtonL2.pressing())
	{
	HoodMotor.rotateTo(-50, vex::rotationUnits::deg, 100, ::vex::velocityUnits::pct);
	}*/
}

void Feed()
{
	if (Ellisons_Controller.ButtonR1.pressing())
	{
		FeedMotor.spin(vex::directionType::fwd, 100, ::vex::velocityUnits::pct);
	}
	else if (Ellisons_Controller.ButtonR2.pressing())
	{
		FeedMotor.spin(vex::directionType::fwd, -100, ::vex::velocityUnits::pct);
	}
	else
	{
		FeedMotor.stop(vex::brakeType::coast);
	}
}

void Index()
{
	if (Ellisons_Controller.ButtonR2.pressing() && Ellisons_Controller.ButtonR1.pressing())
	{
		IndexMotor.spin(vex::directionType::fwd, 100, ::vex::velocityUnits::pct);
	}
	else
	{
		IndexMotor.stop(vex::brakeType::coast);
	}
}

void FlyWheel()
{
	if (Ellisons_Controller.ButtonX.pressing() && FlyWheelPressed == false)
	{
		FlyWheelPressed = true;
		FlyWheelInverse = !FlyWheelInverse;
	}
	if (!Ellisons_Controller.ButtonX.pressing() && FlyWheelPressed == true)
	{
		FlyWheelPressed = false;
	}

	if (FlyWheelInverse)         FlyWheelMotor.spin(vex::directionType::fwd, 100, ::vex::velocityUnits::pct);
	else if (!FlyWheelInverse)   FlyWheelMotor.stop(vex::brakeType::coast);
}


/*void Brake()
{
if (Ellisons_Controller.ButtonUp.pressing())
{
LeftBackMotor.stop(vex::brakeType::brake);
LeftFrontMotor.stop(vex::brakeType::brake);
RightBackMotor.stop(vex::brakeType::brake);
RightFrontMotor.stop(vex::brakeType::brake);
}
else if (!Ellisons_Controller.ButtonUp.pressing())
{
LeftBackMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(),vex::velocityUnits::pct);
LeftFrontMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
RightBackMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);
RightFrontMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);
}
}
else
{
LeftBackMotor.stop(vex::brakeType::coast);
LeftFrontMotor.stop(vex::brakeType::coast);
RightBackMotor.stop(vex::brakeType::coast);
RightFrontMotor.stop(vex::brakeType::coast);
}
}*/
void AutoFeedIndexControll() {
	if (Ellisons_Controller.ButtonA.pressing() && IntakeEnabledBtnPressed == false) {
		IntakeEnabledBtnPressed = true;
		IntakeEnabledInverted = !IntakeEnabledInverted;
	}
	if (!Ellisons_Controller.ButtonA.pressing() && IntakeEnabledBtnPressed == true) {
		IntakeEnabledBtnPressed = false;
	}

	if (IntakeEnabledInverted) { AutoIntakeEnabled = true; }
	if (!IntakeEnabledInverted) {
		AutoIntakeEnabled = false;
		Feed();
		Index();
		//FlyWheel();

	}
}
void usercontrol(void)
{
	HoodCalll();
	DriveRampingEnabled = false;
	AutoIntakeEnabled = false;
	vex::task autoFeedSensing(Auto_Intaking);

	while (1)
	{
		LeftBackMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
		LeftFrontMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
		RightBackMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);
		RightFrontMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);

		FlyWheel();
		AutoFeedIndexControll();
		Hood();

		//Brake();



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

	FlipperMotor.setStopping(vex::brakeType::coast);
	//Prevent main from exiting with an infinite loop.                        
	while (1) {
		vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
	}

}
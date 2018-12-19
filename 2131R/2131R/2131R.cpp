#include "robot-config.h"
#include <cmath>
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

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/


/*void RightDriveStop()
{
{
RightBackMotor.stop(vex::brakeType::coast);
RightFrontMotor.stop(vex::brakeType::coast);
}
}
void LeftDriveStop()
{
{
LeftBackMotor.stop(vex::brakeType::coast);
LeftFrontMotor.stop(vex::brakeType::coast);
}
}
void LeftDrive(int pct)
{
if(pct==0)
{
LeftDriveStop();
}
else{
LeftFrontMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
LeftBackMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
}
}
void RightDrive(int pct)
{
if(pct==0)
{
RightDriveStop();
}
else
{
RightFrontMotor.spin(vex::directionType::rev,pct,vex::velocityUnits::pct);
RightBackMotor.spin(vex::directionType::rev,pct,vex::velocityUnits::pct);
}
}

void UpFlipper(int pct)
{
if (pct==0)         FlipperMotor.stop(vex::brakeType::coast);
else                FlipperMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
}

void DownFlipper(int pct)
{
if (pct==0)         FlipperMotor.stop(vex::brakeType::coast);
else                FlipperMotor.spin(vex::directionType::rev,pct,vex::velocityUnits::pct);
}

void Drive(int same)
{
LeftDrive(same);
RightDrive(same);
}

int BrianScreenDebug(){
Brain.Screen.render(true,false);
while(true){
Brain.Screen.newLine();
// Brain.Screen.print((Gyro.value(vex::rotationUnits::deg)));
Brain.Screen.render();
vex::task::sleep(20);

}
}
void autonomous(void) {
Brain.Screen.print("Starting Auton");
FlyWheelMotor.spin(vex::directionType::fwd, 100,::vex::velocityUnits::pct);
FeedMotor.spin(vex::directionType::rev, 100,::vex::velocityUnits::pct);
Drive(5);
Drive(0);
UpFlipper(15);
DownFlipper(15);

Brain.Screen.print("Auton Works");
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

void drive(double Distance, int Pct = 100, int EndWait = 250, int Correction = 2) {
	//calculation for distance in inches
	double WheelCir = 4 * 3.14159265358979323846264338327950288419716939937510582097494459237816406286208998628034253421170679;
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
		setDrivePower(LPowerSend, RPowerSend);
		vex::task::sleep(1);
	}
	setDrivePower(0, 0);
	vex::task::sleep(EndWait);
}

void TimeAutoDrive(int time, int power) {//DriveRecon
	LeftBackMotor.resetRotation();
	RightBackMotor.resetRotation();

	RightBackMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
	LeftBackMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
	vex::task::sleep(time);
	RightBackMotor.stop(vex::brakeType::coast);
	LeftBackMotor.stop(vex::brakeType::coast);

	setDrivePower(0, 0);
	RightBackMotor.stop(vex::brakeType::brake);
	RightFrontMotor.stop(vex::brakeType::brake);
	LeftBackMotor.stop(vex::brakeType::brake);
	LeftFrontMotor.stop(vex::brakeType::brake);
	//why twice? 
	vex::task::sleep(time);
	setDrivePower(0, 0);
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
		setDrivePower(LPowerSend, -RPowerSend);
		vex::task::sleep(1);
	}
	setDrivePower(0, 0);
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


/*void Flipper(){
FlipperMotor.startRotateFor(FlipperMotorInverted ? -350 : 350,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
FlipperMotorInverted=!FlipperMotorInverted;*/



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

void FirstAton() {
	//FlyChargeUpWait();
	setFlyPower(600);
	wait(5000);
	setIndexPower(100);
	//AutoIndexFiring = true;
	wait(500);
	setDrivePower(100, 100);
	wait(1500);
	setDrivePower(0, 0);
	setFlyPower(0);
	setIndexPower(0);
}
void autonomous(void) {
	//vex::task autoFeedSensing(Auto_Intaking);
	FirstAton();
	Brain.Screen.print("Auton Works");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

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
	if (Ellisons_Controller.ButtonR2.pressing() && Ellisons_Controller.ButtonR1.pressing()) IndexMotor.spin(vex::directionType::fwd, 100, ::vex::velocityUnits::pct);
	else                                        IndexMotor.stop(vex::brakeType::coast);
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

int FlipperUp = -370;
int FlipperDown = -5;
int FlipperRequested = FlipperDown;

void Flipper()
{
	if (Ellisons_Controller.ButtonL1.pressing() && FlipperBtnPressed == false)
	{
		FlipperBtnPressed = true;
		if (FlipperRequested == FlipperDown)     FlipperRequested = FlipperUp;
		else if (FlipperRequested == FlipperUp)  FlipperRequested = FlipperDown;
	}
	if (!Ellisons_Controller.ButtonL1.pressing() && FlipperBtnPressed == true)
	{
		FlipperBtnPressed = false;
	}
	FlipperMotor.startRotateTo(FlipperRequested, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);

}
void FlipperManualandToggle()
{
	if (Ellisons_Controller.ButtonDown.pressing() && FlipperModeBtnPressed == false) {
		FlipperModeBtnPressed = true;
		FlipperMode = !FlipperMode;
	}
	if (!Ellisons_Controller.ButtonDown.pressing() && FlipperModeBtnPressed == true) {
		FlipperModeBtnPressed = false;
	}

	if (FlipperMode) {//manual mode
		FlipperMotor.setStopping(vex::brakeType::brake);

		if (Ellisons_Controller.ButtonL1.pressing())
		{
			FlipperMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
		}
		else if (Ellisons_Controller.ButtonL2.pressing())
		{
			FlipperMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
		}
		else
		{
			FlipperMotor.stop(vex::brakeType::brake);
		}
	}
	if (!FlipperMode) {//toggle mode
					   //FlipperMotor.startRotateTo(FlipperDown,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
		if (Ellisons_Controller.ButtonL1.pressing() && FlipperBtnPressed == false)
		{
			FlipperBtnPressed = true;
			if (FlipperRequested == FlipperDown)     FlipperRequested = FlipperUp;
			else if (FlipperRequested == FlipperUp)  FlipperRequested = FlipperDown;
		}
		if (!Ellisons_Controller.ButtonL1.pressing() && FlipperBtnPressed == true)
		{
			FlipperBtnPressed = false;
		}
		FlipperMotor.startRotateTo(FlipperRequested, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
	}
}
void Descorer()
{
	FlipperMotor.setStopping(vex::brakeType::brake);

	if (Ellisons_Controller.ButtonL1.pressing())
	{
		FlipperMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
	}
	else if (Ellisons_Controller.ButtonL2.pressing())    FlipperMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
	else             FlipperMotor.stop(vex::brakeType::brake);
}

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
		FlyWheel();

	}
}
void usercontrol(void)
{
	AutoIntakeEnabled = false;
	vex::task autoFeedSensing(Auto_Intaking);
	while (1)
	{
		LeftBackMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
		LeftFrontMotor.spin(vex::directionType::fwd, Ellisons_Controller.Axis3.value(), vex::velocityUnits::pct);
		RightBackMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);
		RightFrontMotor.spin(vex::directionType::rev, Ellisons_Controller.Axis2.value(), vex::velocityUnits::pct);

		AutoFeedIndexControll();
		FlipperManualandToggle();


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
#include <cmath>
vex::brain Brain;
vex::motor HoodMotor = vex::motor(vex::PORT8);
vex::motor LeftFrontMotor = vex::motor(vex::PORT1);
vex::motor RightFrontMotor = vex::motor(vex::PORT2);
vex::motor LeftBackMotor = vex::motor(vex::PORT4);
vex::motor RightBackMotor = vex::motor(vex::PORT3);
vex::controller Ellisons_Controller = vex::controller();
vex::motor FeedMotor = vex::motor(vex::PORT9, vex::gearSetting::ratio18_1, 1);
vex::motor IndexMotor = vex::motor(vex::PORT10, vex::gearSetting::ratio18_1, 0);
vex::motor FlyWheelMotor = vex::motor(vex::PORT6, vex::gearSetting::ratio6_1, 0);
vex::motor FlipperMotor = vex::motor(vex::PORT16, vex::gearSetting::ratio36_1, 0);
vex::analog_in BallSenseBottom = vex::analog_in(Brain.ThreeWirePort.B);
vex::analog_in BallSenseTop = vex::analog_in(Brain.ThreeWirePort.C);
vex::analog_in Pot = vex::analog_in(Brain.ThreeWirePort.H);


//calibration
bool HoodCal = true;
bool HoodCaled = false;
bool HoodSpinToControlRunEnabled = false;
bool HoodSpinToControlEnabled = false;

//hood toggle
bool ReversableHood = false;
bool ReversableHoodPressed = false;

//flywheel toggle
bool FlyWheelPressed = false;
bool FlyWheelInverse = false;

/*bool FlipperBtnPressed = false;
bool FlipperInverted = false;

bool FlipperMode = false;
bool FlipperModeBtnPressed = false;

bool DescorerBtnPressed = false;
bool DescorerInverted = false;*/

bool IntakeEnabledBtnPressed;
bool IntakeEnabledInverted;

bool DriveRampingEnabled;









//---------------------Auto Intake-----------------------//
bool AutoIntakeEnabled = false;
int	BottomLightValue;
int TopLightValue;
//int MiddleLightValue;
int BottomBallInMax = 68;
//int MiddleBallInMax = 70;
int TopBallInMax = 62;

bool BallInBottom;
bool BallInTop;
bool AutoIndexFiring;


void setIntakePower(int power) {
	FeedMotor.spin(vex::directionType::fwd, power, ::vex::velocityUnits::pct);
}
void Auto_Intake() {
	BottomLightValue = BallSenseBottom.value(vex::percentUnits::pct);
	TopLightValue = BallSenseTop.value(vex::percentUnits::pct);
	//MiddleLightValue = BallSenseMid.value(vex::percentUnits::pct);

	if (BottomLightValue < BottomBallInMax/* || MiddleLightValue < MiddleBallInMax*/) BallInBottom = true;
	else BallInBottom = false;
	if (TopLightValue < TopBallInMax) BallInTop = true;
	else BallInTop = false;

	if (Ellisons_Controller.ButtonR2.pressing() || AutoIndexFiring == true) {
		setIndexPower(100);
		//for aton firing
		if (AutoIndexFiring) {
			//wait till gone
			vex::task::sleep(300);
			AutoIndexFiring = false;
			setIndexPower(0);
		}
	}

	else {
		if (BallInBottom && BallInTop) {
			setIntakePower(0);
			setIndexPower(0);
			FeedMotor.stop(vex::brakeType::brake);
		}
		if (BallInBottom && !BallInTop) {
			setIntakePower(100);
			setIndexPower(40);
		}
		if (BallInTop && !BallInBottom) {
			setIntakePower(90);
			setIndexPower(0);
		}
		if (!BallInBottom && !BallInTop) {
			setIntakePower(100);
			setIndexPower(40);
		}
	}
}
//----------auton--------------
double abs(double Var) {
	if (Var < 0)  Var = Var * (-1);
	return Var;
}
double sgn(double Var) {
	if (Var > 0)   Var = 1;
	else        Var = -1;
	return Var;
}

void LeftDriveStop() {
	LeftBackMotor.stop();
	LeftFrontMotor.stop();
}
void RightDriveStop() {
	RightBackMotor.stop();
	RightFrontMotor.stop();
}
void setLeftDrivePower(int pct) {
	if (pct == 0)   LeftDriveStop();
	else {
		LeftBackMotor.spin(vex::directionType::fwd, pct, vex::velocityUnits::pct);
		LeftFrontMotor.spin(vex::directionType::fwd, pct, vex::velocityUnits::pct);
	}
}
void setRightDrivePower(int pct) {
	if (pct == 0)  RightDriveStop();
	else {
		RightBackMotor.spin(vex::directionType::fwd, -pct, vex::velocityUnits::pct);
		RightFrontMotor.spin(vex::directionType::fwd, -pct, vex::velocityUnits::pct);
	}
}
void setDrivePower(int left, int right) {
	setLeftDrivePower(left);
	setRightDrivePower(right);
}

void wait(int time) {
	vex::task::sleep(time);
}

void setFlyPower(int rpm) {

	FlyWheelMotor.spin(vex::directionType::fwd, rpm, vex::velocityUnits::rpm);
}
void FlyChargeUpWait() {
	setFlyPower(600);
	while (FlyWheelMotor.velocity(vex::velocityUnits::pct)<100) {}
}
void SetIndexPower(int power) {
	if (power == 0)  IndexMotor.stop(vex::brakeType::brake);
	else {
		IndexMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
	}
}
void setFeedPower(int power) {
	if (power == 0)  FeedMotor.stop(vex::brakeType::brake);
	else {
		FeedMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
	}
}
class Ramping {
public:
	int ChangePct = 1;      //the amout of Pct change per loop
	int ChangeMsec = 1;     //the amount of time inbetween loops

	int RequestedPct = 0;   //used to request Pct value change
	int Pct = 0;            //Pct output
	int MinUpPct = 0;         //Used as moveing up StillSpeed
	int MinDownPct = 0;       //Used as moving down StillSpeed
	int MaxPct = 100;         //the max pct value

	Ramping();

	Ramping(int CP, int CM, int MaxP = 100, int MinDP = 0, int MinUP = 0) {
		//ChangePct,ChangeMsec,MaxPct
		ChangePct = CP;
		ChangeMsec = CM;
		MaxPct = MaxP;
		MinUpPct = MinUP;
		MinDownPct = MinDP;
	}

	void TaskRun() {
		if (RequestedPct>Pct) {
			Pct = Pct + ChangePct;
		}
		else if (RequestedPct<Pct) {
			Pct = Pct - ChangePct;
		}
		//limit Pct
		if (Pct>MaxPct)	Pct = MaxPct;
		if (Pct<-MaxPct)	Pct = -MaxPct;
		if (Pct>0 && Pct<MinUpPct) Pct = MinUpPct;
		if (Pct<0 && Pct>MinDownPct)    Pct = MinDownPct;
	}
};
Ramping LDR(1, 3);
Ramping RDR(1, 3);

void SetDRpower(int Lpower, int Rpower) { //DR
	LDR.RequestedPct = Lpower;
	RDR.RequestedPct = Rpower;
}
void DI(int Lpower, int Rpower) {
	LDR.RequestedPct = Lpower;
	RDR.RequestedPct = Rpower;
	LDR.Pct = Lpower;
	RDR.Pct = Rpower;
	setDrivePower(LDR.Pct, RDR.Pct);
}

void HoodCalll() {
	HoodCal = false;
	int Rpm = 22;
	int TimeOut = 1000;
	int UpdateMsec = 50;
	int CalTimer = 0;
	HoodMotor.spin(vex::directionType::fwd, Rpm, vex::velocityUnits::rpm);
	double MinChange = Rpm / 120000 * UpdateMsec;///(1/4)*(Rpm/60/1000); MinChange = 1/4 of requested rpm but in msec`s
	vex::task::sleep(250);//wait for acel
	double LastRotation = HoodMotor.rotation(vex::rotationUnits::rev) / 1000;//make sure it goes first loop
	while (std::abs(HoodMotor.rotation(vex::rotationUnits::rev) - LastRotation)>MinChange && CalTimer<TimeOut) {//if displacement is more then 1/4 of what it is set to be and it is not out of time
		LastRotation = HoodMotor.rotation(vex::rotationUnits::rev);
		CalTimer = CalTimer + UpdateMsec;
		vex::task::sleep(UpdateMsec);
	}
	HoodMotor.resetRotation();
	HoodMotor.stop();
	Brain.Screen.print("It worked yay");
	HoodCaled = true;
	HoodMotor.rotateTo(-50, vex::rotationUnits::deg, 100, ::vex::velocityUnits::pct);

}

/* int HoodCalTask()
{
HoodCalll();
return 1;
}*/



void mechamdrive(int V1 = 0, int V2 = 0, int V3 = 0, int V4 = 0)
{
	LeftBackMotor.spin(vex::directionType::fwd, V2, vex::velocityUnits::pct);
	LeftFrontMotor.spin(vex::directionType::fwd, V1, vex::velocityUnits::pct);
	RightBackMotor.spin(vex::directionType::rev, V4, vex::velocityUnits::pct);
	RightFrontMotor.spin(vex::directionType::rev, V3, vex::velocityUnits::pct);
}

void tankdrive(int j1, int j2, int j3, int j4)
{
	int Left = j1;
	int Right = j2;
	int Side = (j3 + j4) / 2; //average

	if (std::abs(j3)>std::abs(j4))
	{
		Side = j3;
	}

	else
	{
		Side = j4;
	}

	mechamdrive(
		Left + Side,
		Left - Side,
		Right - Side,
		Right + Side);

}


tankdrive(Ellisons_Controller.Axis3.value(),
	Ellisons_Controller.Axis2.value(),
	Ellisons_Controller.Axis4.value(),
	Ellisons_Controller.Axis1.value());
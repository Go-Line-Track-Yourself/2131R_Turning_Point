vex::brain Brain;
vex::motor LeftFrontMotor = vex::motor(vex::PORT17);
vex::motor RightFrontMotor = vex::motor(vex::PORT18);
vex::motor LeftBackMotor = vex::motor(vex::PORT20);
vex::motor RightBackMotor = vex::motor(vex::PORT19);
vex::controller Ellisons_Controller = vex::controller();
vex::motor FeedMotor = vex::motor(vex::PORT9, vex::gearSetting::ratio18_1, 1);
vex::motor IndexMotor = vex::motor(vex::PORT10, vex::gearSetting::ratio18_1, 0);
vex::motor FlyWheelMotor = vex::motor(vex::PORT6, vex::gearSetting::ratio6_1, 0);
vex::motor FlipperMotor = vex::motor(vex::PORT16, vex::gearSetting::ratio36_1, 0);
vex::analog_in BallSenseBottom = vex::analog_in(Brain.ThreeWirePort.B);
vex::analog_in BallSenseTop = vex::analog_in(Brain.ThreeWirePort.C);

bool FlyWheelPressed = false;
bool FlyWheelInverse = false;

bool FlipperBtnPressed = false;
bool FlipperInverted = false;

bool FlipperMode = false;
bool FlipperModeBtnPressed = false;

bool DescorerBtnPressed = false;
bool DescorerInverted = false;

bool IntakeEnabledBtnPressed;
bool IntakeEnabledInverted;
//---------------------Auto Intake-----------------------//
bool AutoIntakeEnabled = false;
int	BottomLightValue;
int TopLightValue;
int MiddleLightValue;
int BottomBallInMax = 70;
//int MiddleBallInMax = 70;
int TopBallInMax = 60;

bool BallInBottom;
bool BallInTop;
bool AutoIndexFiring;
void setIndexPower(int power) {
	IndexMotor.spin(vex::directionType::fwd, power, ::vex::velocityUnits::pct);
}
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
			vex::task::sleep(500);
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
			setIndexPower(50);
		}
		if (BallInTop && !BallInBottom) {
			setIntakePower(100);
			setIndexPower(0);
		}
		if (!BallInBottom && !BallInTop) {
			setIntakePower(100);
			setIndexPower(50);
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

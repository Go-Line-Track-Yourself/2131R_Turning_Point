vex::brain Brain;
vex::motor LeftFrontMotor = vex::motor(vex::PORT17);
vex::motor RightFrontMotor = vex::motor(vex::PORT18);
vex::motor LeftBackMotor = vex::motor(vex::PORT20);
vex::motor RightBackMotor = vex::motor(vex::PORT19);
vex::controller Ellisons_Controller = vex::controller();
vex::motor FeedMotor = vex::motor(vex::PORT9, vex::gearSetting::ratio18_1, 1);
vex::motor IndexMotor = vex::motor(vex::PORT10, vex::gearSetting::ratio18_1, 0);
vex::motor FlyWheelMotor = vex::motor(vex::PORT6);
vex::motor FlipperMotor = vex::motor(vex::PORT16, vex::gearSetting::ratio36_1, 0);

bool FlyWheelPressed = false;
bool FlyWheelInverse = false;

bool FlipperBtnPressed = false;
bool FlipperInverted = false;

bool DescorerBtnPressed = false;
bool DescorerInverted = false;
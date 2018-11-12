vex::brain Brain;
vex::motor LeftFrontMotor = vex::motor(vex::PORT17);
vex::motor RightFrontMotor = vex::motor(vex::PORT14);
vex::motor LeftBackMotor = vex::motor(vex::PORT10);
vex::motor RightBackMotor = vex::motor(vex::PORT1);
vex::motor JawMotor = vex::motor(vex::PORT16, vex::gearSetting::ratio18_1, true);
vex::motor ArmMotor = vex::motor(vex::PORT12);
vex::controller Ellisons_Controller = vex::controller();
vex::motor LiftMotor1 = vex::motor(vex::PORT20);
vex::motor LiftMotor2 = vex::motor(vex::PORT11);

bool JawIntakePressed;
bool JawIntakeInverse = true;

bool ArmIntakePressed;
bool ArmIntakeInverse = true;

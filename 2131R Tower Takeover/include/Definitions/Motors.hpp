#pragma once
#include "main.h"

//controller
extern okapi::Controller ellisonsController;

//drive motors
namespace drive{
  extern okapi::Motor RightBackMotor;
  extern okapi::Motor RightFrontMotor;
  extern okapi::Motor LeftBackMotor;
  extern okapi::Motor LeftFrontMotor;
  extern okapi::MotorGroup LeftMotors;
  extern okapi::MotorGroup RightMotors;
  extern okapi::MotorGroup Motors;
}

//lift motors
namespace lift{
  extern okapi::Motor Motor;
}

//ramp motor
namespace ramp{
  extern okapi::Motor Motor;
}

//intake motor
namespace intake{
  extern okapi::Motor LeftMotor;
  extern okapi::Motor RightMotor;
  extern okapi::MotorGroup Motors;
  extern pros::ADIAnalogIn Sensor;
}

extern okapi::MotorGroup backOutMotors;

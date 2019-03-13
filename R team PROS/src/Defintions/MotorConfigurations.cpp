#include "Definitions/MotorDefinitions.hpp"

//drive motors
namespace Drive{
  okapi::Motor RightBackMotor(17,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFrontMotor(19,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftBackMotor(14,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftFrontMotor(11,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
}

 //feed motors
 namespace Feed{
   okapi::Motor TopMotor(20,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
   okapi::Motor BottomMotor(15,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

}

 //catapult motor
 namespace Puncher{
   okapi::Motor Motor(12,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
}

//lift motor
namespace Lift{
  okapi::Motor Motor(18,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
}

//feed sensors
 namespace Feed{
   pros::ADIAnalogIn Bottom(1);
   pros::ADIAnalogIn Middle(1);
   pros::ADIAnalogIn Top(1);
}

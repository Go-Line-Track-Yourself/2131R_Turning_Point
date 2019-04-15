#include "Definitions/Motors.hpp"

//drive motors
namespace Drive{
  okapi::Motor RightBackMotor(11,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFrontMotor(15,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftBackMotor(16,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftFrontMotor(14,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
}

 //feed motors
 namespace Feed{
   okapi::Motor Motor(12,false,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
}

 //catapult motor
 namespace Catapult{
   okapi::Motor Motor(19,false,okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
   okapi::Motor Motor2(18,true,okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
}

//lift motor
namespace Lift{
  okapi::Motor Motor(10,false,okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
}

//feed sensors
 namespace Feed{
   pros::ADIAnalogIn Bottom(2);
   pros::ADIAnalogIn Middle(3);
   pros::ADIAnalogIn Top(4);
}

//catapult sensors
namespace Arm{
  pros::ADIAnalogIn Bottom(2);
  pros::ADIAnalogIn Middle(3);
  pros::ADIAnalogIn Top(4);
}

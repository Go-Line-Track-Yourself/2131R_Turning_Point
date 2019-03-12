#include "Definitions/Motors.hpp"

//drive motors
namespace Drive{
  okapi::Motor RightBackMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFrontMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftBackMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftFrontMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
}

 //feed motors
 namespace Feed{
   okapi::Motor TopMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
   okapi::Motor BottomMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
}

 //catapult motor
 namespace Catapult{
   okapi::Motor Motor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
}

//lift motor
namespace Lift{
  okapi::Motor Motor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
}

//feed sensors
 namespace Ball{
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

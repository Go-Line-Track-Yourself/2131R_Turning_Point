#ifndef MOTORS_HPP
#define MOTORS_HPP

#include "okapi/api.hpp"

//controller
extern okapi::Controller Ellisons_Controller;

//drive motors
namespace Drive{
  extern okapi::Motor RightBackMotor;
  extern okapi::Motor RightFrontMotor;
  extern okapi::Motor LeftBackMotor;
  extern okapi::Motor LeftFrontMotor;
}

//feed motors
namespace Feed{
  extern okapi::Motor Motor;
}

//catapult motor
namespace Catapult{
  extern okapi::Motor Motor;
}
//lift motor
namespace Lift{
  extern okapi::Motor Motor;
}

//feed sensors
namespace Feed{
  extern pros::ADIAnalogIn Bottom;
  extern pros::ADIAnalogIn Middle;
  extern pros::ADIAnalogIn Top;
}

//catapult sensors
namespace Arm{
  extern pros::ADIAnalogIn Bottom;
  extern pros::ADIAnalogIn Middle;
  extern pros::ADIAnalogIn Top;
}



#endif /* end of include guard: MOTORS_HPP */

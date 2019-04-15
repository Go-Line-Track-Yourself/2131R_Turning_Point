#include "robot/config/motor_config.hpp"
#include "custom/ramping.hpp"
// #include "custom/mecanum_drive.hpp"
namespace drive{
  okapi::Motor front_left_motor(11,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor front_right_motor(1,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_left_motor(20,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_right_motor(10,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  // MecanumDrive Chassis(
  //   front_left_motor,
  //   back_left_motor,
  //   front_right_motor,
  //   back_right_motor,
  //   4*M_PI,11.5,8);
  Ramping LeftN (1,4,200,-200);
  Ramping RightN(1,4,200,-200);
  Ramping LeftS (1,4,200,-200);
  Ramping RightS(1,4,200,-200);
}
namespace puncher{
  okapi::Motor motor(13,true,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
}
namespace lift{
  okapi::Motor motor(9,true,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
}
namespace flipper{
  okapi::Motor motor(19,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
}
namespace intake{
  okapi::Motor motor(2,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  namespace automatic{
    namespace balls{
      pros::ADIAnalogIn only(8);
    }
  }
}

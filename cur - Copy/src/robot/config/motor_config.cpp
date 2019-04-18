#include "robot/config/motor_config.hpp"
#include "custom/ramping.hpp"

namespace drive{
  okapi::Motor front_left_motor(11,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor front_right_motor(15,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_left_motor(18,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_right_motor(20,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);

  Ramping LeftN (1,4,200,-200);
  Ramping RightN(1,4,200,-200);
  Ramping LeftS (1,4,200,-200);
  Ramping RightS(1,4,200,-200);
}
namespace puncher{
  okapi::Motor motor1(19,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor motor2(16,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::MotorGroup motor({motor1,motor2});
}
namespace lift{
  okapi::Motor motor(10,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
}
namespace intake{
  okapi::Motor motor(14,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  namespace automatic{
    namespace balls{
      pros::ADIAnalogIn top(1);
      pros::ADIAnalogIn middle(3);
      pros::ADIAnalogIn bottom(4);
    }
  }
}

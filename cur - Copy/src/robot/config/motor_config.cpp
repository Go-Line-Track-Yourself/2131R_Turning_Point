#include "robot/config/motor_config.hpp"
#include "custom/ramping.hpp"

namespace drive{
  okapi::Motor front_left_motor(19,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor front_right_motor(20,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_left_motor(10,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_right_motor(9,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);

  Ramping LeftN (1,4,200,-200);
  Ramping RightN(1,4,200,-200);
  Ramping LeftS (1,4,200,-200);
  Ramping RightS(1,4,200,-200);
}
namespace puncher{
  okapi::Motor motor(7,true,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
  pros::ADIAnalogIn charge(5);
}
namespace lift{
  okapi::Motor motor(15,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
}
namespace intake{
  okapi::Motor motor(14,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  namespace automatic{
    namespace balls{
      pros::ADIAnalogIn top(3);
      pros::ADIAnalogIn feed(4);
      pros::ADIAnalogIn middle(5);
    }
  }
}

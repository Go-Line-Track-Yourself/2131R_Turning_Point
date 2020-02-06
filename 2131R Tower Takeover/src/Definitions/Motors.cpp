#include "Definitions/Motors.hpp"

okapi::Controller ellisonsController(okapi::ControllerId::master);

//drive motors
namespace drive{
  okapi::Motor RightBackMotor(14,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFrontMotor(12,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftBackMotor(20,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftFrontMotor(19,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::MotorGroup LeftMotors({LeftBackMotor, LeftFrontMotor});
  okapi::MotorGroup RightMotors({RightBackMotor, RightFrontMotor});
  okapi::MotorGroup Motors({RightBackMotor, RightFrontMotor, LeftBackMotor, LeftFrontMotor});
}

//lift motor
namespace lift{
  okapi::Motor Motor(9,false,okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
  pros::ADIAnalogIn Sensor(1);
}

//ramp motor
namespace ramp{
  okapi::Motor Motor(11,false,okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
}

//intake Motors
namespace intake{
  okapi::Motor LeftMotor(10,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightMotor(13,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::MotorGroup Motors({LeftMotor, RightMotor});
  pros::ADIAnalogIn Sensor(2);
}

okapi::MotorGroup backOutMotors({drive::RightBackMotor, drive::RightFrontMotor, drive::LeftBackMotor, drive::LeftFrontMotor, intake::RightMotor, intake::LeftMotor});

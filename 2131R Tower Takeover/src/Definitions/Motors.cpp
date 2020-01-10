#include "Definitions/Motors.hpp"

okapi::Controller ellisonsController(okapi::ControllerId::master);

//drive motors
namespace drive{
  okapi::Motor RightBackMotor(7,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFrontMotor(1,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftBackMotor(18,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftFrontMotor(9,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::MotorGroup LeftMotors({LeftBackMotor, LeftFrontMotor});
  okapi::MotorGroup RightMotors({RightBackMotor, RightFrontMotor});
  okapi::MotorGroup Motors({RightBackMotor, RightFrontMotor, LeftBackMotor, LeftFrontMotor});
}

//lift motor
namespace lift{
  okapi::Motor Motor(10,false,okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
}

//ramp motor
namespace ramp{
  okapi::Motor Motor(6,false,okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
}

//intake Motors
namespace intake{
  okapi::Motor LeftMotor(16,false,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightMotor(5,true,okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
  okapi::MotorGroup Motors({LeftMotor, RightMotor});
  pros::ADIAnalogIn Sensor(8);
}

okapi::MotorGroup backOutMotors({drive::RightBackMotor, drive::RightFrontMotor, drive::LeftBackMotor, drive::LeftFrontMotor, intake::RightMotor, intake::LeftMotor});

#include "Definitions/MotorDefinitions.hpp"

//drive motors
 okapi::Motor LeftBackMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
 okapi::Motor LeftFrontMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
 okapi::Motor RightBackMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
 okapi::Motor RightFrontMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

 //feed motors
 okapi::Motor FeedMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
 okapi::Motor BottomFeedMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

 //firing motors
 okapi::Motor PuncherMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
 okapi::Motor RotaterMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

//lift motor
okapi::Motor LiftMotor(1,true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

 //sensors
 pros::ADIAnalogIn BallSenseBottom(2);
 pros::ADIAnalogIn BallSenseMiddle(3);
 pros::ADIAnalogIn BallSenseTop(4);

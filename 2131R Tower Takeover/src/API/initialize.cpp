#include "main.h"
#include "Autons/onScreen.hpp"

int currentAuton = 0;
std::string AUTONOMOUS [7]{"Debugging","RedFront","RedBack","BlueFront","BlueBack","Skills", "OnePoint"};

void on_left_button(){
	currentAuton--;
	if(currentAuton < 0) currentAuton = 5;
	pros::lcd::set_text(2, AUTONOMOUS[currentAuton]);
}

void on_right_button(){
	currentAuton++;
	if(currentAuton > 7) currentAuton = 0;
	pros::lcd::set_text(2, AUTONOMOUS[currentAuton]);
}

int returnAuton() {
	return currentAuton;
}

void initialize() {
  //screen initialization
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Good Luck 2131R :)");
  pros::lcd::set_text(2, "Autonomous: " + (AUTONOMOUS[currentAuton]));
  pros::lcd::register_btn2_cb(on_right_button);
  pros::lcd::register_btn0_cb(on_left_button);

  //motor initialization
  drive::RightMotors.tarePosition();
  drive::LeftMotors.tarePosition();
	drive::LeftMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
	drive::RightMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  ramp::Motor.tarePosition();
  ramp::Motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  lift::Motor.tarePosition();
	lift::Motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

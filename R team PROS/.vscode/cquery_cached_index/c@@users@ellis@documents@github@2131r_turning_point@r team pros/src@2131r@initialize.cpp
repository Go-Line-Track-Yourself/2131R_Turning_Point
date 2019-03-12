#include "main.h"
//On Screen Potentiometer
enum class OnScreen {POSITION};

int POSITION =0;

std::string POSITIONS [6]{"Debugging","RedFront","RedBack","BlueFront","BlueBack","Skills"};


void on_left_button(){
	POSITION--;
	if(POSITION<0) POSITION=5;
	pros::lcd::set_text(2, POSITIONS[POSITION]);
}

void on_right_button(){
	POSITION++;
	if(POSITION>5) POSITION=0;
	pros::lcd::set_text(2, POSITIONS[POSITION]);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {


	pros::lcd::initialize();
	pros::lcd::set_text(1, "Good Luck 2131R :)");
	pros::lcd::set_text(2, POSITIONS[POSITION]);


	pros::lcd::register_btn2_cb(on_right_button);
	pros::lcd::register_btn0_cb(on_left_button);

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

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

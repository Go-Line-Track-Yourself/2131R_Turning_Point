#include "robot/api/init.hpp"
#include "main.h"
#include "robot/api/auto.hpp"
#include "robot/control/auton/selection.hpp"
#include "robot/control/modes/auton.hpp"
#include "robot/control/systems/lift.hpp"
#include "robot/control/systems/puncher.hpp"

bool inited = false;
void systemInit() {  // custom robot init dont trust the reliability of
                     // initialize && competition_initialize
  if (!inited) {
    inited = true;
    puncher::motor.tarePosition();//reset puncher at the beg of match
    drive::LeftN.set_limits(drive::LeftN.get_changeMsec(),-drive::LeftN.get_changeMsec(),0,0);
    drive::RightN.set_limits(drive::RightN.get_changeMsec(),-drive::RightN.get_changeMsec(),0,0);
    drive::LeftS.set_limits(drive::LeftS.get_changeMsec(),-drive::LeftS.get_changeMsec(),0,0);
    drive::RightS.set_limits(drive::RightS.get_changeMsec(),-drive::RightS.get_changeMsec(),0,0);
  }
}
void initialize() {
  pros::lcd::initialize();
//  auton::onScreen();
  pros::lcd::set_text(1, "Good Luck 2131R :)");
  pros::lcd::set_text(2, POSITIONS[POSITION]);

  pros::lcd::register_btn2_cb(auton::selection::on_right_button);
  pros::lcd::register_btn0_cb(auton::selection::on_left_button);

  puncher::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  lift::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  intake::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

      std::cout<<"inited"<<std::endl;
}
void disabled(void) {
  auton::autonTask.suspend();
  auton::set_auton(false);

}
void competition_initialize(void) {

}

#include "robot/control/modes/flag.hpp"
#include "robot/control/modes/flow.hpp"

#include "robot/control/systems/drive.hpp"
#include "robot/control/systems/intake.hpp"
#include "robot/control/systems/lift.hpp"
#include "robot/control/systems/puncher.hpp"

namespace flag{
  void user(){
    drive::control::manual();
    drive::control::hold();

    intake::control::doubleShoot();
    intake::control::feedIn();
    intake::control::feedOut();
    intake::control::toggle();
    intake::control::SkillsIntake();

    // lift::control::flag::manual();
    lift::control::calabrate();
    lift::control::position();

    // flipper::control::flag::manual();
    // flipper::control::calabrate();

    puncher::control::charge();
    // puncher::control::doubleBack();
    // puncher::control::doubleFront();
  }
  void init(){
    drive::set_inverted(false);
    lift::set_target(lift::down,lift::vDown,true);
    // flipper::set_target(flipper::up,flipper::vUp,true);
    controllerMaster.setText(1,5,"FLAG");
    flow::set_mode(flow::Modes::FLAG);
  }
  void deInit(){

  }
}

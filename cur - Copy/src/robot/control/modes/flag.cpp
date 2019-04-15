#include "robot/control/modes/flag.hpp"
#include "robot/control/modes/flow.hpp"

#include "robot/control/systems/drive.hpp"
#include "robot/control/systems/intake.hpp"
#include "robot/control/systems/lift.hpp"
#include "robot/control/systems/flipper.hpp"
#include "robot/control/systems/puncher.hpp"

namespace flag{
  void user(){
    drive::control::manual();
    drive::control::hold();

    // intake::control::combo();
    intake::control::feedIn();
    intake::control::feedOut();
    intake::control::toggle();

    Lift::control::flag::manual();
    // Lift::control::calabrate();

    flipper::control::flag::manual();
    flipper::control::calabrate();

    Catapult::control::charge();
    // Catapult::control::doubleBack();
    // Catapult::control::doubleFront();
  }
  void init(){
    drive::set_inverted(false);
    Lift::set_target(Lift::down,Lift::vDown,true);
    flipper::set_target(flipper::up,flipper::vUp,true);
    controllerMaster.setText(1,5,"FLAG");
    Mode::set_mode(Mode::Modes::FLAG);
  }
  void deInit(){

  }
}

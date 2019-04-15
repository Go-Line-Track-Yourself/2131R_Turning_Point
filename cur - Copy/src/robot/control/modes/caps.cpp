#include "robot/control/modes/caps.hpp"
#include "robot/control/modes/flow.hpp"

#include "robot/control/systems/drive.hpp"
#include "robot/control/systems/intake.hpp"
#include "robot/control/systems/lift.hpp"
#include "robot/control/systems/flipper.hpp"
#include "robot/control/systems/puncher.hpp"

namespace caps{
  void user(){
    drive::control::manual();
    drive::control::hold();

    intake::control::feedIn();
    intake::control::feedOut();
    // intake::control::toggle();

    Lift::control::caps::manual();
    Lift::control::calabrate();
    Lift::control::position();

    flipper::control::caps::manual();

    // Catapult::control::
  }
  void init(){
    // intake::automatic::disable();
    flipper::set_target(flipper::up,flipper::vUp,true);
    // Lift::set_target(Lift::down,Lift::vDown,true);
    drive::set_inverted(true);
    controllerMaster.setText(1,5,"CAPS");
    Mode::set_mode(Mode::Modes::CAPS);
    Lift::btnPosTog.changed();
  }
  void deInit(){

  }
}

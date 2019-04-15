#include "robot/control/modes/auton.hpp"

#include "robot/control/systems/drive.hpp"
#include "robot/control/systems/intake.hpp"
#include "robot/control/systems/lift.hpp"
#include "robot/control/systems/flipper.hpp"
#include "robot/control/systems/puncher.hpp"
// DriveEndWait=0;
// TurnEndWait=0;
// PuncherEndWait=0;
namespace auton{
  bool inAuton=false;
  void set_auton(bool b){
    inAuton=b;
  }
  void Task(void*why){
    while(1){
      if(inAuton){
        drive::auton::ramping();
        Catapult::execute();

        intake::execute();
        Lift::execute();
        flipper::execute();
      }
      pros::delay(5);//delay for 5 millis exact
    }
  }
}

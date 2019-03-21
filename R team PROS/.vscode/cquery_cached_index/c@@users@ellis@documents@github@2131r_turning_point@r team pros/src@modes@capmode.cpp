#include "main.h"
#include "Functions/Drive.hpp"
#include "Functions/Feed.hpp"
#include "Functions/Lift.hpp"

void CapMode(){

  Drive::tankdrive( -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftY)*200,
             -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightY)*200,
             -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightX)*200,
             -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftX)*200);

  Lift::ManualLift();

  Lift::Flipper();

}

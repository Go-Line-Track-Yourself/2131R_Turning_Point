#include "main.h"
#include "Functions/Catapult.hpp"
#include "Functions/Drive.hpp"
#include "Functions/Feed.hpp"
#include "Functions/Lift.hpp"

extern void CapMode(){

  Drive::tankdrive( -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftY),
             -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightY),
             -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightX),
             -Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftX));

  Lift::ManualLift();

  Lift::Flipper();

}

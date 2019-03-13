#include "main.h"
#include "Functions/Drive.hpp"
#include "Functions/Feed.hpp"
#include "Functions/Lift.hpp"
#include "Functions/Puncher.hpp"

void FlagMode(){

  Drive::tankdrive( Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftY)*200,
             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightY)*200,
             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightX)*200,
             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftX)*200);

  Feed::AutoFeed();

  Puncher::Puncher();

  Lift::Rotater();

}

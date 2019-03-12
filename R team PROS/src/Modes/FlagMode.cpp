#include "main.h"
#include "Functions/Drive.hpp"
#include "Functions/Feed.hpp"
#include "Functions/Lift.hpp"
#include "Functions/Puncher.hpp"

extern void FlagMode(){

  Drive::tankdrive( Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftY),
             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightY),
             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightX),
             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftX));

  Feed::AutoFeed();

  Puncher::Puncher();

  Lift::Rotater();

}

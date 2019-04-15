#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include "okapi/api.hpp"

extern okapi::Controller Ellisons_Controller;

namespace Feed{
  extern okapi::ControllerButton Button;
}

namespace Lift{
  extern okapi::ControllerButton UpButton;
  extern okapi::ControllerButton DownButton;
  extern okapi::ControllerButton FlipperButton;
}

namespace Catapult{
  extern okapi::ControllerButton Button;
}

namespace Drive{
  extern okapi::ControllerButton BreakButton;
}

namespace Mode{
  extern okapi::ControllerButton Button;
}


#endif

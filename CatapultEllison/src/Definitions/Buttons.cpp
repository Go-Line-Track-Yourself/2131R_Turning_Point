#include "Definitions/Buttons.hpp"

okapi::Controller Ellisons_Controller;

//feed buttons
namespace Feed{
  okapi::ControllerButton Button = Ellisons_Controller[okapi::ControllerDigital::L1];
}

//lift buttons
namespace Lift{
  okapi::ControllerButton UpButton = Ellisons_Controller[okapi::ControllerDigital::R1];
  okapi::ControllerButton DownButton = Ellisons_Controller[okapi::ControllerDigital::R2];
  okapi::ControllerButton FlipperButton = Ellisons_Controller[okapi::ControllerDigital::L1];
}

//catapult buttons
namespace Catapult{
  okapi::ControllerButton Button = Ellisons_Controller[okapi::ControllerDigital::R1];
}

//drive buttons
namespace Drive{
  okapi::ControllerButton BreakButton = Ellisons_Controller[okapi::ControllerDigital::L2];
}

namespace Mode{
  okapi::ControllerButton Button = Ellisons_Controller[okapi::ControllerDigital::A];
}

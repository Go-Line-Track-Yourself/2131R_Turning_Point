#include "Definitions/Buttons.hpp"
#include "Definitions/Motors.hpp"

//ramp buttons
namespace ramp{
  okapi::ControllerButton ScoreButton = ellisonsController[okapi::ControllerDigital::Y];
  okapi::ControllerButton UpButton = ellisonsController[okapi::ControllerDigital::A];
  okapi::ControllerButton DownButton = ellisonsController[okapi::ControllerDigital::B];
}

//drive buttons
namespace drive{
  okapi::ControllerButton BreakButton = ellisonsController[okapi::ControllerDigital::up];
}

//intake buttons
namespace intake{
  okapi::ControllerButton FastButton = ellisonsController[okapi::ControllerDigital::down];
  okapi::ControllerButton BackButton = ellisonsController[okapi::ControllerDigital::X];
  okapi::ControllerButton InButton = ellisonsController[okapi::ControllerDigital::R1];
  okapi::ControllerButton OutButton = ellisonsController[okapi::ControllerDigital::R2];
}

namespace lift{
  okapi::ControllerButton UpButton = ellisonsController[okapi::ControllerDigital::L1];
  okapi::ControllerButton DownButton = ellisonsController[okapi::ControllerDigital::L2];
  okapi::ControllerButton MaxButton = ellisonsController[okapi::ControllerDigital::up];
  okapi::ControllerButton MinButton = ellisonsController[okapi::ControllerDigital::right];
}

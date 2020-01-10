#include "robot/config/controller_config.hpp"

okapi::Controller controllerMaster(okapi::ControllerId::master);
pros::Controller controllerSlave(pros::controller_id_e_t::E_CONTROLLER_PARTNER);
namespace flow{
  okapi::ControllerButton btnTog = controllerMaster[okapi::ControllerDigital::up];
  okapi::ControllerButton btnToCaps = controllerMaster[okapi::ControllerDigital::Y];
}
namespace drive{
  okapi::ControllerButton btnBrake = controllerMaster[okapi::ControllerDigital::L2];
}
namespace intake{
  okapi::ControllerButton btnDouble = controllerMaster[okapi::ControllerDigital::R2];
  okapi::ControllerButton btnIn = controllerMaster[okapi::ControllerDigital::X];
  okapi::ControllerButton btnOut = controllerMaster[okapi::ControllerDigital::A];
  okapi::ControllerButton btnTog = controllerMaster[okapi::ControllerDigital::L1];
  okapi::ControllerButton btnSkills = controllerMaster[okapi::ControllerDigital::B];
}
namespace lift{
  okapi::ControllerButton btnUp = controllerMaster[okapi::ControllerDigital::R1];
  okapi::ControllerButton btnDown = controllerMaster[okapi::ControllerDigital::R2];
  okapi::ControllerButton btnCal = controllerMaster[okapi::ControllerDigital::down];
  
  okapi::ControllerButton btnPosTog = controllerMaster[okapi::ControllerDigital::R2];
}
namespace puncher{
  okapi::ControllerButton btnCharge = controllerMaster[okapi::ControllerDigital::R1];
  // okapi::ControllerButton btnDoubleBack = controllerMaster[okapi::ControllerDigital::left];
  // okapi::ControllerButton btnDoubleFront = controllerMaster[okapi::ControllerDigital::right];
}
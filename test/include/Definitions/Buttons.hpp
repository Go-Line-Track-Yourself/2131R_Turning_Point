#pragma once
#include "main.h"

//lift buttons
namespace lift{
  extern okapi::ControllerButton UpButton;
  extern okapi::ControllerButton DownButton;
  extern okapi::ControllerButton MaxButton;
  extern okapi::ControllerButton MinButton;
}

//ramp buttons
namespace ramp{
  extern okapi::ControllerButton ScoreButton;
  extern okapi::ControllerButton UpButton;
  extern okapi::ControllerButton DownButton;
}

//drive buttons
namespace drive{
  extern okapi::ControllerButton BreakButton;
}

//intake buttons
namespace intake{
  extern okapi::ControllerButton FastButton;
  extern okapi::ControllerButton BackButton;
  extern okapi::ControllerButton InButton;
  extern okapi::ControllerButton OutButton;
}

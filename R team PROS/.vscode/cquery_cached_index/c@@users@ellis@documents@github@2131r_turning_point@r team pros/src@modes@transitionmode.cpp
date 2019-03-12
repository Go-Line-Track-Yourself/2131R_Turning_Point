#include "Modes/Transitions.hpp"
#include "Modes/FlagMode.hpp"
#include "Modes/CapMode.hpp"

namespace Mode{

  bool Inverted;
  bool Pressed;

void Transition(){
    if (Button.isPressed() && Pressed == false){
          Pressed = true;
          Inverted = !Inverted;
    }
    if (!Button.isPressed() && Pressed ==true){
        Pressed = false;
    }

    if (Pressed){
        FlagMode();
    }
    if (!Pressed){
        CapMode();
    }

}
}

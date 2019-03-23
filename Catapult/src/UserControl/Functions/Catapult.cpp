#include "Functions/Catapult.hpp"

namespace Catapult{

  bool Pressed;
  bool Inverted;
  bool Run;

  int Target;
  int Charge;
  int Fire;

void Catapult(){
     if (Button.isPressed() && Pressed == false) {
         Pressed = true;
         Inverted = !Inverted;

                  if (Inverted){
                      Target += Charge;
                  }
                  if (!Inverted){
                      Target += Fire;
                  }
}

     if (!Button.isPressed() && Pressed == true) {
             Pressed = false;
         }




if (Run)
{
    if(std::abs(Target-Motor.getPosition())<2){
        Motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        Run = false;
    }
    else{
      Motor.moveAbsolute(Target,100);
    }
}
}
}

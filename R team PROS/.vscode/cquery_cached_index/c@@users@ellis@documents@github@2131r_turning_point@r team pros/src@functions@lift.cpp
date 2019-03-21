#include "main.h"
#include "Functions/Lift.hpp"

namespace Lift{

  bool Pressed;
  bool Inverted;

void ManualLift(){
  if (UpButton.isPressed()){
    Motor.moveVelocity(100);
  }
  if(DownButton.isPressed()){
    Motor.moveVelocity(-100);
  }
}

void Flipper(){

  if(FlipperButton.isPressed() && Pressed == false){
    Pressed = true;
    Inverted = !Inverted;
  }

  if(!FlipperButton.isPressed() && Pressed == true){
    Pressed = false;
  }

    if(Inverted){
    Motor.moveAbsolute(20,100);
   }

   if(!Inverted){
    Motor.moveAbsolute(-200,100);
   }
}


void Rotater(){

  if (RotaterButton.isPressed() && Pressed == true) {
           Pressed = false;
           Inverted = !Inverted;
       }

  if (!RotaterButton.isPressed() && Pressed == false) {
           Pressed = true;
       }

       if (Inverted){
           Motor.moveAbsolute(100,100);
       }

       if (!Inverted){
           Motor.moveAbsolute(0,100);
       }

   }


}

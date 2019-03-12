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

  if(Pressed){
    Motor.moveAbsolute(20,100);
   }

  if(!Pressed){
    Motor.moveAbsolute(0,100);
   }


}
}

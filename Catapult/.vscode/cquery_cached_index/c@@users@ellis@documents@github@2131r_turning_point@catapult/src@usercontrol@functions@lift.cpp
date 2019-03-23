#include "main.h"
#include "Functions/Lift.hpp"


namespace Lift{

  bool Pressed;
  bool Inverted;

Controller ControllerValue;
int velocity;
int position;

  Controller ControllerInput(){
    return ControllerValue;
  }

  void ControllerSet(Controller Input){
    ControllerValue = Input;
  }

void LiftTransitions(){
  if(ControllerInput()==Controller::MANUAL){
      Motor.moveVelocity(velocity);
  }

  else if(ControllerInput()==Controller::FLIPPER){
    Motor.moveAbsolute(position,velocity);
  }

  else if (ControllerInput()==Controller::OFF){
    Motor.moveVelocity(0);
  }

}

void ManualLift(){
  if(UpButton.isPressed()){
      ControllerSet(Controller::MANUAL);
      velocity = 100;
  }

  else if(DownButton.isPressed()){
    ControllerSet(Controller::MANUAL);
    velocity = -100;
  }

  else if (ControllerInput()==Controller::MANUAL) {
    ControllerSet(Controller::OFF);
  }


}

void Flipper(){
  if(FlipperButton.isPressed() && Pressed == true){
      ControllerSet(Controller::FLIPPER);
      position = 300;
      velocity = 100;
      Pressed = false;
  }

  else if(FlipperButton.isPressed() && Pressed == false){
    ControllerSet(Controller::FLIPPER);
    position = 0;
    velocity = -100;
    Pressed = true;
  }

  else if (ControllerInput()==Controller::FLIPPER) {
    ControllerSet(Controller::OFF);
  }


}
}

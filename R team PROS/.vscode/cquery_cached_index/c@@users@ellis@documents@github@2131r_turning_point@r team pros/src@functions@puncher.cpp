#include "Functions/Puncher.hpp"
namespace Puncher{

  bool Pressed;
  bool Inverted;
  bool Run;

  int Target =0;
  int charge = -390;
  int fire = -330;

void Puncher(){
   if (Button.isPressed() && Pressed == false) {
       Pressed = true;
       Inverted = !Inverted;
       Run =true;

       if (Inverted){
           Target+=charge;
       }
       if (!Inverted){
           Target+=fire;
       }
   }
   if (!Button.isPressed() && Pressed == true) {
       Pressed = false;
   }

   if(Run)
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

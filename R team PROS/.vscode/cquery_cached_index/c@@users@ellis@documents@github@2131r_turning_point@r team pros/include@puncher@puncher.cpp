#include "Puncher/Puncher.hpp"

extern void Puncher(){
   if (PuncherButton.isPressed() && PuncherPressed == false) {
       PuncherPressed = true;
       PuncherEnabled = !PuncherEnabled;
       PuncherRun =true;

       if (PuncherEnabled){
           PunTar+=charge;
       }
       if (!PuncherEnabled){
           PunTar+=fire;
       }
   }
   if (!PuncherButton.isPressed() && PuncherPressed == true) {
       PuncherPressed = false;
   }

   if(PuncherRun)
   {
       if(std::abs(PunTar-PuncherMotor.getPosition())<2){
           PuncherMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
           PuncherRun = false;
       }
       else{
         PuncherMotor.moveAbsolute(100,100);
       }
   }
}

#include "Functions/Rotater.hpp"

void Rotater()
{

    if (Button.isPressed() && Pressed == true) {
        Pressed = false;
        Enabled = !Enabled;
    }

    if (!Button.isPressed() && Pressed == false) {
        Pressed = true;
    }

    if (Enabled){
        LiftMotor.moveAbsolute(100,100);
    }

    if (!Enabled){
        LiftMotor.moveAbsolute(100,100);
    }

}

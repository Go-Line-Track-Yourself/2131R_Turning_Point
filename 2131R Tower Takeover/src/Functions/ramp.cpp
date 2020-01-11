#include "main.h"
#include "Functions/ramp.hpp"

namespace ramp{
bool pressed = true;
bool activated = false;
const int MAX_VEL = 200;
const double TILT_VALUE = 805;

void autoScore(){
  double tiltValue = 500;
  intake::Motors.moveRelative(-9000, MAX_VEL/4);
  pros::delay(1000);
  Motor.moveAbsolute(tiltValue, MAX_VEL/4);
  pros::delay(2000);
  drive::Drive(40, 0.2);
  pros::delay(500);
  Motor.moveAbsolute(-225, MAX_VEL);
}

void score(double tiltValue, double velocity){
  Motor.moveAbsolute(tiltValue, velocity);
  pros::delay(500);
}

void tilter(){
  if(pressed && ScoreButton.isPressed()){
        pressed = false;
      }
      if(!pressed && !ScoreButton.isPressed()){
        pressed = true;
        activated = !activated;

        if(activated) score(TILT_VALUE, MAX_VEL / 5);
        if(!activated) score(0, MAX_VEL);
      }
    }

    // bool checkRampAngle(){
    //   if(Motor.getPosition() <= TILT_VALUE + 10 && Motor.getPosition() >= TILT_VALUE - 10) return true;
    //   else return false;
    // }

    void manual(){
      if(UpButton.isPressed()){
        Motor.moveVelocity(MAX_VEL / 5);
      }
      else if(DownButton.isPressed()){
        Motor.moveVelocity(-MAX_VEL / 5);
      }
      else{
        Motor.moveVelocity(0);
      }
    }
}

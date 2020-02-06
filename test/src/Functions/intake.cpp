#include "main.h"
const int MAX_VEL = 200;
const int INTAKE_HEIGHT = 100;
bool pressed = false;
bool activated = true;
double intakeSpeed;

namespace intake{
    void returnSpeed(){
      if(pressed && FastButton.isPressed()){
            pressed = false;
          }
      if(!pressed && !FastButton.isPressed()){
            pressed = true;
            activated = !activated;

            if(activated){
               Motors.moveVelocity(-MAX_VEL);
            }
            if(!activated){
               Motors.moveVelocity(-MAX_VEL / 5);
            }
          }
    }

  void manual(){
      if(InButton.isPressed()) Motors.moveVelocity(MAX_VEL);
      else if(lift::Motor.getPosition() >= INTAKE_HEIGHT && intake::OutButton.isPressed()){
        intake::Motors.moveVelocity(-MAX_VEL);
      }
      else if(OutButton.isPressed()){
        Motors.moveVelocity(-MAX_VEL / 5);
        //Motors.moveVelocity(-speedControl());
        // if((lift::Motor.getPosition()) < 10){
        //   // drive::RightMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
        //   // drive::LeftMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
        // }
      }
      else{
        pressed = false;
        activated = true;
        if(BackButton.isPressed()) Motors.moveVelocity(-MAX_VEL/5);
        // drive::RightMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        // drive::LeftMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        else {
          Motors.moveVelocity(0);
          Motors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
        }
      }
    }

     void autonIntake(double velocity, bool enabled){
       if(enabled) Motors.moveVelocity(velocity);
       if(!enabled) Motors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    }
  }

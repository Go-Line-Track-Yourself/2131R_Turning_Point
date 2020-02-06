#include "main.h"
#include "Functions/lift.hpp"

namespace lift{
  const int BUFFER = 200;
  const int MAX_VEL = 100;
  const int MAX_POS = 580;
  const int MIN_POS = 0;
  const int TALL_TOWER = 560;
  const int SMALL_TOWER = 440;
  const int HOLD_TIME = 2000;
  const int LAG_TIME = 200;
  const int SENSOR_VAL = 2200;
  bool pressed = true;
  bool changed = true;
  bool activated = false;
  bool initiated = false;
  bool manualControl = false;
  bool toggleControl = true;
  static bool wasPressed;
  static bool wasPresU;
  static double initialTimeU;
  static double initialTimeD;

  void lift(){
    if(UpButton.isPressed() && !wasPresU){
      initialTimeU = pros::millis();
      wasPresU = true;
    }
    else if(UpButton.isPressed()){//down holding
      if(pros::millis() - initialTimeU > LAG_TIME){//down hold
        Motor.moveVelocity(MAX_VEL/2);
      }
      else{//donw holding les then time
        // toggleDown();
      }
    }
    else if(!UpButton.isPressed() && wasPresU){//deinit
      wasPresU = false;
      if(pros::millis() - initialTimeU > LAG_TIME){//deinit holding
        Motor.moveVelocity(0);
      }
      else {//deinit tog
        Motor.moveAbsolute(TALL_TOWER, MAX_VEL);
      }
    }
    else if(DownButton.isPressed() && !wasPressed){//holding initialize
      initialTimeD = pros::millis();
      wasPressed = true;
    }
    else if(DownButton.isPressed()){//holding
      if(pros::millis() - initialTimeD > LAG_TIME){//down hold
        Motor.moveVelocity(-MAX_VEL/2);//todo move to else
      }
      else{//holding less than time
        // toggleDown();
      }
    }
    else if(!DownButton.isPressed() && wasPressed){//deinitialize
      wasPressed = false;
      if(pros::millis() - initialTimeD > LAG_TIME){//deinitialize holding
        Motor.moveVelocity(0);
      }
      else {//deinitialize the toggle
        Motor.moveAbsolute(SMALL_TOWER, MAX_VEL);
      }
    }
    else if(MinButton.isPressed()){
      // if(Sensor.get_value() > SENSOR_VAL) Motor.moveVelocity(-MAX_VEL);
      // else Motor.moveVelocity(0);
      // while(Sensor.get_value() > SENSOR_VAL){
      //    Motor.moveVelocity(-MAX_VEL);
      // }
      //   Motor.moveVelocity(0);
      // }
      Motor.moveAbsolute(0, MAX_VEL);
  }
}

  //main flow method for lifting
  void liftFlow(){
    if(UpButton.isPressed() || DownButton.isPressed()){
      manualControl = true;
      toggleControl = false;
      if(manualControl) manual();
      else if(toggleControl){
        smallTower();
        tallTower();
      }
    }
    else if(MaxButton.isPressed() || MinButton.isPressed()){
      manualControl = false;
      toggleControl = true;
      if(manualControl) manual();
      else if(toggleControl){
        smallTower();
        tallTower();
      }
    }
  }

  //manual method to use if Matt wants to go full manual
  void manual(){
        if(UpButton.isPressed()){
            ramp::Motor.moveAbsolute(100, MAX_VEL/2);
            Motor.moveVelocity(MAX_VEL/1.5);
            if(Motor.getPosition() >= MAX_POS) Motor.moveVelocity(0);
        }
        else if(DownButton.isPressed()){
            Motor.moveVelocity(-MAX_VEL);
            ramp::Motor.moveAbsolute(0, MAX_VEL/9);
            if(Motor.getPosition() <= MIN_POS) Motor.moveVelocity(0);
        }
        else{
          Motor.moveVelocity(0);
          Motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
        }
    }

    //quicker lift method
    void liftTo(double position, double velocity){
      Motor.moveAbsolute(position, velocity);
      pros::delay(500);
    }

    //testing method
    void smallTower(){
      if(pressed && MinButton.isPressed()){
            pressed = false;
          }
          if(!pressed && !MinButton.isPressed()){
            pressed = true;
            activated = !activated;

            if(activated) liftTo(SMALL_TOWER, MAX_VEL);
            if(!activated) liftTo(0, MAX_VEL);
          }
    }

    //testing method
    void tallTower(){
      if(changed && MaxButton.isPressed()){
            changed = false;
          }
          if(!changed && !MaxButton.isPressed()){
            changed = true;
            initiated = !initiated;

            if(initiated) liftTo(TALL_TOWER, MAX_VEL);
            if(!initiated) liftTo(0, MAX_VEL);
          }
    }

     //lift up method used in autonomous
     void autoLift(double height){
       double maxHeight = 63.5;
       double centimeter = 360 / maxHeight;
       height *= centimeter;

       Motor.moveAbsolute(height, MAX_VEL);
       Motor.moveAbsolute(height, MAX_VEL);
       pros::delay(BUFFER);
       Motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
       Motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
     }
}

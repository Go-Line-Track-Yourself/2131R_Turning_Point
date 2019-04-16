#include "robot/control/systems/lift.hpp"
#include "robot/control/modes/flow.hpp"
#include "main.h"

namespace lift{
  //vars
  Controllers controller=Controllers::NONE;

  //position
  const double down=32;//at ground
  const double up=280;//max in 18_ft spec
  const double limitMin=down;
  const double limitMax=600;
  double P=down;//position setting

  //velocity
  const int vMove=100;
  const int vStop=0;
  const int vUp=vMove;
  const int vDown=-vMove;
  const int vPos=vMove/2;
  const int vCal=-vMove/2;
  int V=vStop;//velocity setting

  //calabrate
  bool Calabrated=false;

  //vars FUNCTIONS
  Controllers get_controller(){
    return controller;
  }
  void set_controller(Controllers c){
    controller=c;
  }
  int get_v(){
    return V;
  }
  void set_v(int v){
    V=v;
  }
  double get_target(){
    return P;
  }
  void set_target(double t){
    P=t;
  }
  void set_target(double t,bool p){
    P=t;
    if(p) set_controller(Controllers::POSITION);
  }
  void set_target(double t,int v){
    set_target(t);
    set_v(v);
  }
  void set_target(double t,int v,bool p){
    set_target(t);
    set_v(v);
    if(p) set_controller(Controllers::POSITION);
  }
  bool get_calabrated(){
    return Calabrated;
  }
  //methods
  void positionChanger(int v=vMove){
    set_v(v);
    if(get_controller()==Controllers::MANUAL){
      set_target(down,vDown);
    }
    else if(get_target()==up)       set_target(down,-vPos);
    else if(get_target()==down)     set_target(up,vPos);
    // else if(get_target()==punFront1)  set_target(down,-vPos);
    // else if(get_target()==punFront2)  set_target(up,vPos);
    // else if(get_target()==punBack1)  set_target(down,-vPos);
    // else if(get_target()==punBack2)  set_target(up,vPos);
    set_controller(Controllers::POSITION);
  }
  void calabrate(){//20 loops
    const static int tStart=pros::millis();
    if(pros::millis()>tStart+400){
      motor.moveVelocity(vStop);
      motor.tarePosition();
      Calabrated=true;
      set_target(down, vUp, true);
      motor.setLimitPositons(lift::limitMin,lift::limitMax);
    }
    else {
      motor.moveVelocity(vCal);
    }
  }
  void execute(){
    if(!Calabrated){
      calabrate();
    }
    else{
      switch(get_controller()){
        case Controllers::MANUAL:
        motor.moveVelocity(get_v());
        break;
        case Controllers::POSITION:
        motor.moveAbsolute(get_target(), get_v());
        break;
        case Controllers::CALABRATE:
        motor.moveVelocity(get_v());
        break;
        case Controllers::NONE:
        motor.moveVelocity(vStop);//stop the motor
        break;
      };
    }
  }
  namespace feedback{
    // void rumble(){
    //   if(CapBump.changed()){
    //     if(CapBump.isPressed()){
    //       controllerMaster.rumble(".");
    //     }
    //   }
    // }
  }
  namespace control{
      void manual(){
        if(btnDown.isPressed()){
          set_controller(Controllers::MANUAL);
          set_v(vDown);
        }
        else if(btnUp.isPressed()){
          set_controller(Controllers::MANUAL);
          set_v(vUp);
        }
        else if(get_controller()==Controllers::MANUAL){//deinti
          set_controller(Controllers::NONE);
          set_v(0);
        }
      }
    void position(){
      if(btnPosTog.changed()){
        if(btnPosTog.isPressed()){//init
          // set_controller(Controllers::POSITION);
          positionChanger();
        }
        else{//deInit

        }
      }
      else if(btnPosTog.isPressed()){//hold

      }
      else{

      }
    }
    void calabrate(){
      if(btnCal.changed()){
        if(btnCal.isPressed()){//init
          set_controller(Controllers::CALABRATE);
          motor.setLimitPositionDisabled();
          set_v(vCal);
        }
        else{//deInit
          motor.tarePosition();
          motor.setLimitPositionsEnabled();
          set_target(down,vMove,true);
        }
      }
      else if(btnCal.isPressed()){//hold

      }
      else{

      }
    }
  }
  inline  namespace auton{
    void wait(int w){
      while(std::abs(motor.getPosition()-get_target())>2){
        pros::delay(5);
      }
      pros::delay(w);
    }
  }
}

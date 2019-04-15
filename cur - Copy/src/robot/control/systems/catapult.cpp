#include "robot/control/systems/puncher.hpp"
#include "robot/control/systems/drive.hpp"
#include "robot/control/systems/intake.hpp"
#include "robot/control/systems/lift.hpp"
#include "main.h"

// #include "robot/auton/routines.hpp"
namespace Catapult{
  // pros::Mutex DoubleShotTaskMutex();
  bool Calabrated=false;
  //vars
  Controllers Controller=Controllers::NONE;

  const int VMove=100;
  const int VStop=0;

  int V=VStop;
  bool Charged=true;

  //vars FUNCTIONS
  Controllers get_controller(){
    return Controller;
  }
  void set_controller(Controllers c){
    Controller=c;
  }
  int get_v(){
    return V;
  }
  void set_v(int v){
    V=v;
  }
  bool get_charged(){
    return Charged;
  }
  void set_charged(bool c){
    Charged=c;
  }
  //OnOffCon
  //methods
  namespace OnOffCon{
    //vars
    const int ReleasedtoCharged=100;//not used if started charged
    const int ChargedToCharged=360*5;//65
    double Target=ReleasedtoCharged;//running sum;starts up to fix calibration
    bool Run=false;
    bool Enabled=false;
    //vars FUNCTIONS
    bool get_run(){
      return Run;
    }
    void set_run(bool r){
      Run=r;
    }
    bool get_enabled(){
      return Enabled;
    }
    void set_enabled(bool e){
      Enabled=e;
    }
    double get_target(){
      return Target;
    }
    void set_target(double t){
      Target=t;
    }
    void set_targetRel(double t){
      Target+=t;
    }
    //methods
    void execute(){
      if(motor.getPosition()<get_target() && get_run()){//outside of tal
        set_controller(Controllers::ONOFF);
        // Dir=SGN(Tar-Punchermotor.rotation(vex::rotationUnits::deg));
        set_v(VMove);//set the motor to spin in the correct direction
      }
      else if(get_controller()==Controllers::ONOFF){//if in tar zone and was enabled; fist not enabled
        set_controller(Controllers::NONE);
        set_v(0);
        set_run(false);//stop after it has been hit
      }
    }
  }
  void positionChanger(){
    // ComRumerFun();
    if(!get_charged()){//set up
      OnOffCon::set_targetRel(OnOffCon::ReleasedtoCharged);
      OnOffCon::set_run(true);
      set_charged(true);
    }
    else if(get_charged()){//fire
      OnOffCon::set_targetRel(OnOffCon::ChargedToCharged);
      OnOffCon::set_run(true);
    }
  }
  void calabrate(){//20 loops
    const static int tStart=pros::millis();
    if(pros::millis()>tStart+250){
      motor.moveVelocity(0);
      motor.tarePosition();
      Calabrated=true;
      OnOffCon::set_run(true);//enable it to reset its self
      //set target;//target starts at its offset from cal
      // motor.setLimitPositons(Lift::limitMin,Lift::limitMax);
    }
    else {
      motor.moveVelocity(-50);
    }
  }
  void execute(){
    if(!Calabrated) calabrate();
    else{
      OnOffCon::execute();
      if(get_controller()==Controllers::ONOFF){
        motor.moveVelocity(get_v());
      }
      else if(get_controller()==Controllers::NONE){
        motor.moveVelocity(VStop);
      }
    }
  }

  namespace control{
    // okapi::Motor::brakeMode initBrakeMode = okapi::Motor::brakeMode::coast;
    void charge(){
      if(btnCharge.changed()){
        if(btnCharge.isPressed()){//inti
          // initBrakeMode = drive::get_brakeMode();
          // intake::automatic::enable();
          // drive::set_brakeMode(okapi::Motor::brakeMode::hold);
          positionChanger();
        }
        else{//deInit
          // drive::set_brakeMode(initBrakeMode);
        }
      }
      else if(btnCharge.isPressed()){//hold

      }
      else{

      }
    }
  }
  namespace auton{
    void wait(int w){
      while(OnOffCon::get_run()){//wait for the motor to hit its target pos
        pros::delay(5);
      }
      pros::delay(w);
    }
    void charge(bool w){
      if(!get_charged())  positionChanger();//charge
      if(w)  wait();
    }
    void fire(int wait){
      auton::charge(false);//verify charghed dont wait
      positionChanger();//fire
      pros::delay(wait);
      // intake::automatic::balls::set_puncher(false);
      // intake::automatic::balls::set_overEnabled(false);
    }
  }
}

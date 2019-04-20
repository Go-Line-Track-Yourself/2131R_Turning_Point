#include "robot/control/systems/intake.hpp"
#include "robot/config/controller_config.hpp"
#include "robot/config/motor_config.hpp"
#include "robot/control/modes/flag.hpp"

namespace intake{
// vars
Controllers controller = Controllers::NONE;

const int vMove = 170;
const int vIn = vMove;
const int vOut = -vMove;
const int vStop = 0;
int V = vStop;


// vars FUNCTIONS
Controllers get_controller() { return controller; }
void set_controller(Controllers c) { controller = c; }
int get_v() { return V; }
void set_v(int v) { V = v; }
void set_VSetting(int v) { set_v(v); }
void set_VSetting(int v, bool m)
{
  set_v(v);
  if (m)
    set_controller(Controllers::MANUAL);
}

// methods
void execute(){
  automatic::execute();
  control::execute();
  if (get_controller() == Controllers::NONE)
    motor.moveVelocity(vStop);
}
namespace control
{
void feedOut()
{
  static bool pressedWas;
  if (btnOut.changed())
  { //
    if (btnOut.isPressed())
    { // init
      set_controller(Controllers::MANUAL);
    }
    else
    { // deint
      set_controller(Controllers::NONE);
    }
  }
  else if (btnOut.isPressed())
  { // hold
    set_v(vOut);
  }
  else if (controllerSlave.get_digital(
               pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2) ==
           1)
  { // pressed
    pressedWas = true;
    set_controller(Controllers::MANUAL);
    set_v(vOut);
  }
  else if (pressedWas)
  {
    pressedWas = false;
    set_controller(Controllers::NONE);
    set_v(0);
  }
}
void feedIn()
{
  static bool pressedWas;
  if (btnIn.changed())
  {
    if (btnIn.isPressed())
    { // init
      set_controller(Controllers::MANUAL);
    }
    else
    { // deinit
      set_controller(Controllers::NONE);
    }
  }
  else if (btnIn.isPressed())
  { // hold
    set_v(vIn);
  }
  else if (pressedWas)
  {
    pressedWas = false;
    set_controller(Controllers::NONE);
    set_v(0);
  }
}
void toggle()
{
  if (btnTog.changed())
  {
    if (btnTog.isPressed())
    {               // init
      // flag::init(); // go to flag mode
      // set_controller(Controllers::AUTO);
      std::cout << "intake auto control toged"<<std::endl;
      automatic::toggle();
    }
    else
    { // deinit
    }
  }
  else if (btnTog.isPressed())
  { // hold
  }
  // else
  // if(controllerSlave.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1)==1){//pressed
  //   pressedWas=true;
  //     // flag::init();//go to flag mode
  //     set_controller(Controllers::AUTO);
  //     automatic::toggle();
  //   }
  // else if(pressedWas){
  //   pressedWas=false;
  // }
}
void doubleShoot()
{
  if (btnDouble.changed())
  {
    if (btnDouble.isPressed())
    {               // init
      automatic::feed2Balls=true;
      automatic::enable();
    }
    else
    { // deinit
    }
  }
  else if (btnDouble.isPressed())
  { // hold
  }
}

void execute()
{
  if (get_controller() == Controllers::MANUAL)
    motor.moveVelocity(get_v());
}
} // namespace control
namespace automatic{
  // vars
  const int bottomBallTal = 2500;  // sensor tollerance values
  const int middleBallTal = 2500;  // sensor tollerance values
  const int topBallTal = 2500;  // sensor tollerance values

  bool enabled = false; //
  bool enabledWas = false;

  bool feed2Balls=false;// put 2 balls in catapult


  // vars FUNCTIONS
  bool get_enabled() { return enabled; }
  void set_enabled(bool b)
  {
    enabledWas = enabled;
    enabled = b;
  }
  namespace balls
  {
  // vars
  bool bottomBall;
  bool middleBall;
  bool topBall;

  // vars FUNCTIONS

  // methods
  void updateVars()
  {
    if (top.get_value() < topBallTal)
    {
      topBall = true;
    }
    else
    {
      topBall = false;
    }
        if (middle.get_value() < middleBallTal)
    {
      middleBall = true;
    }
    else
    {
      middleBall = false;
    }
    if (bottom.get_value() < bottomBallTal)
    {
      bottomBall = true;
    }
    else
    {
      bottomBall = false;
    }
  }
  } // namespace balls
  // methods
  void toggle()
  { // toogle the current enabled state
        // std::cout << "intake automatic: ";

    if (get_enabled())        disable();
    else if (!get_enabled())  enable();
  }
  void enable()
  { // set to enabled state
    set_enabled(true);
    set_controller(Controllers::AUTO);
            // std::cout << "enabled"<<std::endl;
  }
  void disable()
  { // set to disabled state
    set_enabled(false);
    set_controller(Controllers::NONE);
                // std::cout << "disabled"<<std::endl;
  }
  void calcV()
  {
    if (get_enabled())
    {
      enabledWas = true;
        if (!balls::topBall) set_v(vIn);
        else{
          if(feed2Balls){
          if(!balls::middleBall)  set_v(vIn);
          else set_v(vStop);
        }
        else{//keep in feed
          if(!balls::bottomBall && !balls::middleBall)  set_v(vIn);
          else if (balls::topBall && balls::bottomBall) set_v(vStop);
          else if (balls::middleBall && balls::topBall) set_v(vStop);
        }
    }
  }
    else if (enabledWas)
    { // first loop disabled
      set_v(vStop);
      enabledWas = false;
    }
  }
  void execute()
  {
    balls::updateVars();
    if (get_controller() == Controllers::AUTO)
    {
      calcV();
      motor.moveVelocity(get_v());
    }
  }

//   void User_Control(){//not needed here combine all inside of the controlmodes
//     Toggle_Control();
}
} // namespace intake

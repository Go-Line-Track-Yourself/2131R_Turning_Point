#include "robot/control/auton/selection.hpp"
#include "display/lvgl.h"
#include "robot/config/controller_config.hpp"
#include "robot/control/auton/routines.hpp"
#include <algorithm>

int POSITION =0;
std::string POSITIONS [6]{"Testing","RedFront","RedBack","BlueFront","BlueBack","Skills"};

namespace auton{
  namespace selection{
    void on_left_button(){
    	POSITION--;
    	if(POSITION < 0) POSITION = 5;
    	pros::lcd::set_text(2, POSITIONS[POSITION]);
    }

    void on_right_button(){
    	POSITION++;
    	if(POSITION > 5) POSITION = 0;
    	pros::lcd::set_text(2, POSITIONS[POSITION]);
    }
  }
  void onScreen(){
    if(POSITION == 0){
      routines::testing();
    }
    if(POSITION ==1){
      routines::red::front();
    }
    if(POSITION ==2){
      routines::red::back();
    }
    if(POSITION ==3){
      routines::blue::front();
    }
    if(POSITION ==4){
      routines::blue::back();
    }
    if(POSITION ==5){
      routines::skills();
    }

  }
}

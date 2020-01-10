#include "robot/control/auton/routines.hpp"
#include "robot/control/auton/selection.hpp"

#include "robot/control/systems/drive.hpp"
#include "robot/control/systems/intake.hpp"
#include "robot/control/systems/lift.hpp"
#include "robot/control/systems/puncher.hpp"

namespace auton{
  namespace Drive=drive::auton;
  namespace Intake=intake::automatic;
  namespace Lift=lift;
  namespace Puncher=puncher::auton;
namespace routines{
    void testing(){

      Drive::drive(25,200,1);
      Drive::drive(-4,200,1);
      Lift::set_target(200,100,1);
      Drive::turnEnc(360,200,1);
      Drive::drive(-13,200,1);

      /*Drive::drive(12,200,1);
      Drive::turnEnc(-190,150,1);
      Drive::drive(-8,200,1);
      pros::delay(700);
      Puncher::fire(true);
      Puncher::wait();
      Drive::drive(3,200,1);
      Drive::turnEnc(175,150,1);
      Drive::drive(10,200,1);
      Drive::drive(-1,200,1);
      Lift::set_target(200,100,1);
      Lift::wait();
      Drive::turnEnc(360,150,1);
      Drive::drive(-16,200,1);
      Lift::set_target(-200,100,1);*/
    

         /*Drive::drive(25,200,1);
         // intake::automatic::feed2Balls = true;
         Drive::drive(-20,200,1);
         Drive::turnEnc(-365,125,1);
         Puncher::fire(true);
         pros::delay(500);
         Drive::turnEnc(-10,15,1);
         Drive::drive(24,200,1);
         Drive::drive(-24,200,1);
         Drive::turnEnc(178,150,1);
         Drive::drive(9.5,200,1);*/

      //possible back
      /*Drive::drive(25,200,1);
      Drive::drive(-3,200,1);
      Lift::set_target(200,100,1);
      Lift::wait();
      Drive::turnEnc(360,200,1);
      Drive::drive(-14,200,1);
      pros::delay(500);
      Drive::turnEnc(-720,200,1);
      Puncher::fire(true);
      Puncher::wait();*/
       
      /*Drive::turnEnc(-352,200,1);
      Drive::drive(-22,200,1);
      Drive::driveS(-7,200,1);
      Drive::drive(-3,200,1);
      Drive::turnEnc(360,150,1);
      Puncher::fire();
      pros::delay(400);
      Drive::turnEnc(-1.5,200,1);
      Drive::drive(27,200,1);
      Drive::drive(-27,200,1);
      Drive::turnEnc(-360,200,1);
      Drive::drive(-5,200,1);
      Drive::turnEnc(360,200,1);
      Drive::drive(5,200,1);
      Drive::turnEnc(-360,200,1);
      Drive::drive(65,200,1);*/

    }

  namespace red{
      void front(){
          Drive::drive(25,200,1);
         // intake::automatic::feed2Balls = true;
         Drive::drive(-20,200,1);
         Drive::turnEnc(-365,125,1);
         Puncher::fire(true);
         pros::delay(500);
         Drive::turnEnc(-10,15,1);
         Drive::drive(24,200,1);
         Drive::drive(-24,200,1);
         Drive::turnEnc(178,150,1);
         Drive::drive(9.5,200,1);
         Puncher::fire();
    
     
    }
    void back(){

       Drive::drive(25,200,1);
      Drive::drive(-4,200,1);
      Lift::set_target(200,100,1);
      Drive::turnEnc(360,200,1);
      Drive::drive(-13,200,1);

      
      // intake::automatic::feed2Balls=true;
     /* Drive::drive(9,200,1);
      Drive::turnEnc(-167,150,1);
      Drive::drive(-7,200,1);
      pros::delay(700);
      Puncher::fire(true);
      Puncher::wait();
      Drive::drive(3,200,1);
      Drive::turnEnc(175,150,1);
      Drive::drive(10,200,1);
      Drive::drive(-1,200,1);
      Lift::set_target(200,100,1);
      Lift::wait();
      Drive::turnEnc(360,150,1);
      Drive::drive(-16,200,1);
      Lift::set_target(-200,100,1);*/

      /*Drive::drive(29,200,1);
      Drive::drive(-4,200,1);
      Lift::set_target(200,100,1);
      Drive::turnEnc(-360,200,1);
      Drive::drive(-17,200,1);*/

      /*Drive::drive(29,200,1);
      Drive::drive(-4,200,1);
      Drive::turnEnc(35,200,1);
      Puncher::fire(true);
      Drive::turnEnc(-35,200,1);
      Lift::set_target(200,100,1);
      Drive::turnEnc(-360,200,1);
      Drive::drive(-17,200,1);
      */


    }
  }
  namespace blue{
    void front(){
        Intake::enable();
      Drive::drive(22,200,1);
      //intake::automatic::feed2Balls = true;
      Drive::drive(-16,200,1);
      Drive::turnEnc(360,150,1);
      Drive::drive(3,200,1);
      Puncher::fire(true);
      pros::delay(700);
      Drive::drive(6,200,1);
      Puncher::fire(true);
      pros::delay(700);
      Drive::turnEnc(5.5,200,1);
      Drive::drive(23,200,100);
      Drive::drive(-24,200,1);
      Drive::turnEnc(-165,150,1);
      Drive::drive(9,200,1);
      Puncher::fire(true);
     
    }
    void back(){
      Drive::drive(29,200,1);
      Drive::drive(-4,200,1);
      Lift::set_target(200,100,1);
      Drive::turnEnc(-360,200,1);
      Drive::drive(-17,200,1);

    }
  }
    void skills(){
      Intake::disable();
      Drive::drive(26,200,1);
      Intake::enable();
      // intake::automatic::feed2Balls = true;
      Drive::drive(-19,200,1);
      Drive::turnEnc(-360,150,1);
      Drive::drive(25,200,1);
      Puncher::fire();
      pros::delay(500);
      Drive::turnEnc(-4.5,200,1);
      Drive::drive(27,200,1);
      Drive::drive(-26,200,1);
      Drive::turnEnc(360,150,1);
      Intake::disable();
      Drive::driveRecon(-200,550,1);
      Drive::drive(37,200,1);
      Intake::enable();
      // intake::automatic::feed2Balls = true;
      Drive::drive(-2,200,1);
      Drive::turnEnc(-355,150,1);
      pros::delay(500);
      Puncher::fire();
      Drive::turnEnc(-1,200,1);
      Drive::drive(27,200,1);
      Drive::drive(-25,200,1);
      Drive::turnEnc(-352,150,1);
      Drive::drive(20,200,1);
      Drive::turnEnc(-352,150,1);
      Drive::drive(7,200,1);
      Drive::turnEnc(-352,150,1);
      Drive::drive(52,200,1);
    }
}
}

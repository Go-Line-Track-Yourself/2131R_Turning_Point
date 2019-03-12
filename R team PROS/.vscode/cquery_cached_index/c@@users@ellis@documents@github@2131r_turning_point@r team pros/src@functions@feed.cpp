#include "Functions/Feed.hpp"


  //Auto Feed control
  bool AutoFeedEnabled = false;
  bool BottomFeedReverse=false;
  bool AutoFiring;

  //Ball locations
  bool BallInBottom;
  bool BallInMiddle;
  bool BallInTop;

  //sensor value integers
  int  BottomSensorValue;
  int  MiddleSensorValue;
  int  TopSensorValue;

  //sensor maximums
  int BottomBallMax = 68;
  int MiddleBallMax = 50;
  int TopBallMax = 70;

  //set Bottom Feed Motor velocity
  int BottomFeedMotorVelocitySetting =13;

namespace Feed{


//setting velocity for entire feed
void setFeedVelocity(int velocity){
    TopMotor.move_velocity(velocity);
    BottomMotor.move_velocity(velocity);
}

//setting velocity for bottom feed only
void setBottomFeedVelocity(int velocity){
    BottomMotor.move_velocity(velocity);
}

void Auto_Feed() {

    //for autonomous cap flippingvex::controller Ellisons_Controller = vex::controller();
    if (BottomFeedReverse)
    {
        setBottomFeedVelocity(BottomFeedMotorVelocitySetting);
    }

    //for usercontrol autofeed
    else if(!BottomFeedReverse)
    {

    //getting values from light sensors
    BottomSensorValue = Bottom.get_value();
    MiddleSensorValue = Middle.get_value();
    TopSensorValue = Top.get_value();


    //if ball in bottom of intake
    if (BottomSensorValue < BottomBallMax) BallInBottom = true;
    else BallInBottom = false;

    //if ball in top of intake
    if (MiddleSensorValue < MiddleBallMax) BallInMiddle = true;
    else BallInMiddle = false;

    //if ball passed top sensor because of too much momentum
    if(TopSensorValue < TopBallMax) BallInTop = true;
    else BallInTop = false;


        //when there are 2 balls
        if (BallInBottom && BallInMiddle){
            setFeedVelocity(0);
        }

        //when there is one ball in the bottom of the feed
        if (BallInBottom && !BallInMiddle){
            setFeedVelocity(95);
        }

        //when there is one ball in the puncher
        if (!BallInBottom && BallInMiddle){
            setFeedVelocity(70);
        }

        //when there are no balls
        if (!BallInBottom && !BallInMiddle){
            setFeedVelocity(95);
        }

        //when an extra ball skips the bottom sensor and there are two balls in the puncher
        if (BallInMiddle && BallInTop){
            setFeedVelocity(-70);
        }

    }
}

//
void AutoFeed()
  {

    if(Button.changedToPressed()){
      Auto_Feed();
    }

    if(Button.changedToReleased()){
      AutoFeedEnabled = false;
      BottomMotor.move_velocity(100);
    }

  }
}

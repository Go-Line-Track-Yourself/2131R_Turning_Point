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


  //setting velocity for feed
  void setFeedVelocity(int velocity){
    Motor.move_velocity(velocity);

  }

  void Auto_Feed() {

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
      setFeedVelocity(580);
    }

    //when there is one ball in the puncher
    if (!BallInBottom && BallInMiddle){
      setFeedVelocity(550);
    }

    //when there are no balls
    if (!BallInBottom && !BallInMiddle){
      setFeedVelocity(590);
    }

    //when an extra ball skips the bottom sensor and there are two balls in the puncher
    if (BallInMiddle && BallInTop){
      setFeedVelocity(-570);
    }

  }

  int Pressed=false;
  int Inverted;

  void AutoFeed() {


      if (Button.isPressed() && Pressed == false){
      Pressed = true;
      Inverted = !Inverted;
      }

      else if (!Button.isPressed() && Pressed == true){
        Pressed = false;
      }


      if (Inverted){
        Auto_Feed();
      }
      if(!Inverted){
        AutoFeedEnabled = false;
        Motor.moveVelocity(0);
      }

    }
  }

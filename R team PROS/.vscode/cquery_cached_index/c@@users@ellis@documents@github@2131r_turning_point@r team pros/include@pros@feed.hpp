#ifndef INTAKE_HPP
#define INTAKE_HPP
#include "main.h"
#include "pros/MotorDefinitions.hpp"

//Auto Feed Boolians and Variables
bool AutoIntakeEnabled = false;
bool BottomFeedReverse=false;
bool AutoFiring;

bool BallInBottom;
bool BallInMiddle;
bool BallInTop;

extern int  BottomLightValue;
extern int  MiddleLightValue;
extern int  TopLightValue;

int BottomBallInMax = 68;
int MiddleBallInMax = 50;
int TopBallInMax = 70;

int BottomFeedMotorPowerSetting =13;


//setting velocity
void setFeedVelocity(int power)//setting velocity for entire feed
{
    FeedMotor.move_velocity(power);
    BottomFeedMotor.move_velocity(power);
}
void setBottomFeedVelocity(int power)//setting velocity for bottom feed only
{
    BottomFeedMotor.move_velocity(power);
}



void Auto_Feed() {

    if (BottomFeedReverse)//for autonomous cap flipping
    {
        setBottomFeedVelocity(BottomFeedMotorPowerSetting);
    }

    else if(!BottomFeedReverse)//for usercontrol autofeed
    {

    //getting values from light sensors
    BottomLightValue = BallSenseBottom.get_value();
    MiddleLightValue = BallSenseMiddle.get_value();
    TopLightValue = BallSenseTop.get_value();


    //if ball in bottom of intake
    if (BottomLightValue < BottomBallInMax) BallInBottom = true;
    else BallInBottom = false;

    //if ball in top of intake
    if (MiddleLightValue < MiddleBallInMax) BallInMiddle = true;
    else BallInMiddle = false;

    //if ball passed top sensor because of too much momentum
    if(TopLightValue < TopBallInMax) BallInTop = true;
    else BallInTop = false;



        if (BallInBottom && BallInMiddle)
        {
            setFeedVelocity(0);
            FeedMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        }
        if (BallInBottom && !BallInMiddle)
        {
            setFeedVelocity(95);

        }
        if (!BallInBottom && BallInMiddle)
        {
            setFeedVelocity(70);

        }
        if (!BallInBottom && !BallInMiddle)
        {
            setFeedVelocity(95);

        }
        if (BallInMiddle && BallInTop)
        {
            setFeedVelocity(-70);
        }
    }
}


#endif

#ifndef INTAKE_HPP
#define INTAKE_HPP



//Auto Feed Boolians and Variables
bool AutoIntakeEnabled = false;
bool BottomFeedReverse=false;
bool AutoFiring;

bool BallInTop;
bool BallInMiddle;
bool BallInBottom;

extern int TopLightValue;
extern int MiddleLightValue;
extern int	BottomLightValue;

int MiddleBallInMax = 50;
int BottomBallInMax = 68;
int TopBallInMax = 70;

int feedmotor2powersetting =13;

void setFeedVelocity(int power)//setting velocity for entire feed
{
    FeedMotor.move_velocity(power);
    FeedMotor2.move_velocity(power);
}
void setFeedVelocity2(int power)//setting velocity for bottom feed only
{
    FeedMotor2.move_velocity(power);
}

void Auto_Intake() {

    if (BottomFeedReverse)//
    {
        setFeedVelocity2(feedmotor2powersetting);
    }

    else if(!BottomFeedReverse)
    {

    BottomLightValue = BallSenseBottom.get_value();
    TopLightValue = BallSenseTop.get_value();
    MiddleLightValue = BallSenseMiddle.get_value();


    if (BottomLightValue < BottomBallInMax) BallInBottom = true;
    else BallInBottom = false;
    if (TopLightValue < TopBallInMax) BallInTop = true;
    else BallInTop = false;
    if(MiddleLightValue < MiddleBallInMax) BallInMiddle = true;
    else BallInMiddle = false;

    if (Ellisons_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) || AutoFiring==true) {
        if(AutoFiring){
          pros::delay(300);
          AutoFiring = false;

        }
    }
        if (BallInBottom && BallInTop)
        {
            setFeedVelocity(0);
            FeedMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        }
        if (BallInBottom && !BallInTop)
        {
            setFeedVelocity(95);

        }
        if (BallInTop && !BallInBottom)
        {
            setFeedVelocity(70);

        }
        if (!BallInBottom && !BallInTop)
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

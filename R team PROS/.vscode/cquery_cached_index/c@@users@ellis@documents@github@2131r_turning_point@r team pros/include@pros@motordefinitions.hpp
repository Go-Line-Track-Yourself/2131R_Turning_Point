#ifndef MOTORDEFINITIONS_HPP
#define MOTORDEFINITIONS_HPP
#include "main.h"
//define Motor Ports
pros::Controller Ellisons_Controller(pros::E_CONTROLLER_MASTER);
pros::Motor LeftBackMotor(19);
pros::Motor LeftFrontMotor(12);
pros::Motor RightBackMotor(20);
pros::Motor RightFrontMotor(11);
pros::Motor FeedMotor(1);
pros::Motor BottomFeedMotor(17);
pros::ADIAnalogIn BallSenseBottom (2);
pros::ADIAnalogIn BallSenseMiddle (3);
pros::ADIAnalogIn BallSenseTop (1);

#endif

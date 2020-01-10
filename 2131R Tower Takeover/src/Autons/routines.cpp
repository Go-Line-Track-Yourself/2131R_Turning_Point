#include "main.h"
#include "Functions/lift.hpp"
#include "Functions/intake.hpp"
#include "Functions/ramp.hpp"

const int MAX_VEL = 200;

void wait(double time){
  pros::delay(time);
  /*drive::RightMotors.tarePosition();
  drive::LeftMotors.tarePosition();*/
}

void debugging(){

  wait(100);
  intake::autonIntake(-MAX_VEL, true);
  wait(1000);
  // drive::Drive(20, -0.75);
  // wait(100);
  // lift::depatchWheeleys();
  // wait(100);
  intake::autonIntake(MAX_VEL, true);
  wait(100);
  drive::Drive(110, -0.75);
  wait(800);
  drive::Drive(90, 0.75);
  wait(500);
  drive::Turn(-14);
  wait(500);
  drive::Drive(25, -0.5);
  wait(500);
  drive::Turn(-2);
  wait(100);
  ramp::autoScore();
}

void redBack(){
  intake::autonIntake(MAX_VEL, true);
  wait(500);
  drive::Drive(-50, MAX_VEL / 3);
  wait(1000);
  drive::Drive(30, MAX_VEL / 2);
  wait(1000);
  drive::Turn(-12 * 360);
  wait(1000);
  drive::Drive(-70, MAX_VEL / 4);
  wait(100);
  ramp::autoScore();
}

void redFront(){
  wait(100);
  intake::autonIntake(-MAX_VEL, true);
  wait(2000);
  // drive::Drive(20, -0.75);
  // wait(100);
  // lift::depatchWheeleys();
  // wait(100);
//   intake::autonIntake(MAX_VEL, true);
//   wait(100);
//   drive::Drive(110, -0.75);
//   wait(800);
//   drive::Drive(90, 0.75);
//   wait(500);
//   drive::Turn(11);
//   wait(500);
//   drive::Drive(52, -0.75);
//   wait(500);
//   ramp::autoScore();
}

void blueBack(){
  intake::autonIntake(MAX_VEL, true);
  wait(500);
  drive::Drive(-50, MAX_VEL / 3);
  wait(1000);
  drive::Drive(30, MAX_VEL / 2);
  wait(1000);
  drive::Turn(11 * 360);
  wait(1000);
  drive::Drive(-70, MAX_VEL / 4);
  wait(100);
  ramp::autoScore();
}

void blueFront(){
  wait(100);
  intake::autonIntake(-MAX_VEL, true);
  wait(1000);
  // drive::Drive(20, -0.75);
  // wait(100);
  // lift::depatchWheeleys();
  // wait(100);
  intake::autonIntake(MAX_VEL, true);
  wait(100);
  drive::Drive(110, -0.75);
  wait(500);
  drive::Drive(90, 0.75);
  wait(500);
  drive::Turn(-14);
  wait(500);
  drive::Drive(25, -0.5);
  wait(500);
  drive::Turn(-2);
  ramp::autoScore();
}

void skills(){
  wait(100);
  intake::autonIntake(-MAX_VEL, true);
  wait(800);
  intake::autonIntake(MAX_VEL, true);
  drive::Drive(110, -0.75);
  wait(500);
  drive::Turn(-2.6);
  wait(500);
  drive::Drive(120, 0.75);
  wait(500);
  drive::Turn(2);
  wait(500);
  drive::Drive(100, -0.75);
  wait(500);
  drive::Drive(100, 0.75);
  wait(500);
  drive::Turn(9.5);
  wait(500);
  drive::Drive(30, -0.75);
  wait(500);
  ramp::autoScore();
}

void onePoint(){
  drive::Drive(-150, MAX_VEL);
  wait(1000);
  drive::Drive(150, MAX_VEL);
}

#include "main.h"
#include "Functions/lift.hpp"
#include "Functions/intake.hpp"
#include "Functions/ramp.hpp"

const int MAX_VEL = 200;

void wait(double time){
  pros::delay(time);
}

void debugging(){
  intake::autonIntake(-MAX_VEL, true);
  wait(800);
  intake::autonIntake(MAX_VEL, true);
  wait(100);
  drive::Drive(120, -0.5);
  wait(100);
  drive::Turn(-3);
  wait(100);
  intake::autonIntake(-MAX_VEL, true);
  wait(500);
  intake::autonIntake(0, true);
  wait(100);
  lift::autoLift(40);
  wait(800);
  drive::Drive(10, -0.5);
  wait(100);
  intake::autonIntake(-MAX_VEL/2, true);
  wait(1000);
  intake::autonIntake(0, true);
  wait(100);
  lift::autoLift(0);
  wait(100);
  drive::Drive(16, 0.75);
  wait(100);
  drive::Turn(3);
  wait(100);
  drive::Drive(40, -0.5);
  wait(100);
  drive::Turn(5);
  wait(100);
  intake::autonIntake(-MAX_VEL, true);
  wait(500);
  intake::autonIntake(0, true);
  wait(100);
  lift::autoLift(40);
  wait(800);
  drive::Drive(10, -0.5);
  wait(100);
  intake::autonIntake(-MAX_VEL/2, true);
  wait(1000);
  intake::autonIntake(0, true);
  wait(100);
  lift::autoLift(0);
  wait(100);
  drive::Drive(16, 0.75);
  wait(100);
  drive::Turn(-5);
  wait(100);
  drive::Drive(15, -0.5);
  wait(100);
  drive::Turn(6);
  wait(100);
  drive::Drive(10 ,-0.5);
  wait(100);
  ramp::autoScore();
  drive::Drive(1, -0.5);
  wait(900);
  drive::Drive(25, 0.5);
  wait(100);
  ramp::Motor.moveAbsolute(0, MAX_VEL);
  // intake::autonIntake(-MAX_VEL, true);
  // wait(800);
  // intake::autonIntake(MAX_VEL, true);
  // wait(400);
  // drive::Drive(100, -0.3);
  // wait(100);
  // drive::Drive(58, 0.8);
  // wait(100);
  // intake::autonIntake(0, true);
  // wait(100);
  // drive::Turn(-13);
  // wait(100);
  // drive::Drive(16, -0.75);
  // wait(100);
  // ramp::autoScore();
  // // intake::Motors.moveRelative(1000, MAX_VEL/2);
  // drive::Drive(1, -0.5);
  // wait(900);
  // drive::Drive(25, 0.5);
  // ramp::Motor.moveAbsolute(0, MAX_VEL);
}

void redBack(){
  intake::autonIntake(MAX_VEL, true);
  wait(500);
  drive::Drive(50, -MAX_VEL / 3);
  wait(1000);
  drive::Drive(30, MAX_VEL / 2);
  wait(1000);
  drive::Turn(-12);
  // wait(1000);
  // drive::Drive(-70, MAX_VEL / 4);
  // wait(100);
  // ramp::autoScore();
}

void redFront(){
  intake::autonIntake(-MAX_VEL, true);
  wait(800);
  intake::autonIntake(MAX_VEL, true);
  wait(400);
  drive::Drive(110, -0.3);
  wait(100);
  drive::Drive(70, 0.8);
  wait(100);
  intake::autonIntake(0, true);
  wait(100);
  drive::Turn(12);
  wait(100);
  drive::Drive(17, -0.75);
  wait(100);
  ramp::autoScore();
  // intake::Motors.moveRelative(1000, MAX_VEL/2);
  drive::Drive(1, -0.5);
  wait(1000);
  drive::Drive(25, 0.5);
  ramp::Motor.moveAbsolute(0, MAX_VEL);
}

void blueBack(){
  intake::autonIntake(-MAX_VEL, true);
  wait(800);
  intake::autonIntake(MAX_VEL, true);
  wait(400);
  drive::Drive(10, -0.5);
  wait(100);
  drive::Turn(14);
  wait(100);
  drive::Drive(20, -0.5);
  wait(100);
  drive::Turn(3);
  wait(100);
  drive::Drive(10, -0.5);
  wait(100);
  ramp::autoScore();
  intake::Motors.moveRelative(100, MAX_VEL/2);
  wait(1000);
  drive::Drive(25, 0.5);
  ramp::Motor.moveAbsolute(0, MAX_VEL);
}

void blueFront(){
  intake::autonIntake(-MAX_VEL, true);
  wait(800);
  intake::autonIntake(MAX_VEL, true);
  wait(400);
  drive::Drive(100, -0.3);
  wait(100);
  drive::Drive(58, 0.8);
  wait(100);
  intake::autonIntake(0, true);
  wait(100);
  drive::Turn(-13);
  wait(100);
  drive::Drive(16, -0.75);
  wait(100);
  ramp::autoScore();
  // intake::Motors.moveRelative(1000, MAX_VEL/2);
  drive::Drive(1, -0.5);
  wait(900);
  drive::Drive(25, 0.5);
  ramp::Motor.moveAbsolute(0, MAX_VEL);
}

void skills(){
}

void onePoint(){
  intake::autonIntake(-MAX_VEL, true);
  wait(800);
  intake::autonIntake(MAX_VEL, true);
}

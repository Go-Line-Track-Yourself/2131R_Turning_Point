#include "main.h"

namespace drive{
  //drive variables
  const double CENTIMETER = 360 / (10.5 * 3.141592628);
  const int MAX_VEL = 150;
  const double RAMP_INT = 0.04;
  const double TOLERANCE = 0.08;
  const double TURN_VEL_PROP = 0.75;
  const double RECON_DIS = 10;
  int factor = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  bool rampDirection = true;
  float leftMotorPower = 0;
  float rightMotorPower = 0;
  float autonRightMotorPower = 0;
  float autonLeftMotorPower = 0;

  //method to average numbers
  double avg(double numOne, double numTwo){
    double sum = numOne + numTwo;
    double averageVal = sum / 2;
    return averageVal;
  }

   void initializeCoefficients(int target, int initial, int maximum, int final){
     a = ((final + initial - 2 * maximum ) - 2*sqrt((final - maximum) * (initial - maximum))) / pow(target, 2);
     b = ((final - initial)/ target - a * target) * (target);
     c = initial;
   }

   float quadraticRamping(float input){
     return a * pow(input, 2) + b * input + c;
   }

   //user control drive with ramping
    void tankDrive(){
      double leftJoyValue = ((-ellisonsController.getAnalog(okapi::ControllerAnalog::leftY)));
      double rightJoyValue = ((-ellisonsController.getAnalog(okapi::ControllerAnalog::rightY)));
       if(abs(rightJoyValue) < TOLERANCE) rightJoyValue = 0;
       if(abs(leftJoyValue) < TOLERANCE) leftJoyValue = 0;
       float targetLeft =leftJoyValue;
       float targetRight = rightJoyValue;
       if(targetLeft > leftMotorPower) leftMotorPower+=RAMP_INT;
       if(targetLeft < leftMotorPower) leftMotorPower-=RAMP_INT;
       if(targetRight > rightMotorPower) rightMotorPower+=RAMP_INT;
       if(targetRight < rightMotorPower) rightMotorPower-=RAMP_INT;
       if(abs(rightMotorPower-targetRight) < RAMP_INT) rightMotorPower = targetRight;
       if(abs(leftMotorPower-targetLeft) < RAMP_INT) leftMotorPower = targetLeft;
       if(!intake::BackButton.isPressed()){
       RightMotors.moveVelocity(rightJoyValue * MAX_VEL);
       LeftMotors.moveVelocity(leftJoyValue * MAX_VEL);
      }
      else if(intake::BackButton.isPressed()) Motors.moveVelocity(MAX_VEL / 5);
  }

    //autonomous drive function
     void Drive(double input, double pctVel){
       RightMotors.tarePosition();
       LeftMotors.tarePosition();
       double distance = input * CENTIMETER;
       while(abs(avg(RightBackMotor.getPosition(), LeftBackMotor.getPosition())) <= distance) {
          if(pctVel > autonLeftMotorPower) autonLeftMotorPower+=RAMP_INT;
          if(pctVel < autonLeftMotorPower) autonLeftMotorPower-=RAMP_INT;
          if(pctVel > autonRightMotorPower) autonRightMotorPower+=RAMP_INT;
          if(pctVel < autonRightMotorPower) autonRightMotorPower-=RAMP_INT;
          if(abs(autonRightMotorPower-pctVel) < RAMP_INT) autonRightMotorPower = pctVel;
          if(abs(autonLeftMotorPower-pctVel) < RAMP_INT) autonLeftMotorPower = pctVel;

          RightMotors.moveVelocity(autonRightMotorPower * MAX_VEL);
          LeftMotors.moveVelocity(autonLeftMotorPower * MAX_VEL);

       }
       pctVel = 0;
       while(autonLeftMotorPower != 0 && autonRightMotorPower != 0){
         if(pctVel > autonLeftMotorPower) autonLeftMotorPower+=RAMP_INT;
         if(pctVel < autonLeftMotorPower) autonLeftMotorPower-=RAMP_INT;
         if(pctVel > autonRightMotorPower) autonRightMotorPower+=RAMP_INT;
         if(pctVel < autonRightMotorPower) autonRightMotorPower-=RAMP_INT;
         if(abs(autonRightMotorPower-pctVel) < RAMP_INT) autonRightMotorPower = pctVel;
         if(abs(autonLeftMotorPower-pctVel) < RAMP_INT) autonLeftMotorPower = pctVel;

         RightMotors.moveVelocity(autonRightMotorPower * MAX_VEL);
         LeftMotors.moveVelocity(autonLeftMotorPower * MAX_VEL);
       }
      }

      //method to set velocity
      void turn(int rightPower, int leftPower){
        RightMotors.moveVelocity(rightPower);
        LeftMotors.moveVelocity(leftPower);
      }

      void Turn(double degrees){
          int leftVel = 50;
          int rightVel = 50;
          degrees = 360 *(degrees/12.56);
          RightMotors.tarePosition();
          LeftMotors.tarePosition();
          while(abs(RightMotors.getPosition()) < abs(degrees)){
            if(degrees <= 0){
              turn(-leftVel, rightVel);
            }
            else{
              turn(leftVel,-rightVel);
              pros::delay(5);
          }
        }
          turn(0,0);
          RightMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
          LeftMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
      }

      void recon(double time, double velocity){
          LeftMotors.tarePosition();
          RightMotors.tarePosition();

          Drive(RECON_DIS, velocity);
          pros::delay(time);
          RightMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
          LeftMotors.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
          Drive(0,0);
}
 }

#pragma once
#include <cmath>

/*class ramping{
  protected:
  float a;
  float b;
  float c;
};

void initializeCoefficients(quadraticRamping * ramp, float target, float initial, float maximum, float final){
  ramp a = ((final + initial - 2 * maximum ) - 2*sqrt((final - maximum) * (initial - maximum))) / pow(target, 2));
  ramp b = ((final - initial)/ target - ramp->a * target) * sgn(target);
  ramp c = intial;
}

float quadraticRamping(quadratic * ramp, float input){
  return ramp-> a * pow(input, 2) + ramp-> b* input + ramp-> c;
}*/


/*class ramping{

protected:
  double added = 1;
  double deltaTime = 5;
  double target =0;
  double current = 0;
  double max = 200;
  double min = 0;

  public:
    void linearRamp(){
      if(target > current) current += added;
      if(target < current) current -= added;
      if(current > max) current = max;
      if(current < -min) current = -max;

    }

    void setTarget(double input){
      this-> targetVal = input;
    }

    void setMaximum(double input){
      this-> maxVal = input;
    }

    void getTarget(){
      return this-> targetVal;
    }

    void getMaximum(){
      return this-> maxVal;
    }

    void getMinimum(){
      return this-> minVal;
    }*/
}

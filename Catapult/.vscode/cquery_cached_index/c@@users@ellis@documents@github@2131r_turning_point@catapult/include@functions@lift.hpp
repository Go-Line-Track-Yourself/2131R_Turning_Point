#ifndef LIFT_HPP
#define LIFT_HPP
#include "main.h"


namespace Lift{

void ManualLift();
void Flipper();
void LiftTransitions();

enum class Controller {MANUAL ,FLIPPER, OFF};

}


#endif /* end of include guard: LIFT_HPP */

#ifndef ROTATE_HPP
#define ROTATE_HPP

void Rotate()
{
    if (Ellisons_Controller.ButtonR2.pressing() && Rotateenabled == false) {
        Rotateenabled = true;
        Rotatepressed = !Rotatepressed;
    }
    if (!Ellisons_Controller.ButtonR2.pressing() && Rotateenabled == true) {
        Rotateenabled = false;
    }

    if (Rotatepressed)
    {
        RotateMotor.startRotateTo(290,vex::rotationUnits::deg, 100,vex::velocityUnits::pct);


    }
    if (!Rotatepressed)
    {
        RotateMotor.startRotateTo(80,vex::rotationUnits::deg, 100,vex::velocityUnits::pct);

    }

}


#endif /* end of include guard: ROTATE_HPP */

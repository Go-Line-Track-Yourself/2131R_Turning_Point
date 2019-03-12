#include "main.h"
#include "Functions/Feed.cpp"
#include "Functions/Drive.cpp"
#include "Functions/Puncher.cpp"
#include "Functions/Rotater.cpp"


 void opcontrol() {
	 while(true){

     //AutoFeed
     AutoFeed();

     //Puncher
     Puncher();

     //Rotater
     Rotater();

		 //drive
	  tankdrive( Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftY),
	             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightY),
	             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::rightX),
	             Ellisons_Controller.getAnalog(okapi::ControllerAnalog::leftX));


	pros::delay(20);
						}


 		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
 		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
 		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
 		//int left = 	Ellisons_Controller.getAnalog(ANALOG_LEFT_Y);
 	//	int right = Ellisons_Controller.getAnalog(ANALOG_RIGHT_Y);



		//LeftBackMotor = left;
		//RightBackMotor = right;

	}

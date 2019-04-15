#include "Functions/Drive.hpp"


namespace Drive{

void mechamdrive (int V1 =0, int V2 =0, int V3 =0, int V4=0){
  LeftFrontMotor.move_velocity(V1);
  LeftBackMotor.move_velocity(V2);
  RightFrontMotor.move_velocity(-V3);
  RightBackMotor.move_velocity(-V4);

}

void tankdrive (int j3, int j2, int j1, int j4){
  int Left = j3;
  int Right = j2;
  int Side = (j1+j4)/2; //average

if(std::abs(j1)>std::abs(j4))
{
		Side = j1;
}

else
{
		Side = j4;
}

mechamdrive(
		Left+Side,
		Left-Side,
		Right-Side,
		Right+Side);

}
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       nikolnotai                                                */
/*    Created:      4/28/2026, 1:39:29 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

#include "main/src.hpp"

using namespace vex;

competition Competition;

Src instance = Src();

void pre_auton(void)
{
  instance.setup();
}

void autonomous(void)
{
  instance.auton();
}

void usercontrol(void)
{
  while (1)
  {
    instance.driver();
    wait(20, msec);
  }
}

int main()
{
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true)
  {
    wait(100, msec);
  }
}

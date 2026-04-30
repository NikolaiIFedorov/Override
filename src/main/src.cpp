#include "src.hpp"

void velocityDrive()
{
    Controller *controller = Src::GetController();
    Drivetrain *drivetrain = Src::GetDrivetrain();
    drivetrain->velocity(controller->value(Action::axisRight));
}

void rotateDrive()
{
    Controller *controller = Src::GetController();
    Drivetrain *drivetrain = Src::GetDrivetrain();
    drivetrain->rotate(controller->value(Action::axisRight));
}

Src::Src()
{
    Init init = Code::init();

    controller = init.controller;
    controller->attachAxies(velocityDrive, rotateDrive);
    drivetrain = Drivetrain(init.driveMotors);
};

void Src::driver()
{
    instance.driverCode();
}

void Src::auton()
{
    instance.autonCode();
}

void Src::setup()
{
    instance.setupCode();
}

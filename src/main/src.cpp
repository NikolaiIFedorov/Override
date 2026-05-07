#include "src.hpp"

void velocityDrive()
{
    Controller *controller = Src::GetController();
    Drivetrain *drivetrain = Src::GetDrivetrain();
    drivetrain->SetVelocity(controller->value(Action::axisRight));
}

void rotateDrive()
{
    Controller *controller = Src::GetController();
    Drivetrain *drivetrain = Src::GetDrivetrain();
    drivetrain->SetRotate(controller->value(Action::axisRight));
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

void Src::log(std::string &msg, Log level)
{
    brain.log(msg, level);
    if (level == Log::Error)
        controller->log(msg);
}

void Src::logDisconnected(std::vector<uint8_t> disconnected)
{
    if (disconnected.empty())
        return;

    std::string msg = "Disconnected motors: ";
    for (auto &port : disconnected)
    {
        msg += (port - '0');
        if (&port != &disconnected.back())
            msg += ", ";
    }

    log(msg, Log::Error);
}

void Src::setup()
{
    std::vector<uint8_t> disconnected = Motors::getDisconnected();
    logDisconnected(disconnected);

    instance.setupCode();
}

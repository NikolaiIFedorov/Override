#include "controller.hpp"

void Controller::attachAxies(void (*leftAxis)(void), void (*rightAxis)(void))
{
    controller.Axis3.changed(leftAxis);
    controller.Axis3.changed(rightAxis);
}

float Controller::value(Action action)
{
    switch (action)
    {
    case Action::axisLeft:
        return controller.Axis3.value();
    case Action::axisRight:
        return controller.Axis1.value();
    }
};

void Controller::log(std::string &message)
{
    static bool init = false;
    if (!init)
    {
        logCount = 0;
        init = true;
    }

    if (logCount >= 3)
        logCount = 0;

    controller.rumble("..");
    controller.rumble(" ");

    controller.Screen.setCursor(1, logCount + 1);
    controller.Screen.print(message.c_str());

    logCount++;
}
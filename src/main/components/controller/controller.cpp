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
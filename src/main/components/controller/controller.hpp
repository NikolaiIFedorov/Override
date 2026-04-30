#pragma once

#include "vex.h"

#include "components/drivetain/drivetrain.hpp"

enum class Action
{
    axisLeft,
    axisRight
};

class Controller
{
public:
    Controller();

    void attachAxies(void (*leftAxis)(void), void (*rightAxis)(void));

    float value(Action action);

private:
    vex::controller controller = vex::controller(vex::controllerType::primary);
};
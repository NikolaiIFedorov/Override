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
    inline Controller &Controller::operator=(const Controller &)
    {
        return *this;
    }

    void attachAxies(void (*leftAxis)(void), void (*rightAxis)(void));

    float value(Action action);

    void log(std::string &message);

private:
    vex::controller controller = vex::controller(vex::controllerType::primary);

    static uint8_t logCount;
};
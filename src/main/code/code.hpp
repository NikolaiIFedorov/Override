#pragma once

#include "main/src.hpp"

#include "drivetain/drivetrain.hpp"
#include "controller/controller.hpp"

class Code
{
public:
    Code();

    void driverCode();
    void autonCode();
    void setupCode();

    static Init init();
};

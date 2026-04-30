#pragma once

#include "drivetain/drivetrain.hpp"
#include "controller/controller.hpp"
#include "code/code.hpp"

struct Init
{
    Controller *controller;
    Motors driveMotors;
};

class Src
{
public:
    Src();

    void driver();
    void auton();
    void setup();

    static Drivetrain *GetDrivetrain() { return &drivetrain; }
    static Controller *GetController() { return controller; }

private:
    Code instance;

    static Drivetrain drivetrain;
    static Controller *controller;
};

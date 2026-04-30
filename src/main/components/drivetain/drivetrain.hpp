#pragma once

#include "vector"

#include "motor/motor.hpp"

class Drivetrain
{
public:
    Drivetrain(Motors motors) : motors(motors) {};
    Drivetrain();

    Motors GetMotors() { return motors; }

    static void velocity(float tilt);
    static void rotate(float tilt);

private:
    Motors motors;
    static Drivetrain instance;
};

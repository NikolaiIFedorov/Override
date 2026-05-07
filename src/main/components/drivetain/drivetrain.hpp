#pragma once

#include "vector"

#include "motor/motor.hpp"

class Drivetrain
{
public:
    Drivetrain(Motors motors) : motors(motors) {};

    Motors GetMotors() { return motors; }

    void SetVelocity(float velocity);
    void SetRotate(float rotate);

private:
    Motors motors;
    float velocity = 0;
    float rotate = 0;

    void drive();
    void balance(float rightPct, float rightRpm, float leftPct, float leftRpm);
};

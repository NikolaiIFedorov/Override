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

    double x = 0;
    double y = 0;
    double r = 0;

    void drive();
    void balance(float rightPct, float rightRpm, float leftPct, float leftRpm);
    void updatePosition(float forward, float turn);

    std::chrono::steady_clock::time_point lastPositionUpdate = std::chrono::steady_clock::now();
};

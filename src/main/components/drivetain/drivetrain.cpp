#include "drivetrain.hpp"

void Drivetrain::SetVelocity(float velocity)
{
    velocity = velocity;
    drive();
};

void Drivetrain::SetRotate(float rotate)
{
    rotate = rotate;
    drive();
};

void Drivetrain::balance(float rightPct, float rightRpm, float leftPct, float leftRpm)
{
    if (rightPct == 0 || rightRpm == 0)
        return;

    float pctRatio = leftPct / rightPct;
    float rpmRatio = leftRpm / rightRpm;
    float unbalance = rpmRatio / pctRatio;

    if (unbalance > 1)
        motors.setRpmScalar(1 / unbalance, Motor::Type::Left);
    else if (unbalance < 1)
        motors.setRpmScalar(unbalance, Motor::Type::Right);
};

void Drivetrain::drive()
{
    float leftPct = velocity - rotate;
    float rightPct = velocity + rotate;

    float leftRpm = motors.spin(leftPct, Motor::Type::Left);
    float rightRpm = motors.spin(rightPct, Motor::Type::Right);

    balance(rightPct, rightRpm, leftPct, leftRpm);
};

#include "drivetrain.hpp"

void Drivetrain::velocity(float tilt)
{
    instance.GetMotors().spin(tilt);
};

void Drivetrain::rotate(float tilt)
{
    for (Motor &motor : instance.motors.GetMotors())
    {
        if (motor.GetType() == Motor::Type::Left)
            motor.spin(tilt);
        else if (motor.GetType() == Motor::Type::Right)
            motor.spin(-tilt);
    }
};
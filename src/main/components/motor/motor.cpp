#include "motor.hpp"

int32_t Motor::vexportFromPort(uint8_t port)
{
    switch (port)
    {
    case 1:
        return vex::PORT1;
    case 2:
        return vex::PORT2;
    case 3:
        return vex::PORT3;
    case 4:
        return vex::PORT4;
    case 5:
        return vex::PORT5;
    case 6:
        return vex::PORT6;
    case 7:
        return vex::PORT7;
    case 8:
        return vex::PORT8;
    case 9:
        return vex::PORT9;
    case 10:
        return vex::PORT10;
    case 11:
        return vex::PORT11;
    case 12:
        return vex::PORT12;
    case 13:
        return vex::PORT13;
    case 14:
        return vex::PORT14;
    case 15:
        return vex::PORT15;
    case 16:
        return vex::PORT16;
    case 17:
        return vex::PORT17;
    case 18:
        return vex::PORT18;
    case 19:
        return vex::PORT19;
    case 20:
        return vex::PORT20;
    case 21:
        return vex::PORT21;
    case 22:
        return vex::PORT22;
    default:
        // LOG ERROR
        return vex::PORT1;
    }
}

double Motor::spin(float pct)
{
    motor.spin(vex::directionType::fwd, pct * rpmScalar, vex::velocityUnits::pct);
    return getVelocity();
}

void Set::timeMotors(std::unordered_map<Motor *, float> &motorRpms)
{
    std::pair<Motor *, float> lowestRpm = {nullptr, std::numeric_limits<float>::max()};
    for (auto &motor : motors)
    {
        motorRpms[&motor] = motor.getVelocity();
        if (motorRpms[&motor] < lowestRpm.second && motorRpms[&motor] != 0)
            lowestRpm = {&motor, motorRpms[&motor]};
    }

    for (auto &motor : motors)
    {
        if (motorRpms[&motor] > lowestRpm.second && motorRpms[&motor] != 0)
            motor.SetRpmScalar(lowestRpm.second / motorRpms[&motor]);
    }
}

double Set::spin(float pct)
{
    double totalVelocity = 0;
    uint8_t motorCount = 0;

    std::unordered_map<Motor *, float> motorRpms;
    for (auto &motor : motors)
    {
        totalVelocity += motor.spin(pct * rpmScalar);
        motorCount++;

        motorRpms[&motor] = motor.getVelocity();
    }

    timeMotors(motorRpms);

    return totalVelocity / motorCount;
}

Motors::Motors(std::vector<Motor> motors) : sets({Set(motors)})
{
    allMotors.insert(allMotors.end(), motors.begin(), motors.end());
}

double Motors::spin(float pct, Motor::Type type)
{
    for (auto &set : sets)
    {
        if (set.GetType() == type)
            return set.spin(pct);
    }
}

void Motors::setRpmScalar(float scalar, Motor::Type type)
{
    for (auto &set : sets)
    {
        if (set.GetType() == type)
            set.SetRpmScalar(scalar);
    }
}

std::vector<uint8_t> Set::getDisconnected()
{
    std::vector<uint8_t> connections;
    for (auto &motor : motors)
        connections.push_back(motor.GetPort());

    return connections;
}

std::vector<uint8_t> Motors::getDisconnected()
{
    std::vector<uint8_t> connections;
    for (auto &motor : allMotors)
    {
        if (!motor->installed())
            connections.push_back(motor->GetPort());
    }
    return connections;
}

#pragma once

#include <vector>
#include <unordered_map>

#include "vex.h"

class Motor
{
public:
    enum class Type
    {
        Right,
        Left
    };
    Motor(uint8_t port, Type type, bool flipped = false) : motor(vexportFromPort(port), flipped), type(type), port(port) {};

    Type GetType() { return type; }

    void SetRpmScalar(float scalar) { rpmScalar = scalar; }

    uint8_t GetPort() { return port; }

    uint8_t installed() { return motor.installed(); }

    double spin(float pct);
    double getVelocity() { return motor.velocity(vex::velocityUnits::pct); }

private:
    vex::motor motor;
    Type type;
    uint8_t port;
    int32_t vexportFromPort(uint8_t port);

    float rpmScalar = 1.0;
};

class Set
{
public:
    Set(std::vector<Motor> motors) : motors(motors) {};

    Motor::Type GetType() { return motors[0].GetType(); }
    void SetRpmScalar(float scalar) { rpmScalar = scalar; };

    std::vector<uint8_t> getDisconnected();

    double spin(float pct);

private:
    std::vector<Motor> motors;

    float rpmScalar = 1.0f;

    void timeMotors(std::unordered_map<Motor *, float> &motorRpms);
};

class Motors
{
public:
    Motors(std::vector<Motor> motors);

    static std::vector<Motor *> GetAllMotors() { return allMotors; };

    void setRpmScalar(float scalar, Motor::Type type);

    static std::vector<uint8_t> getDisconnected();

    double spin(float pct, Motor::Type type);

private:
    std::vector<Set> sets;
    static std::vector<Motor *> allMotors;
};
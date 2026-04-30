#pragma once

#include "vex.h"

struct Motor
{
public:
    enum class Type
    {
        Right,
        Left
    };

    Motor(uint8_t port, Type type, bool flipped = false) : motor(vexportFromPort(port), flipped), type(type) {};
    Motor();

    Type GetType() { return type; }

    void spin(float pct);

private:
    vex::motor motor;
    Type type;
    uint32_t vexportFromPort(uint8_t port);
};

struct Motors
{
public:
    Motors(std::vector<Motor> motors) : motors(motors) {};
    Motors();

    std::vector<Motor> GetMotors() { return motors; }

    void spin(float pct);

private:
    std::vector<Motor> motors;
};
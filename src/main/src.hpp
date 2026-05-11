#pragma once

#include <vector>
#include <string>

#include "drivetain/drivetrain.hpp"
#include "controller/controller.hpp"
#include "brain/brain.hpp"
#include "code/code.hpp"

struct Init
{
    Controller *controller;
    Motors driveMotors;
};

enum class Log
{
    Disconnected,
    Info,
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
    static Brain brain;

    static void log(std::string &msg, Log level = Log::Info);
    static void logDisconnected(std::vector<uint8_t> connections);

    static void maintenence();
};

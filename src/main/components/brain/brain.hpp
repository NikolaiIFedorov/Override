#include "vex.h"
#include "src.hpp"

class Brain
{
public:
    static void log(std::string &message, Log level = Log::Info);

private:
    static vex::brain brain;

    static const uint8_t MAX_COL = 5;
    static const uint8_t ROW_STEP = 2;
    static const uint8_t ERROR_ROW = 1;
    static const uint8_t INFO_ROW = ERROR_ROW + ROW_STEP;
    static const uint8_t DEBUG_ROW = INFO_ROW + ROW_STEP;

    static uint8_t errorCount;
    static uint8_t infoCount;
    static uint8_t debugCount;
};
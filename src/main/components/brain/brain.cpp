#include "brain.hpp"

void Brain::log(std::string &message, Log level)
{
    static bool init = false;
    if (!init)
    {
        infoCount = 0;
        debugCount = 0;
        errorCount = 0;
        init = true;
    }

    switch (level)
    {
    case Log::Info:
        if (infoCount >= MAX_COL)
            infoCount = 0;

        brain.Screen.setCursor(INFO_ROW + infoCount, 1);
        brain.Screen.print(message);
        infoCount++;
        break;
    case Log::Debug:
        if (debugCount >= MAX_COL)
            debugCount = 0;

        brain.Screen.setCursor(DEBUG_ROW + debugCount, 1);
        brain.Screen.setPenColor(vex::color::blue);
        brain.Screen.print(message);
        debugCount++;
        break;
    case Log::Error:
        if (errorCount >= MAX_COL)
            errorCount = 0;

        brain.Screen.setCursor(ERROR_ROW + errorCount, 1);
        brain.Screen.setPenColor(vex::color::orange);
        brain.Screen.print(message);
        errorCount++;
        break;
    }
}
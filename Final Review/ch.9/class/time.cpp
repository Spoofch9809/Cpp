#include <iomanip>   // For setw and setfill stream manipulators
#include <stdexcept> // For invalid_argument exception class
#include <sstream>   // For ostringstream class
#include <string>
#include "time.h" // Include definition of class Time from Time.h
using namespace std;
// Set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
    // Validate hour, minute, and second
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
    {
        hour = h;
        minute = m;
        second = s;
    }
    else
    {
        throw invalid_argument("hour, minute and/or second was out of range");
    }
}
// Return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const
{
    ostringstream output;
    output << setfill('0') << setw(2) << hour << ":"
           << setw(2) << minute << ":" << setw(2) << second;
    return output.str(); // Returns the formatted string
}

// Return Time as a string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const
{
    ostringstream output;
    output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
           << setfill('0') << setw(2) << minute << ":"
           << setw(2) << second << (hour < 12 ? " AM" : " PM");
    return output.str(); // Returns the formatted string
}
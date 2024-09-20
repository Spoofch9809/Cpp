#include <iostream>
#include <string>
using namespace std;

#ifndef TIME_H // Prevent multiple inclusions
#define TIME_H

class Time
{
public:
    void setTime(int hour, int minute, int second); // Set hour, minute, and second
    string toUniversalString() const;          // Return 24-hour time format string
    string toStandardString() const;           // Return 12-hour time format string
private:
    unsigned int hour{0};   // 0 - 23 (24-hour clock format)
    unsigned int minute{0}; // 0 - 59
    unsigned int second{0}; // 0 - 59
};
#endif
#include <iostream>
#include <stdexcept> // For invalid_argument exception class
#include "time.h"    // Definition of class Time from Time.h

using namespace std;

// Displays a Time in 24-hour and 12-hour formats
void displayTime(const string &message, const Time &time)
{
    cout << message
         << "\nUniversal time: " << time.toUniversalString() // Corrected
         << "\nStandard time: " << time.toStandardString()   // Corrected
         << "\n\n";
}
int main()
{
    Time t;                           // Instantiate object t of class Time
    displayTime("Initial time:", t);  // Display t's initial value
    t.setTime(13, 27, 6);             // Change time
    displayTime("After setTime:", t); // Display t's new value
    // Attempt to set the time with invalid values
    try
    {
        t.setTime(99, 99, 99); // All values out of range
    }
    catch (invalid_argument &e)
    {
        cout << "Exception: " << e.what() << "\n\n";
    }
    // Display t's value after attempting to set an invalid time
    displayTime("After attempting to set an invalid time:", t);
    return 0; // Added return statement
}
#include <iostream>

using namespace std;

class HeartRateMonitor
{
private:
    string first, last;
    int yy, mm, dd;

public:
    HeartRateMonitor(string fname, string lname, int year, int month, int day) {
        first = fname;
        last = lname;
        yy = year;
        mm = month;
        dd = day;
    }
    void setFirstName(string fname) {
        first = fname;
    }

    void setLastName(string lname) {
        last = lname;
    }

    void setYear(int year) {
        yy = year;
    }

    void setMonth(int month) {
        mm = month;
    }

    void setDay(int day) {
        dd = day;
    }

    string getFirstName() {
        return first;
    }

    string getLastName() {
        return last;
    }

    int getYear() {
        return yy;
    }

    int getMonth() {
        return mm;
    }

    int getDay() {
        return dd;
    }

    int getAge() {
        int currentYear = 2023;
        int age = currentYear - yy;

        if (mm < 12 || (mm == 12 && dd < 28))
        {
            age--;
        }

        return age;
    }

    int getMaximumHeartRate() {
        return 220 - getAge();
    }

    int targetHeartRate1() {
        return getMaximumHeartRate() * 0.5;
    }

    int targetHeartRate2() {
        return getMaximumHeartRate() * 0.85;
    }

    void getTargetHeartRate() {
        cout << "Your target heart rate should be between " << targetHeartRate1() << " - " << targetHeartRate2() << " beats per minute." << endl;
    }

    void displayInformation() {
        cout << "Hello, " << getAge() << " years old " << getFirstName() << " " << getLastName() << "." << endl;
        cout << "Your maximum heart rate should be " << getMaximumHeartRate() << " beats per minute." << endl;
        getTargetHeartRate();
    }
};

int main()
{
    string fname, lname;
    int year, month, day;

    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    cout << "Enter your birth year (YYYY): ";
    cin >> year;
    cout << "Enter your birth month (MM): ";
    cin >> month;
    cout << "Enter your birth day (DD): ";
    cin >> day;
    cout << endl;

    HeartRateMonitor program(fname, lname, year, month, day);
    program.displayInformation();
}
#include <iostream>
#include <string>

using namespace std;

class TemperatureConverter {
private:
    float fahrenheit, celsius;
public:
    float cel2fah(float temp) {
        fahrenheit = temp;
        celsius = (fahrenheit - 32) * 5.0/9.0;
        return celsius;
    }

    float fah2cel(float temp) {
        celsius = temp;
        fahrenheit = ( 1.8 * temp) + 32;
        return fahrenheit;
    }
};

int main() {
    TemperatureConverter t;
    float temp;
    char option;
    while (true) 
    {
        cout<<"Enter temperature: ";
        cin>>temp;
        cout<<"Convert to (C)elsius or (F)ahrenheit? Enter C or F: ";
        cin >> option;
        if (option == 'C' || option == 'c')
        {
            cout<<""<<temp<<" Fahrenheit is "<<""<<t.fah2cel(temp)<<endl;
        }
        else if (option == 'F' || option == 'f')
        {
            cout<<""<<temp<<" Celsius is "<<""<<t.cel2fah(temp)<<endl;
        }
        else
            cout<<"Error Wrong Input."<<endl;

        cout<<"Do you want to perform another conversion? (Y/N): ";
        cin>>option;
        if (option == 'Y' || option == 'y')
        {
            continue;
        }
        else if (option == 'N' || option == 'n')
        {
            break;
        }
    }

    return 0;
}
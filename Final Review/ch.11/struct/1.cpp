#include <iostream>
#include <string>

using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};
Book myBook;
struct
{                    // Structure declaration
    int myNum;       // Member (int variable)
    string myString; // Member (string variable)
} myStructure;       // Structure variable

struct
{
    string brand;
    string model;
    int year;
} myCar1, myCar2;

int main()
{
    myBook.title = "C++ Primer";
    myBook.author = "Stanley B. Lippman";
    myBook.year = 2012;

    myStructure.myNum = 15;
    myStructure.myString = "No. ";

    myCar1.brand = "Ford";
    myCar1.model = "Mustang";
    myCar1.year = 1969;
    
    myCar2.brand = "Chevy";
    myCar2.model = "Camaro";
    myCar2.year = 1967;

    cout << "Book: " << myBook.title << ", Author: " << myBook.author << ", Year: " << myBook.year;
    cout << "\nStructure: " << myStructure.myString << myStructure.myNum;
    cout << "\nCar 1: " << myCar1.brand << " " << myCar1.model << " " << myCar1.year;
    cout << "\nCar 2: " << myCar2.brand << " " << myCar2.model << " " << myCar2.year;
}
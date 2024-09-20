// Get() in string line

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    string line;

    if (!inFile)
    {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    while (getline(inFile, line))
    {                  
        cout << line << endl; // Output the character
    }
    inFile.close();
    return 0;
}
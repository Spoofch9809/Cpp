// Get()

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    char ch;

    if (!inFile)
    {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    while (inFile.get(ch))
    {                    // Reads one character at a time
        cout << ch << endl; // Output the character
    }
    inFile.close();
    return 0;
}
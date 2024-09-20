// put()

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream outFile("output.txt");
    if (!outFile)
    {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }
    // Writing individual characters to the file
    outFile.put('H').put('e').put('l').put('l').put('o').put('\n');
    outFile.close();
    return 0;
}
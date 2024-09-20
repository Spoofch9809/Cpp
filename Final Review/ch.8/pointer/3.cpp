#include <iostream>
using namespace std;

void cubeByValue(int* nptr) 
{
    *nptr = *nptr * *nptr * *nptr;
}

int main()
{
    int num{5};
    cubeByValue(&num);
    cout << num << endl; // Output: 125
}

#include <iostream>
using namespace std;

void increment(int *ptr)
{
    if (ptr != nullptr) *ptr +=1; // increment if ptr is not a null pointer
}
int main()
{
    int x = 5;
    increment(&x);
    cout << x << endl; // Output: 6
}
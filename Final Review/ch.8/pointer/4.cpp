#include <iostream>
using namespace std;

int main() 
{
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr1 = &arr[0]; // Pointer to first element
    int* ptr2 = &arr[4]; // Pointer to fifth element

    ptrdiff_t diff = ptr2 - ptr1;
    cout << "The pointers are " << diff - 1 << " elements apart." << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr1 = &arr[0];
    int* ptr2 = &arr[0]; 
    int* ptr3 = &arr[2]; 

    if (ptr1 == ptr2){
        cout << "ptr1 and ptr2 are pointing to the same location." << endl;
    } 
    if (ptr1 != ptr3) {
        cout << "ptr1 and ptr3 are not pointing to the same location." << endl;
    }
}
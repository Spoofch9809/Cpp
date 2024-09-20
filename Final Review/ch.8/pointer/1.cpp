#include <iostream>

using namespace std;

int main() {
    int value = 5;
    int* ptr1 = &value;
    int* ptr2 = ptr1; // ptr2 is now pointing to the same location as ptr1

    cout << "Value of *ptr2: " << *ptr2 << endl;

    return 0;
}

// #include <iostream>

// int main() {
// int value = 5;
// void* ptr = &value;

// // std::cout << *ptr << std::endl; // Error: cannot dereference a void pointer

// // Correct way: Cast void* to int* before dereferencing
// std::cout << "Value of *ptr: " << *(static_cast<int*>(ptr)) << std::endl;

// return 0;
// }
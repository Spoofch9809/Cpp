// This program defines a recursive function mystery that calculates the product 
// of two integers using recursion. The program takes two integers as input from 
// the user, and then it calls the mystery function to calculate and display the result.

// Problem -> The error handling seems to be lacking. If the user enters a non-integer,
// the program will crash.
// Solution -> change the base case and the recursive call to multiplication.

// #include <iostream>
// using namespace std;

// int mystery(int a, int b);

// int main() {
//     int x, y;

//     cout << "Enter two integers: ";
    
//     if (!(cin >> x >> y) || cin.fail()) {
//         cout << "Error: Please enter valid integers." << endl;
//         return 1;
//     }

//     cout << "The result is " << mystery(x, y) << endl;

//     return 0;
// }

// int mystery(int a, int b) {
//     if (a == 0 || b == 0) { // Base case
//         return 0;
//     } else if (b == 1) {
//         return a; // Base case
//     } else if (a == 1) {
//         return b; // Base case
//     } else if (b < 0){
//         return -a + mystery(a, b + 1); // Recursion step
//     } else {
//         return a + mystery(a, b - 1); // Recursion step
//     }
// }
#include <iostream>
#include <limits>
using namespace std;

int mystery(int, int);

int main() {
    int x = 0;
    int y = 0;

    cout << "Enter two integers: ";
    while (!(cin >> x >> y) || y < 0) {
        cout << "Invalid input. Please enter two integers, and make sure the second integer is non-negative: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "The result is " << mystery(x, y) << endl;
    return 0;
}

int mystery(int a, int b) {
    if (b == 0) { 
        return 0;
    } else if (b == 1) {
        return a;
    } else { 
        return a + mystery(a, b - 1);
    }
}
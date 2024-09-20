#include <iostream>
#include <string>
using namespace std;

void reverseString(string& str, int start, int end) {
    if (start < end) {
        swap(str[start], str[end]);
        reverseString(str, start + 1, end - 1);
    }
}

int main() {
    string userInput;

    cout << "Enter a string: ";
    getline(cin, userInput);

    if (userInput.empty()) {
        cerr << "Error: Empty input. Please enter a valid string." << endl;
        return 1; // Return an error code
    }

    reverseString(userInput, 0, userInput.length() - 1);

    cout << "Reversed string: " << userInput << endl;

    return 0;
}

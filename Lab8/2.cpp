#include <iostream>
using namespace std;

int mystery3(const char *, int &length, int &vowel);
string reverseString(const char *, size_t index = 0);

int main() {
    char string1[80];
    // Declare a character array to store the input string.

    cout << "Enter a string: ";
    cin.getline(string1, 80);

    if (cin.fail()) { 
        cout << "Input error or insufficient space for concatenation" << endl;
        return 0;
        // Return 0 to indicate successful execution.
    }

    int length, vowel;
    // Declare variables to store the length and vowel count of the string.
    mystery3(string1, length, vowel);

    cout << "Length of the string: " << length + 1 << ", Vowels: " << vowel << endl;

    string reversed = reverseString(string1, length);
    // Call the reverseString function to reverse the input string.

    cout << "Reverse: " << reversed << endl;
    return 0;
}

int mystery3(const char *s, int &length, int &vowel) {
    length = 0;
    vowel = 0;
    // Initialize variables for length and vowel count.

    while (*s != '\0')
    {
        // Loop through each character in the string until the null terminator is encountered.
        length++;
        // Increment the length for each character.
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
            vowel++;
        // Increment the vowel count if the current character is a vowel.
        s++;
        // Move to the next character in the string.
    }

    return length;
    // Return the final length of the string.
}

string reverseString(const char *s, size_t index)
{
    if (index == 0)
    {
        return "";
        // Base case: if the index is 0, return an empty string.
    }
    else
    {
        return s[index - 1] + reverseString(s, index - 1);
        // Recursively call reverseString with the index decremented, appending the current character.
    }
}

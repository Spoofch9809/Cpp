#include <iostream>
#include <cstring> // to use strlen
using namespace std;

void mystery1(char *, const char *);
bool mystery2(char *, const char *);

int main()
{
    char string1[80];
    char string2[80];
    cout << "case 1 Normal concat: Enter two strings: ";
    cin >> string1 >> string2; 
    mystery1(string1, string2);
    cout << "Concatenated String: " << string1 << endl;

    cout << "case 2 overflow: Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);

    cout << "case 3 Substring check: Enter two strings: ";
    cin >> string1 >> string2;
    mystery2(string1, string2);
    if (mystery2(string1, string2)) {
        cout << "Is string2 a substring of string? Yes" << endl;
    } else {
        cout << "Is string2 a substring of string? No" << endl;
    }

    cout << "case 4 non substring check: Enter two strings: ";
    cin >> string1 >> string2;
    mystery2(string1, string2);
    if (mystery2(string1, string2)) {
        cout << "Is string2 a substring of string? Yes" << endl;
    } else {
        cout << "Is string2 a substring of string? No" << endl;
    }
} // end main
void mystery1(char *s1, const char *s2)
{
    size_t s1Length = strlen(s1);
    size_t s2Length = strlen(s2);

    if (s1Length + s2Length < 80)
    {
        while (*s1 != '\0') // find end of string s1
            ++s1;           // move s1 to point to the next character

        for (; (*s1 = *s2); ++s1, ++s2)
            ; // copy s2 to s1
    }
    else
    {
        cout << "Error: Insufficient space for concatenate." << endl;
    }
}

bool mystery2(char *s1, const char *s2)
{
    while (*s1 != '\0')
    {
        if (*s1 == *s2)
        {
            char *temp = s1;
            while (*temp == *s2)
            {
                temp++;
                s2++;
                if (*s2 == '\0')
                    return true;
            }
            s2 -= temp - s1;
        }
        s1++;
    }
    return false;
}
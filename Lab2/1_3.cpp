#include <iostream>
#include <string>

using namespace std;

const int pad = 1;
const int rows = pad * 2 + 3;

int main() {
    cout << "Please enter P1 name: ";
    string p1Name;
    getline(cin, p1Name);

    cout << "Please enter P2 name: ";
    string p2Name;
    cin >> p2Name;

    const string greeting = "Player 1:" + p1Name + " * " + "Player 2:" + p2Name;
    const string greeting1  = "Player 1:" + p1Name;
    const int cols = greeting.size() + pad * 2 + 2;
    const int cols1 = greeting1.size() + pad * 2 + 2;

    cout << endl;

    for (int r = 0; r != rows; ++r) {
        int c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1 || c == cols1 - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }

    return 0;
}
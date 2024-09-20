#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    if (cin.fail()) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<int> array;

    cout << "Enter the number: ";
    int numbers;
    for (int i = 0; i < n; i++) {
        cin >> numbers;
        if (cin.fail()) {
            cout << "Invalid input!" << endl;
            return 0;
        }
        array.push_back(numbers);
    }
    cout << endl;
    
    int min = array[0];
    for (int i = 0; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    cout << "The minimum number is: " << min << endl;
    return 0;
}


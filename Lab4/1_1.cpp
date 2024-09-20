#include <iostream>
#include <vector>

using namespace std;

void lshift(vector<int> &Num, int n) {
    if (n >= 0 && n < Num.size()) {
        Num.erase(Num.begin(), Num.begin() + n);
    } else {
        cout << "Invalid" << endl;
    }
}

void rshift(vector<int> &Num, int n) {
    if (n >= 0) {
        Num.insert(Num.begin(), n, 0);
    } else {
        cout << "Invalid" << endl;
    }
}

int main() {
    vector<int> Num {1,2,3,4,5};

    cout << "Original sequence: "; 
    for (int num : Num) {
        cout << num << " "; 
    }
    cout << endl;
    lshift(Num, 2);
    cout << "After lshift by 2: ";
    for (int num:Num) {
        cout << num << " ";
    }
    cout << endl;
    rshift(Num, 3);
    cout << "After rshift by 3: ";
    for (int num:Num) {
        cout << num << " ";
    }
    cout << endl;
}

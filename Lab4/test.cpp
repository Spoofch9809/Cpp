#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector {1,2,3};

    myVector.push_back(12);
    myVector.push_back(22);
    myVector.push_back(32);

    for (int i=0; i < myVector.size(); ++i) {
        cout << myVector[i] << ' ';
    }
    cout << "\n";
    for (int element : myVector) {
        cout << element << ' ';
    }
    cout << endl;
}

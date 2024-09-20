#include <iostream>
#include <vector>

using namespace std;

void remove_negative(vector<double> &vec) {
    for (int i= vec.size() - 1; i < vec.size(); --i){
        if (vec[i] < 0) {
            vec.erase(vec.begin() + i);
        }
    }

}

int main() {
    vector<double> vec {-0.8, -5.1, 1.6, -6.5, 10.5};

    cout << "Original vector: "; 
    for (double num : vec) {
        cout << num << " "; 
    }
    cout << endl;

    remove_negative(vec);
    cout << "Vector after removing negative numbers: ";
    for (double num:vec) {
        cout << num << " ";
    }
    cout << endl;
}

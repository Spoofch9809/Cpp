#include <iostream>
#include <list>

using namespace std;

void remove_negative(list<double> &mylist) {
    // mylist.remove_if([](double n) { return n < 0; });
    for (auto it = mylist.begin(); it != mylist.end(); ++it) {
        if (*it < 0) {
            it = mylist.erase(it);
        }
    }
}

int main() {
    list<double> mylist = {0.8, -5.1, 1.6, -6.5, 10.5};

    cout << "Original list: "; 
    for (double num : mylist) {
        cout << num << " "; 
    }
    cout << "\n";

    remove_negative(mylist);
    cout << "List after removing negative numbers: ";
    for (double num:mylist) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// void remove_negative(list<double> &mylist) {
//     // mylist.remove_if([](double n) { return n < 0; });
//     list<double>::iterator it = mylist.begin(); 
//     while (it != mylist.end()) {
//         if (*it < 0){
//             it = mylist.erase(it);
//         } else {
//             ++it;
//         }
//     }
// }

// int main() {
//     list<double> mylist = {0.8, -5.1, 1.6, -6.5, 10.5};

//     cout << "Original list: "; 
//     for (double num : mylist) {
//         cout << num << " "; 
//     }
//     cout << "\n";

//     mylist.remove_if([](double n) { return n < 0; });

//     cout << "List after removing negative numbers: ";
//     for (double num:mylist) {
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }

// array class template
#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() 
{
    array<int, 5> n{5, 5, 5, 5, 5};

    cout << "Element" << setw(13) << "Value" << endl;

    // output each array element's value
    for (size_t j = 0; j < n.size(); ++j) {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    return 0;
}

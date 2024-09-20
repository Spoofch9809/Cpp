#include <iostream>
using namespace std;

int main()
{
    std::cout << "Please enter P1 name: ";
    std::string p1_name;
    std::cin >> p1_name;

    std::cout << "Please enter P2 name: ";
    std::string p2_name;
    std::cin >> p2_name;

    // `p1_name` and `p2_name` doesn't exist here!
    std::cout << "Player 1: " << p1_name << std::endl;
    std::cout << "Player 2: " << p2_name << std::endl;
    return 0;
}
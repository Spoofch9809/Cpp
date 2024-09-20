#include <iostream>
#include <string>

int num;

int main() {
    std::cout << "Plese enter a number: ";
    std::cin >> num;
    std::cin.ignore();

    std::string text;
    std::cout << "Enter a sentence: ";
    getline (std::cin, text);

    std::cout << "Number input is: " << num << std::endl;
    std::cout << "The sentence input was " << text << std::endl;

    return 0;
}

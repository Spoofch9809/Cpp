#include <iostream>

class Complex
{
public:
    double real, imag, extra;
    Complex(double real = 0.0, double imag = 0.0, double extra = 0.0) : real(real), imag(imag), extra(extra) {}
    
    // Update the operator+ function to add two Complex objects element-wise
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag, extra + other.extra);
    }
    
    // Friend function for output formatting
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << "[" << c.real << ", " << c.imag << ", " << c.extra << "]";
        return os;
    }
};

int main()
{
    Complex c1(2, 3, 4);
    Complex c2(6, 7, 8);
    Complex c3 = c1 + c2;                   // Using overloaded + operator

    // Update the initialization of c2 and c3
    c2 = Complex(6, 7);
    c3 = c1 + c2;

    std::cout << "c1: " << c1 << std::endl; // Printing using friend function
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    
    return 0;
}

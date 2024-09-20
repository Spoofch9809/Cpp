#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

    void simplify()
    {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    Fraction operator+(const Fraction &other) const
    {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction &other) const
    {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction &other) const
    {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction &other) const
    {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    friend istream &operator>>(istream &is, Fraction &f)
    {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        f.simplify();
        return is;
    }

    friend ostream &operator<<(ostream &os, const Fraction &f)
    {
        if (f.denominator < 0)
        {
            os << "-" << abs(f.numerator) << "/" << abs(f.denominator);
        }
        else
        {
            os << f.numerator << "/" << f.denominator;
        }
        return os;
    }
};

int main()
{
    Fraction f1, f2;
    cout << "Enter the first fraction (numerator/denominator): ";
    cin >> f1;
    cout << "Enter the second fraction (numerator/denominator): ";
    cin >> f2;

    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f1 + f2: " << f1 + f2 << endl;
    cout << "f1 - f2: " << f1 - f2 << endl;
    cout << "f1 * f2: " << f1 * f2 << endl;
    cout << "f1 / f2: " << f1 / f2 << endl;

    return 0;
}
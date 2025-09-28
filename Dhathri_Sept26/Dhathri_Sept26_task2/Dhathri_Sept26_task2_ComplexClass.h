#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double = 0.0, double = 0.0);

    // Arithmetic operators
    Complex operator+(const Complex &right) const;
    Complex operator-(const Complex &right) const;
    Complex operator*(const Complex &right) const;

    // Comparison operators
    bool operator==(const Complex &right) const;
    bool operator!=(const Complex &right) const;

    // Stream operators (friend, non-member)
    friend std::ostream &operator<<(std::ostream &out, const Complex &c);
    friend std::istream &operator>>(std::istream &in, Complex &c);
};

#endif

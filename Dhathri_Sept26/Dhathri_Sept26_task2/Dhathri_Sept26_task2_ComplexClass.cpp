#include "Dhathri_Sept26_task2_ComplexClass.h"

// Constructor
Complex::Complex(double r, double i) : real(r), imaginary(i) {}

// Addition
Complex Complex::operator+(const Complex &right) const {
    return Complex(real + right.real, imaginary + right.imaginary);
}

// Subtraction
Complex Complex::operator-(const Complex &right) const {
    return Complex(real - right.real, imaginary - right.imaginary);
}

// Multiplication
Complex Complex::operator*(const Complex &right) const {
    return Complex(real * right.real - imaginary * right.imaginary,
                   real * right.imaginary + imaginary * right.real);
}

// Equality
bool Complex::operator==(const Complex &right) const {
    return (real == right.real) && (imaginary == right.imaginary);
}

// Inequality
bool Complex::operator!=(const Complex &right) const {
    return !(*this == right);
}

// Output operator
std::ostream &operator<<(std::ostream &out, const Complex &c) {
    out << "(" << c.real << ", " << c.imaginary << ")";
    return out;
}

// Input operator
std::istream &operator>>(std::istream &in, Complex &c) {
    std::cout << "Enter real part: ";
    in >> c.real;
    std::cout << "Enter imaginary part: ";
    in >> c.imaginary;
    return in;
}

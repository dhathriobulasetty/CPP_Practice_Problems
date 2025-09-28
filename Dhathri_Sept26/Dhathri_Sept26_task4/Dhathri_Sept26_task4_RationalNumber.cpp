#include "Dhathri_Sept26_task4_RationalNumber.h"
#include <stdexcept>

// Constructor
RationalNumber::RationalNumber(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    reduce();
}

// GCD 
int RationalNumber::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a < 0) ? -a : a; // ensure positive gcd
}

// Reduce fraction
void RationalNumber::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

// Arithmetic operators
RationalNumber RationalNumber::operator+(const RationalNumber& right) const {
    int n = numerator * right.denominator + right.numerator * denominator;
    int d = denominator * right.denominator;
    return RationalNumber(n, d);
}

RationalNumber RationalNumber::operator-(const RationalNumber& right) const {
    int n = numerator * right.denominator - right.numerator * denominator;
    int d = denominator * right.denominator;
    return RationalNumber(n, d);
}

RationalNumber RationalNumber::operator*(const RationalNumber& right) const {
    int n = numerator * right.numerator;
    int d = denominator * right.denominator;
    return RationalNumber(n, d);
}

RationalNumber RationalNumber::operator/(const RationalNumber& right) const {
    if (right.numerator == 0) {
        throw std::invalid_argument("Division by zero fraction.");
    }
    int n = numerator * right.denominator;
    int d = denominator * right.numerator;
    return RationalNumber(n, d);
}

// Relational operators
bool RationalNumber::operator==(const RationalNumber& right) const {
    return (numerator == right.numerator && denominator == right.denominator);
}

bool RationalNumber::operator!=(const RationalNumber& right) const {
    return !(*this == right);
}

bool RationalNumber::operator<(const RationalNumber& right) const {
    return (numerator * right.denominator < right.numerator * denominator);
}

bool RationalNumber::operator<=(const RationalNumber& right) const {
    return (*this < right || *this == right);
}

bool RationalNumber::operator>(const RationalNumber& right) const {
    return !(*this <= right);
}

bool RationalNumber::operator>=(const RationalNumber& right) const {
    return !(*this < right);
}

// I/O operators
std::ostream& operator<<(std::ostream& out, const RationalNumber& r) {
    if (r.denominator == 1) {
        out << r.numerator;
    } else {
        out << r.numerator << "/" << r.denominator;
    }
    return out;
}

std::istream& operator>>(std::istream& in, RationalNumber& r) {
    int n, d;
    char slash;
    in >> n >> slash >> d;
    if (slash != '/') {
        in.setstate(std::ios::failbit);
        return in;
    }
    if (d == 0) {
        in.setstate(std::ios::failbit);
        return in;
    }
    r = RationalNumber(n, d);
    return in;
}

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber {
public:
    RationalNumber(int n = 0, int d = 1);  // constructor with default values

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber& right) const;
    RationalNumber operator-(const RationalNumber& right) const;
    RationalNumber operator*(const RationalNumber& right) const;
    RationalNumber operator/(const RationalNumber& right) const;

    // Relational operators
    bool operator==(const RationalNumber& right) const;
    bool operator!=(const RationalNumber& right) const;
    bool operator<(const RationalNumber& right) const;
    bool operator<=(const RationalNumber& right) const;
    bool operator>(const RationalNumber& right) const;
    bool operator>=(const RationalNumber& right) const;

    // I/O operators
    friend std::ostream& operator<<(std::ostream& out, const RationalNumber& r);
    friend std::istream& operator>>(std::istream& in, RationalNumber& r);

private:
    int numerator;
    int denominator;

    void reduce();        // reduces fraction to simplest form
    static int gcd(int a, int b); // greatest common divisor helper
};

#endif

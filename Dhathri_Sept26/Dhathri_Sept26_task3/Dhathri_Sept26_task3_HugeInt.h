#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>

class HugeInt {
    friend std::ostream &operator<<(std::ostream &, const HugeInt &);

public:
    static const int digits = 30; // maximum digits in a HugeInt

    HugeInt(long = 0);             // conversion/default constructor
    HugeInt(const std::string &);  // conversion constructor

    // Addition
    HugeInt operator+(const HugeInt &) const;
    HugeInt operator+(int) const;
    HugeInt operator+(const std::string &) const;
    
    // Subtraction
    HugeInt operator-(const HugeInt &) const;  

    // Multiplication and Division
    HugeInt operator*(const HugeInt &) const;
    HugeInt operator/(const HugeInt &) const; // integer division

    // Relational and Equality operators
    bool operator==(const HugeInt &) const;
    bool operator!=(const HugeInt &) const;
    bool operator<(const HugeInt &) const;
    bool operator<=(const HugeInt &) const;
    bool operator>(const HugeInt &) const;
    bool operator>=(const HugeInt &) const;

private:
    short integer[digits];
};

#endif

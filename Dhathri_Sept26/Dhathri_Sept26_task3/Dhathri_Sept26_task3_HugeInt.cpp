#include "Dhathri_Sept26_task3_HugeInt.h"

// Constructor from long
HugeInt::HugeInt(long value) {
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    for (int j = digits - 1; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

// Constructor from string
HugeInt::HugeInt(const std::string &number) {
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    int length = number.size();

    for (int j = digits - length, k = 0; j < digits; j++, k++) {
        if (isdigit(number[k]))
            integer[j] = number[k] - '0';
    }
}

// Addition HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &op2) const {
    HugeInt temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10;
            carry = 1;
        } else
            carry = 0;
    }
    return temp;
}

// Addition HugeInt + int
HugeInt HugeInt::operator+(int op2) const {
    return *this + HugeInt(op2);
}

// Addition HugeInt + string
HugeInt HugeInt::operator+(const std::string &op2) const {
    return *this + HugeInt(op2);
}

// Subtraction HugeInt - HugeInt
HugeInt HugeInt::operator-(const HugeInt &right) const {
    HugeInt result;
    HugeInt tempLeft(*this);   // copy of left operand
    HugeInt tempRight(right);  // copy of right operand

    int borrow = 0;
    for (int i = digits - 1; i >= 0; --i) {
        int diff = tempLeft.integer[i] - tempRight.integer[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.integer[i] = diff;
    }

    return result;
}

// Multiplication HugeInt * HugeInt
HugeInt HugeInt::operator*(const HugeInt &op2) const {
    HugeInt result;

    for (int i = digits - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = digits - 1, k = digits - 1 - (digits - 1 - i); j >= 0 && k >= 0; j--, k--) {
            int prod = integer[i] * op2.integer[j] + result.integer[k] + carry;
            result.integer[k] = prod % 10;
            carry = prod / 10;
        }
    }
    return result;
}

// Division HugeInt / HugeInt (simple long division approach)
HugeInt HugeInt::operator/(const HugeInt &divisor) const {
    HugeInt quotient(0);
    HugeInt remainder(0);

    for (int i = 0; i < digits; i++) {
        // Shift remainder left by one digit
        for (int j = 0; j < digits - 1; j++)
            remainder.integer[j] = remainder.integer[j + 1];
        remainder.integer[digits - 1] = integer[i];

        // Find how many times divisor fits
        int count = 0;
        while (!(remainder < divisor)) {
            remainder = remainder - divisor;
            count++;
        }
        quotient.integer[i] = count;
    }
    return quotient;
}

// Equality
bool HugeInt::operator==(const HugeInt &right) const {
    for (int i = 0; i < digits; i++)
        if (integer[i] != right.integer[i])
            return false;
    return true;
}

// Inequality
bool HugeInt::operator!=(const HugeInt &right) const {
    return !(*this == right);
}

// Less than
bool HugeInt::operator<(const HugeInt &right) const {
    for (int i = 0; i < digits; i++) {
        if (integer[i] < right.integer[i]) return true;
        if (integer[i] > right.integer[i]) return false;
    }
    return false;
}

// Less than or equal
bool HugeInt::operator<=(const HugeInt &right) const {
    return (*this < right) || (*this == right);
}

// Greater than
bool HugeInt::operator>(const HugeInt &right) const {
    return !(*this <= right);
}

// Greater than or equal
bool HugeInt::operator>=(const HugeInt &right) const {
    return !(*this < right);
}

// Output operator
std::ostream &operator<<(std::ostream &output, const HugeInt &num) {
    int i;
    for (i = 0; (num.integer[i] == 0) && (i < HugeInt::digits - 1); i++)
        ; // skip leading zeros

    for (; i < HugeInt::digits; i++)
        output << num.integer[i];

    return output;
}

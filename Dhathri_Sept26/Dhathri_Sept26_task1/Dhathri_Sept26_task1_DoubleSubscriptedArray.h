#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>

class DoubleSubscriptedArray {
    friend std::ostream &operator<<(std::ostream &, const DoubleSubscriptedArray &);
    friend std::istream &operator>>(std::istream &, DoubleSubscriptedArray &);

public:
    DoubleSubscriptedArray(int rows = 3, int cols = 3); // default constructor
    DoubleSubscriptedArray(const DoubleSubscriptedArray &); // copy constructor
    ~DoubleSubscriptedArray(); // destructor

    int getRows() const;
    int getCols() const;

    const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &); // assignment
    bool operator==(const DoubleSubscriptedArray &) const; // equality
    bool operator!=(const DoubleSubscriptedArray &right) const {
        return !(*this == right);
    }

    // operator() for accessing elements
    int &operator()(int row, int col);             // non-const
    const int &operator()(int row, int col) const; // const

private:
    int rows;
    int cols;
    int *ptr; // 1D dynamic array
};

#endif

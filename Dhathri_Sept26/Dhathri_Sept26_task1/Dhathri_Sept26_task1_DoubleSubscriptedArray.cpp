#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Dhathri_Sept26_task1_DoubleSubscriptedArray.h"

// constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c)
    : rows(r > 0 ? r : 3), cols(c > 0 ? c : 3) {
    ptr = new int[rows * cols];
    for (int i = 0; i < rows * cols; ++i)
        ptr[i] = 0;
}

// copy constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray &other)
    : rows(other.rows), cols(other.cols) {
    ptr = new int[rows * cols];
    for (int i = 0; i < rows * cols; ++i)
        ptr[i] = other.ptr[i];
}

// destructor
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] ptr;
}

// getters
int DoubleSubscriptedArray::getRows() const { return rows; }
int DoubleSubscriptedArray::getCols() const { return cols; }

// assignment operator
const DoubleSubscriptedArray &
DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &right) {
    if (this != &right) {
        if (rows * cols != right.rows * right.cols) {
            delete[] ptr;
            rows = right.rows;
            cols = right.cols;
            ptr = new int[rows * cols];
        }
        for (int i = 0; i < rows * cols; ++i)
            ptr[i] = right.ptr[i];
    }
    return *this;
}

// equality operator
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &right) const {
    if (rows != right.rows || cols != right.cols)
        return false;
    for (int i = 0; i < rows * cols; ++i)
        if (ptr[i] != right.ptr[i])
            return false;
    return true;
}

// operator() non-const
int &DoubleSubscriptedArray::operator()(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        std::cerr << "Error: Subscript (" << row << "," << col << ") out of range\n";
        std::exit(1);
    }
    return ptr[row * cols + col];
}

// operator() const
const int &DoubleSubscriptedArray::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        std::cerr << "Error: Subscript (" << row << "," << col << ") out of range\n";
        std::exit(1);
    }
    return ptr[row * cols + col];
}

// input operator
std::istream &operator>>(std::istream &input, DoubleSubscriptedArray &a) {
    for (int i = 0; i < a.rows * a.cols; ++i)
        input >> a.ptr[i];
    return input;
}

// output operator
std::ostream &operator<<(std::ostream &output, const DoubleSubscriptedArray &a) {
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            output << std::setw(5) << a(i, j);
        }
        output << '\n';
    }
    return output;
}

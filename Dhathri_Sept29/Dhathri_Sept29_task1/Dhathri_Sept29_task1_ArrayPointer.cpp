#include "Dhathri_Sept29_task1_ArrayPointer.h"

void initializeArray(double numbers[])
{
    // a) Initialize array with 0.0, 1.1, 2.2, ... 9.9
    for (int index = 0; index < SIZE; ++index)
    {
        numbers[index] = index * 1.1;
    }
}

void printArrayUsingSubscript(const double numbers[])
{
    // c) Print using subscript notation
    std::cout << "Array using subscript notation:\n";
    for (int index = 0; index < SIZE; ++index)
    {
        std::cout << std::fixed << std::setprecision(1) << numbers[index] << " ";
    }
    std::cout << "\n";
}

void assignPointerToArray(double* &nPtr, double numbers[])
{
    // d) Assign starting address in two different ways
    nPtr = numbers;        // Method 1
    nPtr = &numbers[0];    // Method 2
}

void printArrayUsingPointerOffset(double* nPtr)
{
    // e) Print using pointer/offset notation
    std::cout << "Array using pointer/offset notation with nPtr:\n";
    for (int index = 0; index < SIZE; ++index)
    {
        std::cout << std::fixed << std::setprecision(1) << *(nPtr + index) << " ";
    }
    std::cout << "\n";
}

void printArrayUsingArrayNameOffset(const double numbers[])
{
    // f) Print using array name as a pointer
    std::cout << "Array using pointer/offset notation with array name:\n";
    for (int index = 0; index < SIZE; ++index)
    {
        std::cout << std::fixed << std::setprecision(1) << *(numbers + index) << " ";
    }
    std::cout << "\n";
}

void printArrayUsingPointerSubscript(double* nPtr)
{
    // g) Print using pointer/subscript notation
    std::cout << "Array using pointer/subscript notation with nPtr:\n";
    for (int index = 0; index < SIZE; ++index)
    {
        std::cout << std::fixed << std::setprecision(1) << nPtr[index] << " ";
    }
    std::cout << "\n";
}

void demonstrateElementAccess(double* nPtr, double numbers[])
{
    // h) Refer to 4th element
    std::cout << "Fourth element of array (different notations):\n";
    std::cout << "Array subscript: " << numbers[3] << "\n";
    std::cout << "Pointer/offset with array name: " << *(numbers + 3) << "\n";
    std::cout << "Pointer subscript with nPtr: " << nPtr[3] << "\n";
    std::cout << "Pointer/offset with nPtr: " << *(nPtr + 3) << "\n";
}

void demonstratePointerArithmetic(double* nPtr, double numbers[])
{
    // i) nPtr + 8
    nPtr = numbers;
    std::cout << "\nPointer arithmetic demonstrations:\n";
    std::cout << "Address referenced by nPtr + 8: " << (nPtr + 8) << "\n";
    std::cout << "Value at that address: " << *(nPtr + 8) << "\n";

    // j) nPtr points to numbers[5], then subtract 4
    nPtr = &numbers[5];
    nPtr -= 4;
    std::cout << "Address after nPtr -= 4 (from numbers[5]): " << nPtr << "\n";
    std::cout << "Value at that address: " << *nPtr << "\n";
}

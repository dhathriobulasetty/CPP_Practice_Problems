#include "Dhathri_Sept29_task1_ArrayPointer.h"

int main()
{
    double numbers[SIZE];   // a) Declare array
    double* nPtr = nullptr; // b) Declare pointer to double named nPtr

    initializeArray(numbers);
    printArrayUsingSubscript(numbers);

    assignPointerToArray(nPtr, numbers);
    printArrayUsingPointerOffset(nPtr);
    printArrayUsingArrayNameOffset(numbers);
    printArrayUsingPointerSubscript(nPtr);

    demonstrateElementAccess(nPtr, numbers);
    demonstratePointerArithmetic(nPtr, numbers);

    return 0;
}

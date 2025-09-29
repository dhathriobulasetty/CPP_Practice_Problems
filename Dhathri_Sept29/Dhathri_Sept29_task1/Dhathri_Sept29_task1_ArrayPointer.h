#ifndef ARRAYPOINTER_H
#define ARRAYPOINTER_H

#include <iostream>
#include <iomanip>

// Constant definition
const int SIZE = 10;

// Function declarations
void initializeArray(double numbers[]);
void printArrayUsingSubscript(const double numbers[]);
void assignPointerToArray(double* &nPtr, double numbers[]);
void printArrayUsingPointerOffset(double* nPtr);
void printArrayUsingArrayNameOffset(const double numbers[]);
void printArrayUsingPointerSubscript(double* nPtr);
void demonstrateElementAccess(double* nPtr, double numbers[]);
void demonstratePointerArithmetic(double* nPtr, double numbers[]);

#endif 

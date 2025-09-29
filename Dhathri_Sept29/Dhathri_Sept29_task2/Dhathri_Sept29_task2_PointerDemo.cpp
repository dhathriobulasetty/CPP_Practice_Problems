#include "Dhathri_Sept29_task2_PointerDemo.h"

void demonstratePointerTasks()
{
    double number1 = 7.3;     
    double number2 = 0.0;     
    char* ptr = nullptr;      // variable ptr of type char*
    char s1[100] = "Hello";   // initialized with string literal
    char s2[100] = "World";   // initialized with string literal

    // a) Declare the variable fPtr to be a pointer to an object of type double
    double* fPtr = nullptr;

    // b) Assign the address of variable number1 to pointer variable fPtr
    fPtr = &number1;

    // c) Print the value of the object pointed to by fPtr
    std::cout << "Value pointed to by fPtr: " << *fPtr << "\n";

    // d) Assign the value of the object pointed to by fPtr to variable number2
    number2 = *fPtr;

    // e) Print the value of number2
    std::cout << "Value of number2: " << number2 << "\n";

    // f) Print the address of number1
    std::cout << "Address of number1: " << &number1 << "\n";

    // g) Print the address stored in fPtr and check if same as &number1
    std::cout << "Address stored in fPtr: " << fPtr << "\n";
    if (fPtr == &number1)
    {
        std::cout << "Yes, the address stored in fPtr is the same as the address of number1.\n";
    }
    else
    {
        std::cout << "No, the addresses are different.\n";
    }
}

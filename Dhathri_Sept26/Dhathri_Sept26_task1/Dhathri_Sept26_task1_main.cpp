#include <iostream>
#include "Dhathri_Sept26_task1_DoubleSubscriptedArray.h"

int main() {
    DoubleSubscriptedArray A(3, 5); // 3x5 array
    std::cout << "Enter 15 integers for 3x5 array:\n";
    std::cin >> A;

    std::cout << "\nArray A is:\n" << A;

    // copy constructor
    DoubleSubscriptedArray B(A);
    std::cout << "\nCopied array B (from A):\n" << B;

    // assignment
    DoubleSubscriptedArray C(2, 2);
    C = A;
    std::cout << "\nArray C after assignment from A:\n" << C;

    // comparison
    std::cout << "\nAre A and B equal? " << (A == B ? "Yes" : "No") << '\n';
    std::cout << "Are A and C not equal? " << (A != C ? "Yes" : "No") << '\n';

    // element access
    std::cout << "\nElement at (1,3) in A is: " << A(1, 3) << '\n';
    std::cout << "Modifying A(1,3) to 99...\n";
    A(1, 3) = 99;
    std::cout << "Now array A is:\n" << A;

    return 0;
}

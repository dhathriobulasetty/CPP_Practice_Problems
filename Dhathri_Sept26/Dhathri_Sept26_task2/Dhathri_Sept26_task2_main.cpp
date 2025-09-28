#include <iostream>
#include "Dhathri_Sept26_task2_ComplexClass.h"

int main() {
    Complex x, y(4.3, 8.2), z(3.3, 1.1);

    std::cout << "Initially:\n";
    std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\n";

    x = y + z;
    std::cout << "\nx = y + z:\n";
    std::cout << x << " = " << y << " + " << z << "\n";

    x = y - z;
    std::cout << "\nx = y - z:\n";
    std::cout  << x << " = " << y << " - " << z << "\n";

    x = y * z;
    std::cout << "\nx = y * z:\n";
    std::cout << x << " = " << y << " * " << z << "\n";

    // Testing == and !=
    if (y == z)
        std::cout << "\ny and z are equal\n";
    else
        std::cout << "\ny and z are not equal\n";

    if (y != z)
        std::cout << "y and z are different\n";

    return 0;
}

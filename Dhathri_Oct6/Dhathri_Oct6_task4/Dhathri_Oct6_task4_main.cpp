#include "Dhathri_Oct6_task4_Quadrilateral.h"

int main()
{
    std::cout << "Quadrilateral Hierarchy Demonstration \n\n";

    Trapezoid trapezoid(8.0, 6.0, 4.0, 5.0, 3.0);
    std::cout << "Trapezoid:\n";
    trapezoid.displaySides();
    std::cout << "Area: " << trapezoid.calculateArea() << "\n";
    std::cout << "Perimeter: " << trapezoid.calculatePerimeter() << "\n\n";

    Parallelogram parallelogram(6.0, 4.0, 3.0);
    std::cout << "Parallelogram:\n";
    parallelogram.displaySides();
    std::cout << "Area: " << parallelogram.calculateArea() << "\n";
    std::cout << "Perimeter: " << parallelogram.calculatePerimeter() << "\n\n";

    Rectangle rectangle(5.0, 3.0);
    std::cout << "Rectangle:\n";
    rectangle.displaySides();
    std::cout << "Area: " << rectangle.calculateArea() << "\n";
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << "\n\n";

    Square square(4.0);
    std::cout << "Square:\n";
    square.displaySides();
    std::cout << "Area: " << square.calculateArea() << "\n";
    std::cout << "Perimeter: " << square.calculatePerimeter() << "\n\n";

    return 0;
}

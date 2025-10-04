#include "Dhathri_Oct1_task3_Geometry.h"
#include <iostream>

int main() {
    // Sample data for different shapes
    float s1[4] = {3,4,5,6}, a1[4] = {90,90,90,90};
    float s2[4] = {6,5,4,3}, a2[4] = {100,80,100,80};
    float s3[4] = {6,4,6,4}, a3[4] = {110,70,110,70};
    float s4[4] = {6,4,6,4}, a4[4] = {90,90,90,90};
    float s5[4] = {5,5,5,5}, a5[4] = {90,90,90,90};

    // Create one object of each class
    Quadrilateral quad(s1,a1);
    Trapezoid trap(s2,a2);
    Parallelogram para(s3,a3);
    Rectangle rect(s4,a4);
    Square sq(s5,a5);

    // Store them in a Quadrilateral* array for polymorphism
    Quadrilateral* shapes[5] = {&quad, &trap, &para, &rect, &sq};

    // Demonstrate virtual functions
    for (int i = 0; i < 5; i++) {
        std::cout << *shapes[i] << "\n";
        std::cout << "Valid: " << shapes[i]->isValid() << "\n";
        std::cout << "Area: " << shapes[i]->area() << "\n";
        std::cout << "Perimeter: " << (*shapes[i])() << "\n\n";
    }

    // Compare Rectangle and Square areas
    std::cout << "Rectangle == Square ? " << (rect == sq) << "\n";

    // Type conversion operator (Square → float)
    std::cout << "Square as float (area): " << float(sq) << "\n";

    return 0;
}

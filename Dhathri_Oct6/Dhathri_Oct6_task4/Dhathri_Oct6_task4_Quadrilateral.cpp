#include "Dhathri_Oct6_task4_Quadrilateral.h"

#include <cmath>
// Base Class Implementation
Quadrilateral::Quadrilateral(double a, double b, double c, double d)
    : sideA(a), sideB(b), sideC(c), sideD(d){}

void Quadrilateral::displaySides() const
{
    std::cout << "Sides: " << sideA << ", " << sideB << ", "
              << sideC << ", " << sideD << std::endl;
}

// Trapezoid Implementation
Trapezoid::Trapezoid(double a, double b, double c, double d, double h)
    : Quadrilateral(a, b, c, d), height(h)
{}

double Trapezoid::calculateArea() const
{
    // Formula: ((a + b) / 2) * height
    return ((sideA + sideC) / 2) * height;
}

double Trapezoid::calculatePerimeter() const
{
    return sideA + sideB + sideC + sideD;
}

// Parallelogram Implementation
Parallelogram::Parallelogram(double base, double side, double h)
    : Quadrilateral(base, side, base, side), height(h)
{
}

double Parallelogram::calculateArea() const
{
    // Area = base * height
    return sideA * height;
}

double Parallelogram::calculatePerimeter() const
{
    return 2 * (sideA + sideB);
}

// Rectangle Implementation
Rectangle::Rectangle(double length, double width)
    : Parallelogram(length, width, width)
{
}

double Rectangle::calculateArea() const
{
    return sideA * sideB;
}

double Rectangle::calculatePerimeter() const
{
    return 2 * (sideA + sideB);
}

// Square Implementation
Square::Square(double side)
    : Rectangle(side, side)
{
}

double Square::calculateArea() const
{
    return sideA * sideA;
}

double Square::calculatePerimeter() const
{
    return 4 * sideA;
}

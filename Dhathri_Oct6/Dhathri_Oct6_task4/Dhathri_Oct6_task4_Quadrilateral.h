#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <string>

// Base Class
class Quadrilateral
{
protected:
    double sideA;
    double sideB;
    double sideC;
    double sideD;

public:
    // Constructor
    Quadrilateral(double a, double b, double c, double d);

    // Display function
    void displaySides() const;
};

// Derived Class: Trapezoid
class Trapezoid : public Quadrilateral
{
protected:
    double height;

public:
    Trapezoid(double a, double b, double c, double d, double h);
    double calculateArea() const;
    double calculatePerimeter() const;
};

// Derived Class: Parallelogram
class Parallelogram : public Quadrilateral
{
protected:
    double height;

public:
    Parallelogram(double base, double side, double h);
    double calculateArea() const;
    double calculatePerimeter() const;
};

// Derived Class: Rectangle
class Rectangle : public Parallelogram
{
public:
    Rectangle(double length, double width);
    double calculateArea() const;
    double calculatePerimeter() const;
};

// Derived Class: Square
class Square : public Rectangle
{
public:
    explicit Square(double side);
    double calculateArea() const;
    double calculatePerimeter() const;
};

#endif

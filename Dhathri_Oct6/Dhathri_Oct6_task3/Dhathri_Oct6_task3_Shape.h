#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <string>

// Base class: Shape
class Shape {
protected:
    std::string shapeName;

public:
    Shape(const std::string& name);
    virtual ~Shape();

    virtual void display() const = 0; 
};

// Derived class: TwoDimensionalShape
class TwoDimensionalShape : public Shape {
public:
    TwoDimensionalShape(const std::string& name);
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
};

// Derived class: ThreeDimensionalShape
class ThreeDimensionalShape : public Shape {
public:
    ThreeDimensionalShape(const std::string& name);
    virtual double calculateSurfaceArea() const = 0;
    virtual double calculateVolume() const = 0;
};

// 2D Shapes
class Circle : public TwoDimensionalShape {
private:
    double radius;

public:
    Circle(double r);
    double calculateArea() const override;
    double calculatePerimeter() const override;
    void display() const override;
};

class Triangle : public TwoDimensionalShape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double a, double b, double c);
    double calculateArea() const override;
    double calculatePerimeter() const override;
    void display() const override;
};

class Rectangle : public TwoDimensionalShape {
private:
    double length, width;

public:
    Rectangle(double l, double w);
    double calculateArea() const override;
    double calculatePerimeter() const override;
    void display() const override;
};

class Square : public TwoDimensionalShape {
private:
    double side;

public:
    Square(double s);
    double calculateArea() const override;
    double calculatePerimeter() const override;
    void display() const override;
};

class Parallelogram : public TwoDimensionalShape {
private:
    double base, height, side;

public:
    Parallelogram(double b, double h, double s);
    double calculateArea() const override;
    double calculatePerimeter() const override;
    void display() const override;
};

class Rhombus : public TwoDimensionalShape {
private:
    double diagonal1, diagonal2, side;

public:
    Rhombus(double d1, double d2, double s);
    double calculateArea() const override;
    double calculatePerimeter() const override;
    void display() const override;
};

// 3D Shapes
class Sphere : public ThreeDimensionalShape {
private:
    double radius;

public:
    Sphere(double r);
    double calculateSurfaceArea() const override;
    double calculateVolume() const override;
    void display() const override;
};

class Cube : public ThreeDimensionalShape {
private:
    double side;

public:
    Cube(double s);
    double calculateSurfaceArea() const override;
    double calculateVolume() const override;
    void display() const override;
};

class Cuboid : public ThreeDimensionalShape {
private:
    double length, width, height;

public:
    Cuboid(double l, double w, double h);
    double calculateSurfaceArea() const override;
    double calculateVolume() const override;
    void display() const override;
};

class Cylinder : public ThreeDimensionalShape {
private:
    double radius, height;

public:
    Cylinder(double r, double h);
    double calculateSurfaceArea() const override;
    double calculateVolume() const override;
    void display() const override;
};

class Cone : public ThreeDimensionalShape {
private:
    double radius, height;

public:
    Cone(double r, double h);
    double calculateSurfaceArea() const override;
    double calculateVolume() const override;
    void display() const override;
};

#endif

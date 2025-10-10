#include "Dhathri_Oct6_task3_Shape.h"

// Base Class Implementations

// Constructor initializes shape name
Shape::Shape(const std::string& name) : shapeName(name) {}

// Destructor
Shape::~Shape() {}

// Constructors of intermediate base classes
TwoDimensionalShape::TwoDimensionalShape(const std::string& name) : Shape(name) {}
ThreeDimensionalShape::ThreeDimensionalShape(const std::string& name) : Shape(name) {}

// 2D Shapes Implementations

// Circle 
Circle::Circle(double r) : TwoDimensionalShape("Circle"), radius(r) {}

double Circle::calculateArea() const {
    return M_PI * radius * radius; // πr²
}

double Circle::calculatePerimeter() const {
    return 2 * M_PI * radius; // 2πr
}

void Circle::display() const {
    std::cout << "Shape: " << shapeName << "\nRadius: " << radius
              << "\nArea: " << calculateArea()
              << "\nPerimeter: " << calculatePerimeter() << "\n\n";
}

//  Triangle 
Triangle::Triangle(double a, double b, double c)
    : TwoDimensionalShape("Triangle"), sideA(a), sideB(b), sideC(c) {}

double Triangle::calculatePerimeter() const {
    return sideA + sideB + sideC;
}

double Triangle::calculateArea() const {
    double s = calculatePerimeter() / 2;        
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC)); // Heron's formula
}

void Triangle::display() const {
    std::cout << "Shape: " << shapeName << "\nSides: "
              << sideA << ", " << sideB << ", " << sideC
              << "\nArea: " << calculateArea()
              << "\nPerimeter: " << calculatePerimeter() << "\n\n";
}

// Rectangle 
Rectangle::Rectangle(double l, double w)
    : TwoDimensionalShape("Rectangle"), length(l), width(w) {}

double Rectangle::calculateArea() const {
    return length * width;
}

double Rectangle::calculatePerimeter() const {
    return 2 * (length + width);
}

void Rectangle::display() const {
    std::cout << "Shape: " << shapeName << "\nLength: " << length
              << ", Width: " << width
              << "\nArea: " << calculateArea()
              << "\nPerimeter: " << calculatePerimeter() << "\n\n";
}

// Square 
Square::Square(double s)
    : TwoDimensionalShape("Square"), side(s) {}

double Square::calculateArea() const {
    return side * side;
}

double Square::calculatePerimeter() const {
    return 4 * side;
}

void Square::display() const {
    std::cout << "Shape: " << shapeName << "\nSide: " << side
              << "\nArea: " << calculateArea()
              << "\nPerimeter: " << calculatePerimeter() << "\n\n";
}

//  Parallelogram 
Parallelogram::Parallelogram(double b, double h, double s)
    : TwoDimensionalShape("Parallelogram"), base(b), height(h), side(s) {}

double Parallelogram::calculateArea() const {
    return base * height;
}

double Parallelogram::calculatePerimeter() const {
    return 2 * (base + side);
}

void Parallelogram::display() const {
    std::cout << "Shape: " << shapeName << "\nBase: " << base
              << ", Height: " << height
              << "\nArea: " << calculateArea()
              << "\nPerimeter: " << calculatePerimeter() << "\n\n";
}

//  Rhombus 
Rhombus::Rhombus(double d1, double d2, double s)
    : TwoDimensionalShape("Rhombus"), diagonal1(d1), diagonal2(d2), side(s) {}

double Rhombus::calculateArea() const {
    return (diagonal1 * diagonal2) / 2; // ½ × d₁ × d₂
}

double Rhombus::calculatePerimeter() const {
    return 4 * side;
}

void Rhombus::display() const {
    std::cout << "Shape: " << shapeName << "\nDiagonals: "
              << diagonal1 << ", " << diagonal2
              << "\nArea: " << calculateArea()
              << "\nPerimeter: " << calculatePerimeter() << "\n\n";
}

// 3D Shapes Implementations

// Sphere 
Sphere::Sphere(double r)
    : ThreeDimensionalShape("Sphere"), radius(r) {}

double Sphere::calculateSurfaceArea() const {
    return 4 * M_PI * radius * radius; // 4πr²
}

double Sphere::calculateVolume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3); // 4/3 πr³
}

void Sphere::display() const {
    std::cout << "Shape: " << shapeName << "\nRadius: " << radius
              << "\nSurface Area: " << calculateSurfaceArea()
              << "\nVolume: " << calculateVolume() << "\n\n";
}

//  Cube 
Cube::Cube(double s)
    : ThreeDimensionalShape("Cube"), side(s) {}

double Cube::calculateSurfaceArea() const {
    return 6 * side * side; // 6a²
}

double Cube::calculateVolume() const {
    return std::pow(side, 3); // a³
}

void Cube::display() const {
    std::cout << "Shape: " << shapeName << "\nSide: " << side
              << "\nSurface Area: " << calculateSurfaceArea()
              << "\nVolume: " << calculateVolume() << "\n\n";
}

//  Cuboid 
Cuboid::Cuboid(double l, double w, double h)
    : ThreeDimensionalShape("Cuboid"), length(l), width(w), height(h) {}

double Cuboid::calculateSurfaceArea() const {
    return 2 * (length * width + width * height + height * length);
}

double Cuboid::calculateVolume() const {
    return length * width * height;
}

void Cuboid::display() const {
    std::cout << "Shape: " << shapeName
              << "\nLength: " << length
              << ", Width: " << width
              << ", Height: " << height
              << "\nSurface Area: " << calculateSurfaceArea()
              << "\nVolume: " << calculateVolume() << "\n\n";
}

// Cylinder 
Cylinder::Cylinder(double r, double h)
    : ThreeDimensionalShape("Cylinder"), radius(r), height(h) {}

double Cylinder::calculateSurfaceArea() const {
    return 2 * M_PI * radius * (radius + height); // 2πr(r + h)
}

double Cylinder::calculateVolume() const {
    return M_PI * radius * radius * height; // πr²h
}

void Cylinder::display() const {
    std::cout << "Shape: " << shapeName
              << "\nRadius: " << radius
              << ", Height: " << height
              << "\nSurface Area: " << calculateSurfaceArea()
              << "\nVolume: " << calculateVolume() << "\n\n";
}

//  Cone 
Cone::Cone(double r, double h)
    : ThreeDimensionalShape("Cone"), radius(r), height(h) {}

double Cone::calculateSurfaceArea() const {
    double slant = std::sqrt(radius * radius + height * height); // slant height
    return M_PI * radius * (radius + slant); // πr(r + l)
}

double Cone::calculateVolume() const {
    return (M_PI * radius * radius * height) / 3; // ⅓ πr²h
}

void Cone::display() const {
    std::cout << "Shape: " << shapeName
              << "\nRadius: " << radius
              << ", Height: " << height
              << "\nSurface Area: " << calculateSurfaceArea()
              << "\nVolume: " << calculateVolume() << "\n\n";
}

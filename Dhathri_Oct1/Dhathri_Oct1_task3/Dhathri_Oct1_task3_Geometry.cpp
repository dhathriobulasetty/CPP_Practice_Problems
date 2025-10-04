#include "Dhathri_Oct1_task3_Geometry.h"

// Base Class 
Quadrilateral::Quadrilateral(const float s[4], const float a[4]) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = s[i];
        angles[i] = a[i];
    }
}
Quadrilateral::Quadrilateral(const Quadrilateral& other) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = other.sides[i];
        angles[i] = other.angles[i];
    }
}
Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }
    return *this;
}
Quadrilateral::~Quadrilateral() {
    delete[] sides;
    delete[] angles;
}
bool Quadrilateral::isValid() {
    float sum = 0;
    for (int i = 0; i < 4; i++) sum += angles[i];
    return std::fabs(sum - 360.0f) < 1e-3;  // check sum of angles
}
float Quadrilateral::area() const { return 0.0f; } // generic quad no area formula
std::string Quadrilateral::type() const { return "Quadrilateral"; }

// Operator overloads
bool Quadrilateral::operator==(const Quadrilateral& other) const {
    return std::fabs(this->area() - other.area()) < 1e-3;
}
float Quadrilateral::operator()() const {
    return sides[0] + sides[1] + sides[2] + sides[3]; // perimeter
}
Quadrilateral::operator float() const { return area(); }
std::ostream& operator<<(std::ostream& os, const Quadrilateral& q) {
    os << q.type() << " (Sides: ";
    for (int i = 0; i < 4; i++) os << q.sides[i] << " ";
    os << ", Angles: ";
    for (int i = 0; i < 4; i++) os << q.angles[i] << " ";
    os << ")";
    return os;
}

// Trapezoid 
Trapezoid::Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s, a) {}
bool Trapezoid::isValid() {
    return Quadrilateral::isValid(); // simplified assumption
}
float Trapezoid::area() const {
    float h = sides[1]; // dummy height assumption for example
    return 0.5f * (sides[0] + sides[2]) * h;
}
std::string Trapezoid::type() const { return "Trapezoid"; }

// Parallelogram 
Parallelogram::Parallelogram(const float s[4], const float a[4]) : Trapezoid(s, a) {}
bool Parallelogram::isValid() {
    return Quadrilateral::isValid() &&
           (std::fabs(sides[0] - sides[2]) < 1e-3) &&
           (std::fabs(sides[1] - sides[3]) < 1e-3); // opposite sides equal
}
float Parallelogram::area() const {
    float rad = angles[0] * M_PI / 180.0f;
    return sides[0] * sides[1] * std::sin(rad); // base*height using sin(angle)
}
std::string Parallelogram::type() const { return "Parallelogram"; }

// Rectangle 
Rectangle::Rectangle(const float s[4], const float a[4]) : Parallelogram(s, a) {}
bool Rectangle::isValid() {
    return Parallelogram::isValid() &&
           (std::fabs(angles[0] - 90.0f) < 1e-3); // all right angles
}
float Rectangle::area() const {
    return sides[0] * sides[1]; // length * breadth
}
std::string Rectangle::type() const { return "Rectangle"; }

// Square 
Square::Square(const float s[4], const float a[4]) : Rectangle(s, a) {}
bool Square::isValid() {
    return Rectangle::isValid() &&
           (std::fabs(sides[0] - sides[1]) < 1e-3); // all sides equal
}
float Square::area() const {
    return sides[0] * sides[0]; // side^2
}
std::string Square::type() const { return "Square"; }

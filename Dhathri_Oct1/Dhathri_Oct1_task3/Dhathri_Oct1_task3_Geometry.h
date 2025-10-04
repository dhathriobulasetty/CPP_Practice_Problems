#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>
#include <string>

// Base class: General Quadrilateral
class Quadrilateral {
protected:
    float* sides;   // dynamically allocated array for 4 sides
    float* angles;  // dynamically allocated array for 4 angles

public:
    Quadrilateral(const float s[4], const float a[4]);   // constructor with new
    Quadrilateral(const Quadrilateral& other);           // copy constructor
    Quadrilateral& operator=(const Quadrilateral& other);// assignment operator
    virtual ~Quadrilateral();                            // destructor with delete[]

    // Virtual functions for polymorphism
    virtual bool isValid();       // sum of angles == 360
    virtual float area() const;   // default = 0
    virtual std::string type() const;

    // Operator overloads
    bool operator==(const Quadrilateral& other) const; // compare by area
    float operator()() const;                          // perimeter
    operator float() const;                            // convert to area
    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& q);
};

// Derived classes in deep hierarchy
class Trapezoid : public Quadrilateral {
public:
    Trapezoid(const float s[4], const float a[4]);
    bool isValid() override;      // at least one pair parallel 
    float area() const override;  // formula using average of bases * height
    std::string type() const override;
};

class Parallelogram : public Trapezoid {
public:
    Parallelogram(const float s[4], const float a[4]);
    bool isValid() override;      // opposite sides equal
    float area() const override;  // base * height using sin(angle)
    std::string type() const override;
};

class Rectangle : public Parallelogram {
public:
    Rectangle(const float s[4], const float a[4]);
    bool isValid() override;      // all angles = 90
    float area() const override;  // length * breadth
    std::string type() const override;
};

class Square : public Rectangle {
public:
    Square(const float s[4], const float a[4]);
    bool isValid() override;      // all sides equal + all angles 90
    float area() const override;  // side * side
    std::string type() const override;
};

#endif

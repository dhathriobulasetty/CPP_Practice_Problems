#include "Dhathri_Oct6_task3_Shape.h"

int main() {
    // Create objects for Two-Dimensional Shapes
    Circle circle(5.0);
    Triangle triangle(3.0, 4.0, 5.0);
    Rectangle rectangle(4.0, 6.0);
    Square square(5.0);
    Parallelogram parallelogram(6.0, 4.0, 5.0);
    Rhombus rhombus(6.0, 8.0, 5.0);

    // Create objects for Three-Dimensional Shapes
    Sphere sphere(4.0);
    Cube cube(3.0);
    Cuboid cuboid(4.0, 5.0, 6.0);
    Cylinder cylinder(3.0, 7.0);
    Cone cone(3.0, 5.0);

    // Display all shapes
    std::cout << "TWO DIMENSIONAL SHAPES \n";
    circle.display();
    triangle.display();
    rectangle.display();
    square.display();
    parallelogram.display();
    rhombus.display();

    std::cout << "THREE DIMENSIONAL SHAPES \n";
    sphere.display();
    cube.display();
    cuboid.display();
    cylinder.display();
    cone.display();

    return 0;
}

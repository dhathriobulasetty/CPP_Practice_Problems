#include "Dhathri_Oct6_task2_StudentHierarchy.h"

int main()
{
    // Creating UndergraduateStudent objects
    Freshman f1("Sai", "101", "Computer Science", 18, 8.1, "AI & ML");
    Senior s1("Abhishek Sharma", "204", "Electrical", 21, 9.1, "Power Systems");

    // Creating GraduateStudent objects
    MastersStudent m1("Raju", "301", "Mechanical", 24, 8.8, "Robotics", "Dr. Raja Rao");
    DoctoralStudent d1("Ramu", "401", "Biotech", 26, 9.3, "Genomics", "Dr. Kiran");

    // Demonstrate functionality for Undergraduate students
    f1.displayDetails();
    f1.registerForClubs();
    f1.applyForInternship();

    s1.displayDetails();
    s1.applyForInternship();

    // Demonstrate functionality for Graduate students
    m1.displayDetails();
    m1.submitThesis();
    m1.assistProfessor();

    d1.displayDetails();
    d1.submitThesis();

    return 0;
}

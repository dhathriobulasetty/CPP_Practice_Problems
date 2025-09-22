#include "Dhathri_Sept22_task4_HeartRates.h"
#include <iostream>

int main()
{
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;

    std::cout << "Enter first name: ";
    std::cin >> firstName;

    std::cout << "Enter last name: ";
    std::cin >> lastName;

    std::cout << "Enter birth month (1-12): ";
    std::cin >> birthMonth;

    std::cout << "Enter birth day (1-31): ";
    std::cin >> birthDay;

    std::cout << "Enter birth year: ";
    std::cin >> birthYear;

    HeartRates person(firstName, lastName, birthMonth, birthDay, birthYear);

    int currentMonth, currentDay, currentYear;
    std::cout << "\nEnter current month (1-12): ";
    std::cin >> currentMonth;
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    int age = person.getAge(currentMonth, currentDay, currentYear);
    int maxRate = person.getMaximumHeartRate(age);
    int lowerBound, upperBound;
    person.getTargetHeartRate(age, lowerBound, upperBound);

    std::cout << "\nHeart Rate Information \n";
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << "\n";
    std::cout << "Date of Birth: " << person.getBirthDay() << "/"
              << person.getBirthMonth() << "/" << person.getBirthYear() << "\n";
    std::cout << "Age: " << age << " years\n";
    std::cout << "Maximum Heart Rate: " << maxRate << " bpm\n";
    std::cout << "Target Heart Rate Range: " << lowerBound << " - " << upperBound << " bpm\n";

    return 0;
}

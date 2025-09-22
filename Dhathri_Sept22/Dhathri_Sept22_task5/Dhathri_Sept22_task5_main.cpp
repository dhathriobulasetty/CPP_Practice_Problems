#include "Dhathri_Sept22_task5_HealthProfile.h"
#include <iostream>

int main() {
    std::string firstName, lastName, gender;
    int day, month, year;
    double height, weight;
    int currentDay, currentMonth, currentYear;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter gender: ";
    std::cin >> gender;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> month;
    std::cout << "Enter birth day (1-31): ";
    std::cin >> day;
    std::cout << "Enter birth year: ";
    std::cin >> year;
    std::cout << "Enter height (in inches): ";
    std::cin >> height;
    std::cout << "Enter weight (in pounds): ";
    std::cin >> weight;

    // Ask current date for age calculation
    std::cout << "\nEnter current month: ";
    std::cin >> currentMonth;
    std::cout << "Enter current day: ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    // Create HealthProfile object
    HealthProfile profile(firstName, lastName, gender, day, month, year, height, weight);

    int age = profile.getAge(currentDay, currentMonth, currentYear);
    double bmi = profile.getBMI();
    int maxHeartRate = profile.getMaximumHeartRate(age);
    int lower, upper;
    profile.getTargetHeartRateRange(age, lower, upper);

    // Display info
    std::cout << "\nHealth Profile \n";
    std::cout << "Name: " << profile.getFirstName() << " " << profile.getLastName() << "\n";
    std::cout << "Gender: " << profile.getGender() << "\n";
    std::cout << "Date of Birth: " << profile.getBirthDay() << "/" 
              << profile.getBirthMonth() << "/" << profile.getBirthYear() << "\n";
    std::cout << "Height: " << profile.getHeight() << " inches\n";
    std::cout << "Weight: " << profile.getWeight() << " pounds\n";

    std::cout << "Age: " << age << " years\n";
    std::cout << "BMI: " << bmi << "\n";
    std::cout << "Maximum Heart Rate: " << maxHeartRate << "\n";
    std::cout << "Target Heart Rate Range: " << lower << " - " << upper << "\n";

    // BMI Categories
    std::cout << "\nBMI VALUES\n";
    std::cout << "Underweight: less than 18.5\n";
    std::cout << "Normal: between 18.5 and 24.9\n";
    std::cout << "Overweight: between 25 and 29.9\n";
    std::cout << "Obese: 30 or greater\n";

    return 0;
}

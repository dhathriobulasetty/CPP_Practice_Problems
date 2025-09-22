#include "Dhathri_Sept22_task5_HealthProfile.h"
#include <iostream>

// Constructor
HealthProfile::HealthProfile(const std::string& fName, const std::string& lName, const std::string& gen,
                             int day, int month, int year, int height, int weight)
    : firstName(fName), lastName(lName), gender(gen),
      birthDay(day), birthMonth(month), birthYear(year),
      heightInInches(height), weightInPounds(weight) {}

// Setters
void HealthProfile::setFirstName(const std::string& fName) { firstName = fName; }
void HealthProfile::setLastName(const std::string& lName) { lastName = lName; }
void HealthProfile::setGender(const std::string& gen) { gender = gen; }
void HealthProfile::setBirthDay(int day) { birthDay = day; }
void HealthProfile::setBirthMonth(int month) { birthMonth = month; }
void HealthProfile::setBirthYear(int year) { birthYear = year; }
void HealthProfile::setHeight(int height) { heightInInches = height; }
void HealthProfile::setWeight(int weight) { weightInPounds = weight; }

// Getters
std::string HealthProfile::getFirstName() const { return firstName; }
std::string HealthProfile::getLastName() const { return lastName; }
std::string HealthProfile::getGender() const { return gender; }
int HealthProfile::getBirthDay() const { return birthDay; }
int HealthProfile::getBirthMonth() const { return birthMonth; }
int HealthProfile::getBirthYear() const { return birthYear; }
int HealthProfile::getHeight() const { return heightInInches; }
int HealthProfile::getWeight() const { return weightInPounds; }

// Calculations
int HealthProfile::getAge(int currentDay, int currentMonth, int currentYear) const {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

int HealthProfile::getMaximumHeartRate(int age) const {
    return 220 - age;
}

void HealthProfile::getTargetHeartRateRange(int age, int& lower, int& upper) const {
    int maxRate = getMaximumHeartRate(age);
    lower = static_cast<int>(maxRate * 0.50);
    upper = static_cast<int>(maxRate * 0.85);
}

double HealthProfile::getBMI() const {
    return (weightInPounds * 703.0) / (heightInInches * heightInInches);
}

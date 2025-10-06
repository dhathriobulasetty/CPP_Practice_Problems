#include "Dhathri_Oct6_Task1_BasePlusCommissionEmployee.h"
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& firstName,
                                                       const std::string& lastName,
                                                       const std::string& ssn,
                                                       double sales,
                                                       double rate,
                                                       double salary)
    : commissionEmp(firstName, lastName, ssn, sales, rate), baseSalary(0.0)
{
    setBaseSalary(salary);
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

// calculate earnings
double BasePlusCommissionEmployee::calculateTotalEarnings() const
{
    return getBaseSalary() + commissionEmp.calculateEarnings();
}

// print BasePlusCommissionEmployee object
void BasePlusCommissionEmployee::displayEmployeeDetails() const
{
    commissionEmp.displayEmployeeDetails();
    std::cout << "Base Salary: " << baseSalary << "\n";
    std::cout << "Total Earnings: " << calculateTotalEarnings() << "\n";
}

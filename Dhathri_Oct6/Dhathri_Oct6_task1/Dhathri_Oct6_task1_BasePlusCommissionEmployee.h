#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include "Dhathri_Oct6_Task1_CommissionEmployee.h"

class BasePlusCommissionEmployee
{
private:
    CommissionEmployee commissionEmp; // Composition
    double baseSalary;

public:
    BasePlusCommissionEmployee(const std::string& firstName,
                               const std::string& lastName,
                               const std::string& ssn,
                               double sales,
                               double rate,
                               double salary);

    void setBaseSalary(double salary);  // set base salary
    double getBaseSalary() const; // return base salary

    double calculateTotalEarnings() const; // calculate earnings
    void displayEmployeeDetails() const; // print BasePlusCommissionEmployee object
};

#endif

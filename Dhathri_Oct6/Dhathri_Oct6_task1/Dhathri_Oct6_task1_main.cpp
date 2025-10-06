#include "Dhathri_Oct6_Task1_BasePlusCommissionEmployee.h"
#include <iostream>

int main()
{
    std::cout << " Base Plus Commission Employee using Composition \n";

    // instantiate BasePlusCommissionEmployee object
    BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333",
                                        5000.0, 0.10, 1000.0);

    employee.displayEmployeeDetails();

    return 0;
}

#include "Dhathri_Sept25_task1_SavingsAccount.h"
#include<iostream>
int main()
{
    // Create two saver objects
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    // Set interest rate to 3%
    SavingsAccount::modifyInterestRate(0.03);

    // Calculate monthly interest and display balances
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Balances after 1 month at 3% annual interest:\n";
    std::cout << "Saver 1: ";
    saver1.displayBalance();
    std::cout << "Saver 2: ";
    saver2.displayBalance();

    // Set interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    // Calculate monthly interest and display balances
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nBalances after next month at 4% annual interest:\n";
    std::cout << "Saver 1: ";
    saver1.displayBalance();
    std::cout << "Saver 2: ";
    saver2.displayBalance();

    return 0;
}

#include "Dhathri_Sept25_task1_SavingsAccount.h"
#include<iostream>

// Initialize static member
double SavingsAccount::annualInterestRate = 0.0;

// Constructor
SavingsAccount::SavingsAccount(double initialBalance)
    : savingsBalance(initialBalance)
{
    if (initialBalance < 0.0)
    {
        std::cerr << "Error: Initial balance cannot be negative. Setting to 0.\n";
        savingsBalance = 0.0;
    }
}

// Calculate monthly interest and add to balance
void SavingsAccount::calculateMonthlyInterest()
{
    double monthlyInterest = (savingsBalance * annualInterestRate) / 12.0;
    savingsBalance += monthlyInterest;
}

// Display balance
void SavingsAccount::displayBalance() const
{
    std::cout << "Current Balance: $" << savingsBalance << "\n";
}

// Modify interest rate
void SavingsAccount::modifyInterestRate(double newRate)
{
    if (newRate >= 0.0)
    {
        annualInterestRate = newRate;
    }
    else
    {
        std::cerr << "Error: Interest rate cannot be negative.\n";
    }
}

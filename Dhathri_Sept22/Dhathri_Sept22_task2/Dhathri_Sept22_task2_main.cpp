#include "Dhathri_Sept22_task2_Account.h"
#include <iostream>

int main()
{
    // Create two Account objects
    Account account1(100);   // valid initial balance
    Account account2(-50);   // invalid initial balance, will reset to 0

    std::cout << "\nInitial balances:" << std::endl;
    std::cout << "Account 1 balance: " << account1.getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2.getBalance() << std::endl;

    // Credit operations
    std::cout << "\nCrediting 50 to Account 1..." << std::endl;
    account1.credit(50);
    std::cout << "Account 1 balance: " << account1.getBalance() << std::endl;

    // Debit operations
    std::cout << "\nDebiting 30 from Account 1..." << std::endl;
    account1.debit(30);
    std::cout << "Account 1 balance: " << account1.getBalance() << std::endl;

    std::cout << "\nTrying to debit 100 from Account 2 (should fail)..." << std::endl;
    account2.debit(100);
    std::cout << "Account 2 balance: " << account2.getBalance() << std::endl;

    return 0;
}

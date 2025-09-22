#include "Dhathri_Sept22_task3_Invoice.h"
#include <iostream>

int main()
{
    // Create two invoices
    Invoice invoice1("A1", "Hammer", 5, 55);
    Invoice invoice2("B1", "Screwdriver", -3, 25); // invalid quantity

    std::cout << "\nInvoice 1 Details:" << std::endl;
    std::cout << "Part Number: " << invoice1.getPartNumber() << std::endl;
    std::cout << "Description: " << invoice1.getPartDescription() << std::endl;
    std::cout << "Quantity: " << invoice1.getQuantity() << std::endl;
    std::cout << "Price per Item: " << invoice1.getPricePerItem() << std::endl;
    std::cout << "Invoice Amount: " << invoice1.getInvoiceAmount() << std::endl;

    std::cout << "\nInvoice 2 Details:" << std::endl;
    std::cout << "Part Number: " << invoice2.getPartNumber() << std::endl;
    std::cout << "Description: " << invoice2.getPartDescription() << std::endl;
    std::cout << "Quantity: " << invoice2.getQuantity() << std::endl;
    std::cout << "Price per Item: " << invoice2.getPricePerItem() << std::endl;
    std::cout << "Invoice Amount: " << invoice2.getInvoiceAmount() << std::endl;

    return 0;
}

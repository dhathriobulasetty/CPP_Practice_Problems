#include "Dhathri_Sept23_task3_AirlineReservation.h"
#include <iostream>

// Constructor initializes all seats to false (empty)
AirlineReservationSystem::AirlineReservationSystem() {
    seats.fill(false); 
}

// Finds the first available seat in the given range
int AirlineReservationSystem::findAvailableSeat(int start, int end) const {
    for (int i = start; i <= end; ++i) {
        if (!seats[i]) return i; // return first available seat index
    }
    return -1; // no seat available
}

// Prints a boarding pass for the passenger
void AirlineReservationSystem::printBoardingPass(int seatIndex) const {
    std::cout << "\nBoarding Pass:\n";
    std::cout << " Seat Number: " << seatIndex + 1 << '\n'; // +1 to convert from index to seat number
    if (seatIndex < 5)
        std::cout << " Section: First Class\n";
    else
        std::cout << " Section: Economy\n";
    std::cout << "------------------------\n\n";
}


void AirlineReservationSystem::run() {
    while (true) {
        std::cout << "Please type 1 for \"First Class\"\n";
        std::cout << "Please type 2 for \"Economy\"\n";
        std::cout << "Choice: ";
        
        int choice;
        std::cin >> choice;

        int seatIndex = -1;

        if (choice == 1) { // First Class booking
            seatIndex = findAvailableSeat(0, 4);

            if (seatIndex != -1) {
                seats[seatIndex] = true;
                printBoardingPass(seatIndex);
            } else {
                std::cout << "First Class is full. Accept Economy? (y/n): ";
                char ans;
                std::cin >> ans;
                if (ans == 'y' || ans == 'Y') {
                    seatIndex = findAvailableSeat(5, 9);
                    if (seatIndex != -1) {
                        seats[seatIndex] = true;
                        printBoardingPass(seatIndex);
                    } else {
                        std::cout << "Flight is full. Next flight leaves in 3 hours.\n";
                        break;
                    }
                } else {
                    std::cout << "Next flight leaves in 3 hours.\n";
                    break;
                }
            }
        } 
        else if (choice == 2) { // Economy booking
            seatIndex = findAvailableSeat(5, 9);

            if (seatIndex != -1) {
                seats[seatIndex] = true;
                printBoardingPass(seatIndex);
            } else {
                std::cout << "Economy is full. Accept First Class? (y/n): ";
                char ans;
                std::cin >> ans;
                if (ans == 'y' || ans == 'Y') {
                    seatIndex = findAvailableSeat(0, 4);
                    if (seatIndex != -1) {
                        seats[seatIndex] = true;
                        printBoardingPass(seatIndex);
                    } else {
                        std::cout << "Flight is full. Next flight leaves in 3 hours.\n";
                        break;
                    }
                } else {
                    std::cout << "Next flight leaves in 3 hours.\n";
                    break;
                }
            }
        } 
        else {
            std::cout << "Invalid choice. Please enter 1 or 2.\n";
        }

        // Check if all seats are filled
        bool full = true;
        for (bool seat : seats) {
            if (!seat) {
                full = false;
                break;
            }
        }
        if (full) {
            std::cout << "All seats are booked! Next flight leaves in 3 hours.\n";
            break;
        }
    }
}

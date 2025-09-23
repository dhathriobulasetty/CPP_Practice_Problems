#ifndef AIRLINERESERVATIONSYSTEM_H
#define AIRLINERESERVATIONSYSTEM_H

#include <array>

class AirlineReservationSystem {
private:
    static const int TOTAL_SEATS = 10;
    std::array<bool, TOTAL_SEATS> seats; // seat availability; false = empty, true = booked

    // find next available seat in a range
    int findAvailableSeat(int start, int end) const;

    // Print boarding pass with seat info
    void printBoardingPass(int seatIndex) const;

public:
    AirlineReservationSystem();

    // Run the interactive seat booking process
    void run();
};

#endif

#ifndef CRAPSGAMESTATS_H
#define CRAPSGAMESTATS_H

#include <array>

class CrapsGameStats {
private:
    static const int NUM_GAMES = 1000;
    static const int MAX_ROLLS_TRACKED = 20;

    std::array<int, MAX_ROLLS_TRACKED + 2> winsPerRoll;   // index 1..20, index 21 = after 20
    std::array<int, MAX_ROLLS_TRACKED + 2> lossesPerRoll; // same as above
    int totalWins;
    int totalLosses;
    int totalRolls;

    int rollDice(); // simulate rolling two dice

public:
    CrapsGameStats();

    void simulateGames();
    void displayStatistics() const;
};

#endif // CRAPSGAMESTATS_H

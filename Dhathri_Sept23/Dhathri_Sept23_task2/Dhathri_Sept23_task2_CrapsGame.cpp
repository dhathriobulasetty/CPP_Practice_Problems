#include "Dhathri_Sept23_task2_CrapsGame.h"   
#include <iostream>           
#include <cstdlib>           
#include <ctime>              

// Constructor 
CrapsGameStats::CrapsGameStats()
    : totalWins(0), totalLosses(0), totalRolls(0) {
    // Fill win/loss arrays with 0
    winsPerRoll.fill(0);
    lossesPerRoll.fill(0);

    // Seed the random number generator with the current system time
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

// Function to roll two dice and return their sum
int CrapsGameStats::rollDice() {
    int die1 = 1 + std::rand() % 6;  // Random number between 1–6
    int die2 = 1 + std::rand() % 6;  // Random number between 1–6
    return die1 + die2;              // Return total of both dice
}

// Simulates NUM_GAMES games of craps
void CrapsGameStats::simulateGames() {
    for (int game = 0; game < NUM_GAMES; ++game) {
        // Enum to represent possible game states
        enum Status { CONTINUE, WON, LOST };

        int myPoint = 0;         // Stores player’s point if game continues
        Status gameStatus;       // Current state of game
        int rollCount = 1;       // Counts how many rolls happened in this game

        int sumOfDice = rollDice();  // First roll of the dice

        // Rules of craps:
        switch (sumOfDice) {
            case 7: case 11:        // Immediate win
                gameStatus = WON;
                break;
            case 2: case 3: case 12: // Immediate loss
                gameStatus = LOST;
                break;
            default:                // Game continues, set point
                gameStatus = CONTINUE;
                myPoint = sumOfDice;
                break;
        }

        // Keep rolling until the game is WON or LOST
        while (gameStatus == CONTINUE) {
            ++rollCount;
            sumOfDice = rollDice();

            if (sumOfDice == myPoint) {
                gameStatus = WON;      // Player makes their point again → win
            } else if (sumOfDice == 7) {
                gameStatus = LOST;     // Rolling a 7 before making point → loss
            }
        }

        // Update total number of rolls across all games
        totalRolls += rollCount;

        // If rolls exceed MAX_ROLLS_TRACKED, bucket them into "After 20"
        if (rollCount > MAX_ROLLS_TRACKED) rollCount = MAX_ROLLS_TRACKED + 1;

        // Update statistics based on result
        if (gameStatus == WON) {
            ++totalWins;
            ++winsPerRoll[rollCount];
        } else {
            ++totalLosses;
            ++lossesPerRoll[rollCount];
        }
    }
}

// Display results after simulation
void CrapsGameStats::displayStatistics() const {
    std::cout << "Craps Game Statistics after " << NUM_GAMES << " games:\n\n";

    // Show wins distribution by roll
    std::cout << "Wins by roll:\n";
    for (int i = 1; i <= MAX_ROLLS_TRACKED; ++i) {
        std::cout << " Roll " << i << ": " << winsPerRoll[i] << '\n';
    }
    std::cout << " After 20: " << winsPerRoll[MAX_ROLLS_TRACKED + 1] << "\n\n";

    // Show losses distribution by roll
    std::cout << "Losses by roll:\n";
    for (int i = 1; i <= MAX_ROLLS_TRACKED; ++i) {
        std::cout << " Roll " << i << ": " << lossesPerRoll[i] << '\n';
    }
    std::cout << " After 20: " << lossesPerRoll[MAX_ROLLS_TRACKED + 1] << "\n\n";

    // Calculate and display statistics
    double winChance = static_cast<double>(totalWins) / NUM_GAMES * 100.0;
    double avgLength = static_cast<double>(totalRolls) / NUM_GAMES;

    std::cout << "Total Wins: " << totalWins << "\n";
    std::cout << "Total Losses: " << totalLosses << "\n";
    std::cout << "Chances of winning: " << winChance << "%\n";
    std::cout << "Average game length: " << avgLength << " rolls\n";
}

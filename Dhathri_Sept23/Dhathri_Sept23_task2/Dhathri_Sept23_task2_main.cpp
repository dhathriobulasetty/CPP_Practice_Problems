#include "Dhathri_Sept23_task2_CrapsGame.h"  

int main() {
    // Create an object of CrapsGameStats
    CrapsGameStats gameStats;

    // Run the simulation for NUM_GAMES (1000 by default)
    gameStats.simulateGames();

    // Display the results (wins, losses, probabilities, average rolls, etc.)
    gameStats.displayStatistics();

    return 0;  
}

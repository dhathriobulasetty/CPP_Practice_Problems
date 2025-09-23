#include "Dhathri_Sept23_task4_TurtleGraphics.h"
#include <iostream>

// Constructor initializes floor to false, pen up, position at (0,0), facing east
TurtleGraphics::TurtleGraphics()
    : x(0), y(0), direction(0), penDown(false) {
    for (auto& row : floor) {
        row.fill(false);
    }
}

// Processes the list of commands
void TurtleGraphics::processCommands(const std::vector<std::pair<int, int>>& commands) {
    for (const auto& cmd : commands) {
        int command = cmd.first;
        int value = cmd.second;

        switch (command) {
            case 1: // Pen up
                penDown = false;
                break;
            case 2: // Pen down
                penDown = true;
                break;
            case 3: // Turn right
                direction = (direction + 1) % 4;
                break;
            case 4: // Turn left
                direction = (direction + 3) % 4; // equivalent to -1 mod 4
                break;
            case 5: // Move forward
                moveForward(value);
                break;
            case 6: // Print floor
                printFloor();
                break;
            case 9: // End of data
                return;
            default:
                std::cout << "Invalid command: " << command << '\n';
        }
    }
}

// Moves the turtle forward by given steps
void TurtleGraphics::moveForward(int steps) {
    for (int i = 0; i < steps; ++i) {
        // Mark position if pen is down
        if (penDown && x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            floor[y][x] = true;
        }

        // Move one step in current direction
        switch (direction) {
            case 0: if (x + 1 < SIZE) ++x; break; // East
            case 1: if (y + 1 < SIZE) ++y; break; // South
            case 2: if (x - 1 >= 0) --x; break;   // West
            case 3: if (y - 1 >= 0) --y; break;   // North
        }
    }
}

// Prints the floor grid
void TurtleGraphics::printFloor() const {
    for (const auto& row : floor) {
        for (bool cell : row) {
            std::cout << (cell ? '*' : ' ');
        }
        std::cout << '\n';
    }
    std::cout << "----------------------\n";
}

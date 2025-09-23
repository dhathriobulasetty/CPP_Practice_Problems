#include "Dhathri_Sept23_task4_TurtleGraphics.h"
#include <vector>

int main() {
    TurtleGraphics turtle;

    // Example program: draw a 12x12 square
    std::vector<std::pair<int, int>> commands = {
        {2, 0},     // pen down
        {5, 12},    // move forward 12
        {3, 0},     // turn right
        {5, 12},    // move forward 12
        {3, 0},     // turn right
        {5, 12},    // move forward 12
        {3, 0},     // turn right
        {5, 12},    // move forward 12
        {1, 0},     // pen up
        {6, 0},     // print floor
        {9, 0}      // end of data
    };

    turtle.processCommands(commands);

    return 0;
}

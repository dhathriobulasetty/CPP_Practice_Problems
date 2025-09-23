#ifndef TURTLEGRAPHICS_H
#define TURTLEGRAPHICS_H

#include <array>
#include <vector>

// Class simulates turtle graphics sketchpad
class TurtleGraphics {
private:
    static const int SIZE = 20;              // floor size
    std::array<std::array<bool, SIZE>, SIZE> floor; // 20x20 floor grid
    int x, y;                                // current position of turtle
    int direction;                           // 0=East, 1=South, 2=West, 3=North
    bool penDown;                            // pen state

    void moveForward(int steps);             // helper function for command 5

public:
    TurtleGraphics();                        // constructor initializes floor and turtle
    void processCommands(const std::vector<std::pair<int, int>>& commands);
    void printFloor() const;                 // display current drawing
};

#endif // TURTLEGRAPHICS_H

#ifndef MAZETRAVERSAL_H
#define MAZETRAVERSAL_H

#include <iostream>
#include <array>

// Maze size constants
constexpr int MAZE_ROWS = 12;
constexpr int MAZE_COLS = 12;

// Function declarations
void printMaze(const std::array<std::array<char, MAZE_COLS>, MAZE_ROWS>& maze);
bool mazeTraverse(std::array<std::array<char, MAZE_COLS>, MAZE_ROWS>& maze, int row, int col, int startRow, int startCol);

#endif 

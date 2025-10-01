#include "Dhathri_Sept30_task3_MazeTraversal.h"

// Function to display the maze
void printMaze(const std::array<std::array<char, MAZE_COLS>, MAZE_ROWS>& maze)
{
    for (int i = 0; i < MAZE_ROWS; ++i)
    {
        for (int j = 0; j < MAZE_COLS; ++j)
        {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "--------------------------------------\n";
}

// Recursive function to traverse the maze
bool mazeTraverse(std::array<std::array<char, MAZE_COLS>, MAZE_ROWS>& maze, int row, int col, int startRow, int startCol)
{
    // Mark current position
    maze[row][col] = 'X';
    printMaze(maze);

    // Check if exit is found (on boundary but not starting point)
    if ((row == 0 || row == MAZE_ROWS - 1 || col == 0 || col == MAZE_COLS - 1) &&
        !(row == startRow && col == startCol))
    {
        std::cout << "Maze solved! Exit found at (" << row << ", " << col << ")\n";
        return true;
    }

    // Movement order: down, right, up, left (wall-following strategy)
    static const int moveRow[] = {1, 0, -1, 0};
    static const int moveCol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i)
    {
        int nextRow = row + moveRow[i];
        int nextCol = col + moveCol[i];

        // Check if next move is valid
        if (nextRow >= 0 && nextRow < MAZE_ROWS &&
            nextCol >= 0 && nextCol < MAZE_COLS &&
            maze[nextRow][nextCol] == '.')
        {
            if (mazeTraverse(maze, nextRow, nextCol, startRow, startCol))
            {
                return true;
            }
        }
    }

    // Backtrack
    return false;
}

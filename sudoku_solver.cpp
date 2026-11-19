
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 9;

// Display the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    cout << "\n========== SUDOKU GRID ==========\n";

    for (int row = 0; row < SIZE; row++) {

        if (row % 3 == 0 && row != 0) {
            cout << "------+-------+------\n";
        }

        for (int col = 0; col < SIZE; col++) {

            if (col % 3 == 0 && col != 0) {
                cout << "| ";
            }

            if (grid[row][col] == 0) {
                cout << ". ";
            } else {
                cout << grid[row][col] << " ";
            }
        }

        cout << endl;
    }
}

// Check whether a number can be placed
bool isSafe(int grid[SIZE][SIZE],
            int row, int col, int num) {

    // Check row
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Find an empty cell
bool findEmptyCell(int grid[SIZE][SIZE],
                   int &row, int &col) {

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {

            if (grid[row][col] == 0) {
                return true;
            }
        }
    }

    return false;
}

// Validate the initial Sudoku puzzle
bool isValidGrid(int grid[SIZE][SIZE]) {

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            int num = grid[row][col];

            if (num < 0 || num > 9) {
                return false;
            }

            if (num != 0) {

                grid[row][col] = 0;

                bool valid = isSafe(grid, row, col, num);

                grid[row][col] = num;

                if (!valid) {
                    return false;
                }
            }
        }
    }

    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {

    int row, col;

    // If no empty cell exists, puzzle is solved
    if (!findEmptyCell(grid, row, col)) {
        return true;
    }

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num;

            // Recursive call
            if (solveSudoku(grid)) {
                return true;
            }

            // Backtracking
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int grid[SIZE][SIZE];

    cout << "====================================\n";
    cout << "       SUDOKU SOLVER IN C++\n";
    cout << "====================================\n";

    cout << "\nEnter the Sudoku puzzle (9 x 9).\n";
    cout << "Enter 0 for empty cells.\n\n";

    // Get Sudoku input
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            if (!(cin >> grid[row][col])) {
                cout << "Invalid input!\n";
                return 0;
            }
        }
    }

    cout << "\nOriginal Sudoku:";
    printGrid(grid);

    // Check initial puzzle
    if (!isValidGrid(grid)) {
        cout << "\nInvalid Sudoku puzzle!\n";
        return 0;
    }

    // Solve the puzzle
    if (solveSudoku(grid)) {

        cout << "\nSudoku solved successfully!\n";

        cout << "\nSolved Sudoku:";
        printGrid(grid);

    } else {

        cout << "\nNo solution exists for this Sudoku puzzle.\n";
    }

    return 0;
}

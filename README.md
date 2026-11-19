# CodeAlpha_Sudoku_Solver-
Sudoku Solver using C++ and Backtracking Algorithm

# CodeAlpha Sudoku Solver

## Project Overview

The Sudoku Solver is a C++ application that
solves Sudoku puzzles automatically using the
Backtracking Algorithm.

It uses recursion to find the correct numbers
while following Sudoku rules.

## Features

- 9x9 Sudoku grid representation.
- User input for Sudoku puzzles.
- Empty cells represented by 0.
- Row validation.
- Column validation.
- 3x3 subgrid validation.
- Recursive backtracking algorithm.
- Displays the solved Sudoku puzzle.
- Detects invalid and unsolvable puzzles.

## Technologies Used

- C++
- 2D Arrays
- Functions
- Recursion
- Backtracking Algorithm

## Algorithm Used

Backtracking is used to solve the Sudoku puzzle.

1. Find an empty cell.
2. Try numbers from 1 to 9.
3. Check whether the number is valid.
4. Place the number if it follows Sudoku rules.
5. Recursively solve the remaining cells.
6. Backtrack if no valid number works.
7. Continue until the puzzle is solved.

## How to Run

1. Download the source code.
2. Open it in a C++ compiler.
3. Compile the program.
4. Enter the Sudoku puzzle.
5. Use 0 for empty cells.
6. Run the program to get the solution.

## Sample Input

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

## Expected Output

Sudoku solved successfully!

## Author

Nandika S.K

## Internship

CodeAlpha C++ Programming Internship

Website: https://www.codealpha.tech/


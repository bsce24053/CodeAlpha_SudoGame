#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class SudokuSolver {
private:
    int board[9][9];

    bool findEmptyCell(int &row, int &col) {
        for (row = 0; row < 9; row++) {
            for (col = 0; col < 9; col++) {
                if (board[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isValid(int row, int col, int num) {

        // Check Row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }

        // Check Column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }

        // Check 3x3 Box
        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

public:

    void inputBoard() {
        cout << "Enter Sudoku Grid (9x9)\n";
        cout << "Use 0 for empty cells:\n";

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }
    }

    void displayBoard() {
        cout << "\nSolved Sudoku:\n\n";

        for (int i = 0; i < 9; i++) {

            if (i % 3 == 0 && i != 0)
                cout << "-------------------------\n";

            for (int j = 0; j < 9; j++) {

                if (j % 3 == 0 && j != 0)
                    cout << "| ";

                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool solveSudoku() {

        int row, col;

        if (!findEmptyCell(row, col)) {
            return true;
        }

        for (int num = 1; num <= 9; num++) {

            if (isValid(row, col, num)) {

                board[row][col] = num;

                if (solveSudoku()) {
                    return true;
                }

                board[row][col] = 0;
            }
        }

        return false;
    }
};

#endif
#include "functions.h"

int main() {

    SudokuSolver sudoku;

    sudoku.inputBoard();

    if (sudoku.solveSudoku()) {
        sudoku.displayBoard();
    }
    else {
        cout << "No Solution Exists!" << endl;
    }

    return 0;
}
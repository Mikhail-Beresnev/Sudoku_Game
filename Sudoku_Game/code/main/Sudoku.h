#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
using namespace std;

/*
int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
                     {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
                     {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
                     {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
                     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
 */

class Sudoku {
public:
  Sudoku(int board[9][9]); // COMPLETE
  void drawBoard();        // COMPLETE

protected:
  int board[9][9];         // contains playable game board
  int originalBoard[9][9];  // player cannot change original values
  int solutionBoard[9][9]; // contains solution to game
};

#endif
/*
Project 3 : Sudoku
-------------------
Developers:
- Jared Ballance
- Jared Evans
- Mikhail Beresnev
 */

#include "GeneratingSudokuBoard.h"
#include "SolvingAlgorithm.h"
#include "Sudoku.h"
#include "userInterface.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  //   int testBoard[9][9] = {
  //       {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
  //       {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
  //       {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
  //       {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
  //       {0, 0, 0, 0, 8, 0, 0, 7, 9}};
  //   Sudoku newGame(testBoard);
  //   newGame.drawBoard();

  // Mikhail's tests
  //   SolvingAlgorithm test(testBoard);
  //   pair<int, int> xy = make_pair(2, 0);
  //   test.checkOptions(xy);
  //   xy = make_pair(1, 1);
  //   test.checkOptions(xy);
  //   xy = make_pair(2, 1);
  //   test.checkOptions(xy);
  //   xy = make_pair(0, 2);
  //   test.checkOptions(xy);

  //  SolvingAlgorithm test(testBoard);
  //  test.solvingAlgorithm();

  int difficultyLevel = 0;
  int totalGameDigits = 0;
  int board[9][9];

  entryScreen game(board, difficultyLevel, totalGameDigits);
  game.start();
  return 0;
}
// Test Driver for the Solver
/*
#include "GeneratingSudokuBoard.h"
#include "SolvingAlgorithm.h"
#include "Sudoku.h"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
  int testBoard[9][9] = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  Sudoku newGame(testBoard);
  cout << "Test Board:\n";
  newGame.drawBoard();

  cout << "Test Solver:\n" << endl;
  Solver test(testBoard);
  pair<int, int> xy;
  xy = make_pair(0, 0);
  test.checkOptions(xy);
  xy = make_pair(1, 0);
  test.checkOptions(xy);
  xy = make_pair(2, 0);

  test.checkOptions(xy);
  xy = make_pair(0, 1);
  test.checkOptions(xy);
  xy = make_pair(1, 1);
  test.checkOptions(xy);
  xy = make_pair(2, 1);
  test.checkOptions(xy);

  xy = make_pair(0, 2);
  test.checkOptions(xy);
  xy = make_pair(1, 2);
  test.checkOptions(xy);
  xy = make_pair(2, 2);
  test.checkOptions(xy);
  cout << endl;

  test.solveSudoku();
  test.drawBoard();

  cout << endl;
  cout << "Test Generator:\n";

  int difficultyLevel = 3;
  int totalGameDigits = 0;
  int board[9][9];

  cout << "Testing Difficulty Level 3- Hard (21 Digits)\n";

  GeneratingSudokuBoard generator(board, difficultyLevel, totalGameDigits);
  generator.gameDifficulty(difficultyLevel);
  //   generator.generatingBoardFunctions();
  //   cout << "Number of digits for Level 3- Hard: "
  //        << generator.gameDifficulty(difficultyLevel) << endl;
  assert(generator.gameDifficulty(difficultyLevel) == 21);

  cout << "Printing board of Hard difficulty:\n";
  generator.setSolutionBoard();
  generator.setPlayableGameBoard(totalGameDigits);
  generator.drawBoard(); // prints out playable game board
}
*/
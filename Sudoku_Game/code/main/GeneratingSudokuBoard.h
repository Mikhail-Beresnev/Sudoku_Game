/*************************************************************************
 *
 * Project 3: Create Sudoku Generating Algorithm
 *
 * File Name:       GeneratingSudokuBoard.h
 * Course:          CPTR 142
 *
 */
#ifndef GENERATINGSUDOKUBOARD_H
#define GENERATINGSUDOKUBOARD_H
#include "SolvingAlgorithm.h"
// #include "checkingFunction.h"
#include <cstdlib>
#include <iostream>

class GeneratingSudokuBoard : public Solver {
public:
  GeneratingSudokuBoard(int board[9][9], int difficultyLevel,
                        int totalGameDigits)
      : Solver(board) {

    this->difficultyLevel = difficultyLevel;
    this->totalGameDigits = totalGameDigits;
  }
  void generatingBoardFunctions(); // uses all functions to create game board
  void requestGameDifficulty();
  int gameDifficulty(int); // takes in difficulty, returns totalGameDigits
  void setSolutionBoard();
  void setPlayableGameBoard(
      int totalGameDigits); // sets board based on difficulty level chosen

protected:
  int totalGameDigits = 0;
  int removeDigits = 0;
  int difficultyLevel = 0;
};

#endif // GENERATINGSUDOKUBOARD_H
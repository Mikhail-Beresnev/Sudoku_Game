#ifndef USERINTERFACE_H
#define USERINTERFACE_H

// #include "GeneratingSudokuBoard.h"
// #include "Sudoku.h"
#include "checkingFunction.h"
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

class entryScreen : public checkingFunction {
public:
  entryScreen(int board[9][9], int difficultyLevel, int totalGameDigits)
      : checkingFunction(board, difficultyLevel, totalGameDigits) {
  }             // constructor
  void start(); // starts program
  pair<int, int>
  askForPosition();        // gets position from user to place number on board
  int requestInputValue(); // gets number from user to put on board
  void placeInputValue();  // places number on board
  void playGame();    // plays game until board is full, using 3 functions above
  void importBoard(); //
  int printStartingOptions(); // gives all player options
  int solveOrPlay();          // player chooses to play or have board solved
  void
  solveOrPlayChoice(bool flag);  // takes in and implements choice from above function
  int gameEndOptions(); // player chooses what to do at end of game
  void
  gameEndOptionsChoice(); // takes in and implements choice form above function
  int checkOpenSlots();

private:
  pair<int, int> xy; // pair for choice by player
  int playerSolution;
  int openSlots;
};

#endif
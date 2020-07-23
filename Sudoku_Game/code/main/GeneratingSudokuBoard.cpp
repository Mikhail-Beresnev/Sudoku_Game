/*************************************************************************
 *
 * Project 3: Create Sudoku Generating Algorithm
 *
 * File Name:       GeneratingSudokuBoard.cpp
 * Course:          CPTR 142
 *
 */

#include "GeneratingSudokuBoard.h"
#include "SolvingAlgorithm.h"
#include "Sudoku.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>

using namespace std;

void GeneratingSudokuBoard::generatingBoardFunctions() { // calls all function
                                                         // in one
  requestGameDifficulty();
  setSolutionBoard();
  setPlayableGameBoard(totalGameDigits);
}

void GeneratingSudokuBoard::requestGameDifficulty() {
  // GeneratingSudokuBoard Game(board, difficultyLevel, totalGameDigits);
  difficultyLevel = 0;
  cout << "Choose game difficulty level:\n"; // asks for user input
  cout << "1. Easy (27 digits)\n";
  cout << "2. Medium (24 digits)\n";
  cout << "3. Hard (21 digits)\n";
  cout << "4. Extreme (17 digits)\n";
  cout << "5. Custom\n";

  while (((difficultyLevel < 1) || (difficultyLevel > 5)) ||
         ((totalGameDigits < 17) || (totalGameDigits > 77))) {
    try {
      if (difficultyLevel == 5) {
        totalGameDigits = gameDifficulty(difficultyLevel);
        // totalGameDigits = Game.gameDifficulty(difficultyLevel);
      } else {
        cout << "Difficulty Level: ";
        cin >> difficultyLevel;

        if (cin.fail()) {
          cin.clear(); // error checking to make sure the user does not break
                       // the program
          cin.ignore(1000, '\n');
          // dont' need cerr because it will get thrown as empty output in
          // switch default
        }
        totalGameDigits = gameDifficulty(difficultyLevel);
        // totalGameDigits = Game.gameDifficulty(difficultyLevel);
      }
    } catch (runtime_error &error) { // catches error if invalid input
      cout << error.what() << endl;
    }
  }
  cout << "Total digits for chosen game difficulty: " << totalGameDigits
       << endl;
}

int GeneratingSudokuBoard::gameDifficulty(int difficultyLevel) {
  switch (difficultyLevel) {
  case 1: // easy
    totalGameDigits = 27;
    break;
  case 2: // medium
    totalGameDigits = 24;
    break;
  case 3: // hard
    totalGameDigits = 21;
    break;
  case 4: // extreme
    totalGameDigits = 17;
    break;
  case 5: // custom
    // (77)maximum & (17)minimum values capable of generating unique puzzle
    cout << "Enter number digits for unique game board (17-77): ";
    cin >> totalGameDigits;
    if ((totalGameDigits < 17) || (totalGameDigits > 77)) {
      throw runtime_error("Invalid Entry");
    }
    break;
  default: // all other input is invalid and is thrown
    throw runtime_error("Invalid Entry");
    break;
  }

  return totalGameDigits;
}

void GeneratingSudokuBoard::setSolutionBoard() {
  srand(time(NULL));
  int x;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = 0;
    }
  } // set board to all 0's

  x = rand() % 9 + 1;
  board[rand() % 9][rand() % 9] = x;

  solver();

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      solutionBoard[i][j] = board[i][j];
    }
  }
}

void GeneratingSudokuBoard::setPlayableGameBoard(
    int removeDigits) { // removes removeDigits number of digits from full board
  srand(time(NULL));
  int x, y;
  removeDigits = 81 - totalGameDigits;
  //   cout << removeDigits << endl; // FOR TESTING PURPOSES

  while (solver() == false) {
    solver();
  }

  for (int i = 0; i < removeDigits;) {
    x = rand() % 9;
    y = rand() % 9;
    if (board[x][y] != 0) {
      board[x][y] = 0;
      i++; // only counts iteration if valid entry on board
    } else {
      continue;
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      originalBoard[i][j] = board[i][j];
    }
  }
}
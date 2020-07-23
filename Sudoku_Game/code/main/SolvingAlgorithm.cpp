#include "SolvingAlgorithm.h"
#include <set>

Solver::Solver(int board[9][9]) : Sudoku{board} {}

void Solver::solveSudoku() {
  // board [y axis] [x axis]

  // Runs the solver
  if (solver() == true) {
  } else {
    cout << "Solution does not exsist" << endl;
  }
}

vector<int> Solver::checkOptions(pair<int, int> position) {
  set<int> temp;
  vector<int> options;

  // Determine the constants for the row
  for (int i = 0; i < 9; i++) {
    if (board[position.second][i] != 0) {
      temp.emplace(board[position.second][i]);
    }
  }
  // Determine the constants for the column
  for (int i = 0; i < 9; i++) {
    if (board[i][position.first] != 0) {
      temp.emplace(board[i][position.first]);
    }
  }

  // Determine the constants for the box

  // Determine the box location
  int boxX = position.first - (position.first % 3);
  int boxY = position.second - (position.second % 3);

  for (int i = boxX; i < (boxX + 3); i++) {
    for (int j = boxY; j < (boxY + 3); j++) {
      if (board[j][i] != 0) {
        temp.emplace(board[j][i]);
      }
    }
  }
  // Gets the options by not transfering the constants into vector
  for (int i = 1; i <= 9; i++) {
    if (temp.count(i) == 0) {
      options.push_back(i);
    }
  }
  return options;
}

bool Solver::solver() {
  pair<int, int> position;
  // Looks for a position that is not filled
  if (checkCompletion(position)) {
    return true;
  }

  // tests numbers from 1 - 9 for that position and recurses
  for (int i = 1; i < 10; i++) {

    if (!checkContradiction(position, i)) {

      board[position.second][position.first] = i;

      if (solver()) {
        return true;
      }
      board[position.second][position.first] = 0;
    }
  }
  // If something goes wrong, then it will go back into the for loop on the
  // previous recursion and try a different value
  return false;
}

bool Solver::checkCompletion(pair<int, int> &position) {
  // Main method of going through the board

  // Looks throughout the entire board for an open position and by reference,
  // sets the position to be used to that open space
  for (position.second = 0; position.second < 9; position.second++) {
    for (position.first = 0; position.first < 9; position.first++) {
      if (board[position.second][position.first] == 0) {
        return false;
      }
    }
  }
  return true;
}

bool Solver::checkContradiction(pair<int, int> position, int number) {
  // If the number is an option that can be placed into the position, pass the
  // check
  vector<int> options = checkOptions(position);
  if (board[position.second][position.first] != 0) {
    return true;
  }
  for (int i = 0; i < options.size(); i++) {
    if (options.at(i) == number) {
      return false;
    }
  }
  // Otherwise, fail the check
  return true;
}
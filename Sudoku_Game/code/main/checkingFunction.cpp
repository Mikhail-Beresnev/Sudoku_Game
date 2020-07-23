#include "checkingFunction.h"
#include <set>

checkingFunction::checkingFunction(int board[9][9], int difficultyLevel,
                                   int totalGameDigits)
    : GeneratingSudokuBoard(board, difficultyLevel, totalGameDigits) {}

bool checkingFunction::checkBoard() {
  // Checks the board for a valid solution
  // If there is a problem with the board (duplicate use of a number in a box,
  // row, or column, returns false)

  // Makes sure that there are no empty slots
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }

  // Check the 9 boxes
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (!checkBox(make_pair(i, j))) {
        return false;
      }
    }
  }
  // check the rows
  for (int i = 0; i < 9; i++) {
    if (!checkRow(make_pair(i, 0))) {
      return false;
    }
  }
  // check the columns
  for (int i = 0; i < 9; i++) {
    if (!checkColumn(make_pair(0, i))) {
      return false;
    }
  }
  // If there was no duplicates, pass the check
  return true;
}

bool checkingFunction::checkBox(pair<int, int> position) {
  // Find the position of the box
  int boxX = position.first * 3;
  int boxY = position.second * 3;
  vector<int> box;
  // turn a 2d array into a vector
  for (int i = boxX; i < (boxX + 3); i++) {
    for (int j = boxY; j < (boxY + 3); j++) {
      box.push_back(board[i][j]);
    }
    // cout << "set: " << i << endl;
  }
  set<int> boxTest;
  // transfer the vector into a set for unique values
  for (int i = 0; i < box.size(); i++) {
    boxTest.emplace(box.at(i));
  }
  // check to see if the size of the vector and the set is the same

  // Idea is that if the set size is not equal to the vector size, it means that
  // one of the values in the vector is not unique
  if (boxTest.size() != box.size()) {
    return false;
  } else {
    return true;
  }
}

bool checkingFunction::checkColumn(pair<int, int> position) {
  vector<int> column;
  // turn a 2d array into a vector
  for (int i = 0; i < 9; i++) {
    column.push_back(board[i][position.first]);
  }
  set<int> columnTest;
  // transfer the vector into a set for unique values
  for (int i = 0; i < column.size(); i++) {
    columnTest.emplace(column.at(i));
  }
  // check to see if the size of the vector and the set is the same
  if (columnTest.size() != column.size()) {
    return false;
  } else {
    return true;
  }
}

bool checkingFunction::checkRow(pair<int, int> position) {
  vector<int> row;
  // turn a 2d array into a vector
  for (int i = 0; i < 9; i++) {
    row.push_back(board[position.second][i]);
  }
  set<int> rowTest;
  // transfer the vector into a set for unique values
  for (int i = 0; i < row.size(); i++) {
    rowTest.emplace(row.at(i));
  }
  // check to see if the size of the vector and the set is the same
  if (rowTest.size() != row.size()) {
    return false;
  } else {
    return true;
  }
}
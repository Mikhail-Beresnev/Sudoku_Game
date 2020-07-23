#ifndef CHECKINGFUNCTION_H
#define CHECKINGFUNCTION_H

#include "GeneratingSudokuBoard.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class checkingFunction : public GeneratingSudokuBoard {
public:
  checkingFunction(int board[9][9], int difficultyLevel, int totalGameDigits);
  bool checkBoard();
  bool checkBox(pair<int, int> position);
  bool checkColumn(pair<int, int> position);
  bool checkRow(pair<int, int> position);

private:
};
#endif
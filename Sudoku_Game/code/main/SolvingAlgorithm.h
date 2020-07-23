#ifndef SOLVINGALGORITHM_H
#define SOLVINGALGORITHM_H

#include "Sudoku.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solver : public Sudoku {
public:
  Solver(int board[9][9]); 
  void solveSudoku();
  bool solver(); 
  bool checkCompletion(pair<int, int> &position); 
  vector<int> checkOptions(pair<int, int> position); 
  bool checkContradiction(pair<int, int> position, int number); 

private:
};

#endif
#include "Sudoku.h"
#include <iostream>

using namespace std;

// COMPLETE
Sudoku::Sudoku(int board[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      this->board[i][j] = board[i][j];
    }
  }
}

// COMPLETE

void Sudoku::drawBoard() {

  cout << "=";
  for (int i = 1; i < 36; i++) {
    if (i % 12 == 0) {
      cout << "+";
    } else {
      cout << "=";
    }
  }
  cout << "=";
  cout << endl;
  for (int i = 0; i < 9; i++) {
    cout << "|";
    for (int j = 0; j < 9; j++) {
      cout << " ";
      if (board[i][j] == 0) {
        cout << " ";
      } else {
        cout << board[i][j];
      }
      cout << " "
           << "|";
    }
    cout << endl;
    for (int k = 0; k < 36; k++) {
      if ((i + 1) % 3 == 0 && k % 12 == 0 && k != 0) {
        cout << "+";
      } else if ((i + 1) % 3 == 0) {
        cout << "=";
      } else if (k % 12 == 0) {
        cout << "|";
      } else {
        cout << "-";
      }
    }
    if ((i + 1) % 3 == 0) {
      cout << "=" << endl;
    } else {
      cout << "|" << endl;
    }
  }
}

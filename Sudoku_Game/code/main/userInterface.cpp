#include "userInterface.h"
// #include "Sudoku.h"
// #include "checkingFunction.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Asks for position
void entryScreen::start() {
  switch (printStartingOptions()) {
  case 1:
    generatingBoardFunctions(); // creates game
    drawBoard();                // gives player generated game board
    solveOrPlayChoice(false);   // asks to play or solve board
    break;
  case 2:
    importBoard(); // imports board form importedSudoku.txt
    solver();      // sets solution board
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        solutionBoard[i][j] = board[i][j];
        board[i][j] = originalBoard[i][j];
      }
    }
    drawBoard();              // prints board from .txt file
    solveOrPlayChoice(false); // asks to play or solve board
    break;
  case 3:
    abort(); // ends program immediately
    break;
  }
}

void entryScreen::importBoard() {
  cout << "To import board, input 9x9 array in importedSudoku.txt file, with "
          "blanks input as 0.\n";
  cout << "(Be sure to include one space between each number for correct board "
          "setup.)\n";

  ifstream fin;
  char restart;

  fin.open("importedSudoku.txt");
  if (!fin.is_open()) {
    cerr << "Error! File failed to open." << endl;
    cerr << "Enter \'y\' to restart the program or any other character to quit:"
         << endl;
    cin >> restart;
    if (restart == 'y') {
      importBoard(); // calls restart program when file fails to open
    } else {
      abort(); // ends program immediately
    }
  }

  int i = 0, j = 0;
  int sudoku;

  while (fin >> sudoku) { // sets originalBoard from .txt file
    originalBoard[i][j] = sudoku;
    j++;
    if (j == 9) {
      j = 0;
      i++;
    }
  }

  fin.close();
}

int entryScreen::printStartingOptions() {
  int choice = 0; // gives player options to start
  cout << "Choose game option:\n";
  cout << "1. Generate New Game\n";
  cout << "2. Import Game (.txt file)\n";
  cout << "3. Quit\n";

  while ((choice < 1) || (choice > 3)) {
    try {
      cout << "Choice: ";
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw runtime_error("Invalid Input");
      } else if ((choice < 1) || (choice > 3)) {
        throw runtime_error("Invalid Input");
      }
    } catch (runtime_error &error) {
      cout << error.what() << endl;
    }
  } // restarts if invalid input

  return choice;
}

int entryScreen::solveOrPlay() {
  int choice = 0;
  cout << "Choose game option:\n";
  cout << "1. Play Game\n";
  cout << "2. Auto Solve Board\n";
  while ((choice < 1) || (choice > 2)) {
    try {
      cout << "Choice: ";
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw runtime_error("Invalid Input");
      } else if ((choice < 1) || (choice > 3)) {
        throw runtime_error("Invalid Input");
      }
    } catch (runtime_error &error) {
      cout << error.what() << endl;
    }
  }
  return choice;
}

int entryScreen::checkOpenSlots() {
  int openSlots = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        openSlots++;
      } // finds number of empty slots on board
    }
  }
  return openSlots;
}

void entryScreen::solveOrPlayChoice(bool flag) {
  string giveUp = "";

  switch (solveOrPlay()) {
  case 1: // plays game until there are no empty slots
    openSlots = checkOpenSlots();
    if (flag == true) {
      openSlots = 1;
    }
    // checks number of open slots after each input
    while (openSlots > 0) {
      cout << "(Enter -1 to give up or any other key to continue): ";
      cin >> giveUp;
      if (giveUp == "-1") {
        openSlots = 0;
        solver();
        drawBoard();
      } else {
        playGame();
        openSlots = checkOpenSlots();
      }
    }
    if (checkBoard()) {
      cout << "Congratulations! You have correctly solved the board.\n";
    } else {
      cout << "Your solution is incorrect\n";
      solveOrPlayChoice(true);
    }
    gameEndOptionsChoice(); // prints options when game is over
    break;

  case 2:
    solver();               // solves board
    drawBoard();            // prints solved board
    gameEndOptionsChoice(); // prints options when game is over
    break;
  }
}

void entryScreen::playGame() {
  askForPosition();
  while (originalBoard[xy.first][xy.second] != 0) {
    cout << "You cannot change original values\n";
    askForPosition();
  } // player can only change numbers not given at begining
  placeInputValue();
  drawBoard();
}

pair<int, int> entryScreen::askForPosition() {
  xy.first = 0;
  xy.second = 0;
  cout << "What is your position?:\n";

  while ((xy.second < 1) || (xy.second > 9)) {
    cout << "Column (x): "; // gets input until valid
    cin >> xy.second;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cerr << "Invalid Input"; // generate error with invalid input
    } else if ((xy.second < 1) || (xy.second > 9)) {
      cout << "Your number must be within numbers 1-9";
    }
  }
  xy.second -= 1; // -1 for correct index on board

  while ((xy.first < 1) || (xy.first > 9)) {
    cout << "Row (y): "; // gets input until valid
    cin >> xy.first;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cerr << "Invalid Input"; // generate error with invalid input
    } else if ((xy.first < 1) || (xy.first > 9)) {
      cout << "Your number must be within numbers 1-9";
    }
  }
  xy.first -= 1; // -1 for correct index on board

  return xy;
}

int entryScreen::requestInputValue() { // Asks for input values
  int inputValue = -1;
  while ((inputValue < 0) || (inputValue > 9)) {
    cout << "Choose input between 0-9: ";
    cin >> inputValue;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cerr << "Invalid Input";
    } else if ((inputValue < 0) || (inputValue > 9)) {
      cout << "Your number must be within numbers 0-9";
    }
  }

  return inputValue;
}

void entryScreen::placeInputValue() {
  board[xy.first][xy.second] = requestInputValue();
} // sets board value bases on inputValue;

int entryScreen::gameEndOptions() {
  int choice = 0; // gives options when game is over
  cout << "Choose game option:\n";
  cout << "1. Play New Game\n";
  cout << "2. Restart Last Game\n";
  cout << "3. Quit\n";
  while ((choice < 1) || (choice > 3)) {
    try {
      cout << "Choice: ";
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw runtime_error("Invalid Input");
      } else if ((choice < 1) || (choice > 3)) {
        throw runtime_error("Invalid Input");
      }
    } catch (runtime_error &error) {
      cout << error.what() << endl;
    } // runs again if invalid input
  }

  return choice;
}

void entryScreen::gameEndOptionsChoice() {
  switch (gameEndOptions()) {
  case 1:
    start(); // starts whole program over
    break;
  case 2:
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        board[i][j] = originalBoard[i][j];
      } // resets last game to playable board
    }
    drawBoard();
    solveOrPlayChoice(false);
    break;
  case 3:
    abort(); // ends all functions immediately
    break;
  }
}
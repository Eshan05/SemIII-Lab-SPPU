// * Eshan Nahar
// Write a C++ program to implement the game of 8 puzzle. Apply the concept of
// polymorphism.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Base class for generic puzzle
class Puzzle {
 public:
  virtual void display() = 0; // Pure virtual function to display the puzzle
  virtual bool
  move(int direction) = 0; // Pure virtual function to move the empty tile
  virtual bool
  isSolved() = 0; // Pure virtual function to check if the puzzle is solved
};

// Derived class for the 8-puzzle game
class EightPuzzle : public Puzzle {
 private:
  vector<vector<int>> board; // 2D vector to represent the puzzle board
  int emptyRow, emptyCol;    // Position of the empty tile

 public:
  // Constructor to initialize the puzzle
  EightPuzzle(vector<vector<int>> initialBoard) : board(initialBoard) {
    // Find the empty tile (represented by 0)
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        if(board[i][j] == 0) {
          emptyRow = i;
          emptyCol = j;
        }
      }
    }
  }

  void display() override {
    for(const auto &row : board) {
      for(int tile : row) {
        if(tile == 0) cout << "   "; // Print space for empty tile
        else cout << tile << "  ";
      }
      cout << endl;
    }
    cout << endl;
  }

  bool move(int direction) override {
    int newRow = emptyRow, newCol = emptyCol;

    // Determine new position of the empty tile based on direction
    switch(direction) {
      case 1: newRow--; break; // Up
      case 2: newRow++; break; // Down
      case 3: newCol--; break; // Left
      case 4: newCol++; break; // Right
      default: return false;   // Invalid direction
    }

    // Check if the move is within bounds
    if(newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
      swap(board[emptyRow][emptyCol], board[newRow][newCol]);
      emptyRow = newRow;
      emptyCol = newCol;
      return true;
    }
    return false; // Move not possible
  }

  bool isSolved() override {
    int expected = 1;
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        if(i == 2 && j == 2) {
          // Last tile should be 0
          if(board[i][j] != 0) return false;
        } else {
          if(board[i][j] != expected) return false;
          expected++;
        }
      }
    }
    return true;
  }
};

int main() {
  // Initial configuration of the 8-puzzle
  vector<vector<int>> initialBoard = { { 1, 2, 3 }, { 4, 0, 5 }, { 7, 8, 6 } };

  EightPuzzle puzzle(initialBoard);
  int direction;

  cout << "Welcome to the 8-Puzzle Game!\n";
  while(true) {
    puzzle.display();
    if(puzzle.isSolved()) {
      cout << "Congratulations! You solved the puzzle!\n";
      break;
    }

    cout << "Enter your move (1: Up, 2: Down, 3: Left, 4: Right): ";
    cin >> direction;

    if(!puzzle.move(direction)) { cout << "Invalid move. Please try again.\n"; }
  }

  return 0;
}

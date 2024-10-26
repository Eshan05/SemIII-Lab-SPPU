#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Base class for a generic game
class Game {
 public:
  virtual void displayBoard() = 0; // Pure virtual function to display the board
  virtual bool
  makeMove(int player,
           int position) = 0; // Pure virtual function for making a move
  virtual bool
  isWinner(int player) = 0;  // Pure virtual function to check for a winner
  virtual bool isDraw() = 0; // Pure virtual function to check for a draw
  virtual bool
  isGameOver() = 0; // Pure virtual function to check if the game is over
};

// Derived class for Tic Tac Toe game
class TicTacToe : public Game {
 private:
  vector<char> board; // 1D vector to represent the 3x3 board
  char currentPlayer; // Current player ('X' or 'O')

 public:
  TicTacToe()
      : board(9, ' '), currentPlayer('X') {
  } // Initialize board and set current player

  void displayBoard() override {
    cout << "Current Board:\n";
    for(int i = 0; i < 3; ++i) {
      cout << " " << board[i * 3] << " | " << board[i * 3 + 1] << " | "
           << board[i * 3 + 2] << " \n";
      if(i < 2) cout << "---|---|---\n";
    }
    cout << endl;
  }

  bool makeMove(int player, int position) override {
    char symbol = (player == 1) ? 'X' : 'O';
    if(position < 0 || position >= 9 || board[position] != ' ') {
      cout << "Invalid move. Try again.\n";
      return false;
    }
    board[position] = symbol;
    return true;
  }

  bool isWinner(int player) override {
    char symbol = (player == 1) ? 'X' : 'O';
    // Check rows, columns, and diagonals for a winner
    return (board[0] == symbol && board[1] == symbol &&
            board[2] == symbol) || // Row 1
           (board[3] == symbol && board[4] == symbol &&
            board[5] == symbol) || // Row 2
           (board[6] == symbol && board[7] == symbol &&
            board[8] == symbol) || // Row 3
           (board[0] == symbol && board[3] == symbol &&
            board[6] == symbol) || // Column 1
           (board[1] == symbol && board[4] == symbol &&
            board[7] == symbol) || // Column 2
           (board[2] == symbol && board[5] == symbol &&
            board[8] == symbol) || // Column 3
           (board[0] == symbol && board[4] == symbol &&
            board[8] == symbol) || // Diagonal 1
           (board[2] == symbol && board[4] == symbol &&
            board[6] == symbol); // Diagonal 2
  }

  bool isDraw() override { return count(board.begin(), board.end(), ' ') == 0; }

  bool isGameOver() override { return isWinner(1) || isWinner(2) || isDraw(); }

  void switchPlayer() { currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; }

  char getCurrentPlayer() { return currentPlayer; }
};

int main() {
  TicTacToe game;
  int position;

  cout << "Welcome to Tic Tac Toe!\n";

  while(!game.isGameOver()) {
    game.displayBoard();
    cout << "Player " << game.getCurrentPlayer() << ", enter your move (0-8): ";
    cin >> position;

    if(game.makeMove((game.getCurrentPlayer() == 'X') ? 1 : 2, position)) {
      if(game.isWinner((game.getCurrentPlayer() == 'X') ? 1 : 2)) {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << " wins!\n";
        break;
      }
      if(game.isDraw()) {
        game.displayBoard();
        cout << "It's a draw!\n";
        break;
      }
      game.switchPlayer();
    }
  }

  return 0;
}

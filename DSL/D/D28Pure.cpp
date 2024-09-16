#include <iostream>
using namespace std;

const int N = 3;
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (board[i][j] == 1) cout << "Q ";
      else cout << ". ";
    }
    cout << endl;
  }
  cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
  // Check column
  for (int i = 0; i < row; ++i) if (board[i][col] == 1) return false;
  // Check upper-left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) if (board[i][j] == 1) return false;
  // Check upper-right diagonal
  for (int i = row, j = col; i >= 0 && j < N; --i, ++j) if (board[i][j] == 1) return false;

  return true;
}

// Recursive
void solveNQueens(int board[N][N], int row, int &count) {
  if (row >= N) {
    printBoard(board);
    count++;
    return;
  }

  for (int col = 0; col < N; ++col) {
    if (isSafe(board, row, col)) {
      board[row][col] = 1; // Place the queen
      solveNQueens(board, row + 1, count);
      board[row][col] = 0; // Backtrack
    }
  }
}

int main() {
  int board[N][N] = { 0 };
  int count = 0;
  solveNQueens(board, 0, count);
  cout << "Total solutions: " << count << endl;
  return 0;
}
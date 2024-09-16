/**
 * * Eshan Nahar
 * * Like leetcode 51
 * A classic problem that can be solved by backtracking is called the Eight
 Queens problem, which comes from the game of chess. The chess board consists of
64 square arranged in an 8 by 8 grid. The board normally alternates between
black and white square, but this is not relevant for the present problem. The
queen can move as far as she wants in any direction, as long as she follows a
straight line, Vertically, horizontally, or diagonally. Write C++ program with
recursive function for generating all possible configurations for 4-queen's
problem.

*/

#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<int> &board) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board.size(); ++j) {
			if (board[j] == i) cout << "Q ";
			else cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(const vector<int> &board, int row, int col) {
	for (int prevRow = 0; prevRow < row; ++prevRow) {
		int prevCol = board[prevRow];
		// Check column and diagonals
		if (prevCol == col || prevCol - prevRow == col - row || prevCol + prevRow == col + row) return false;
	}
	return true;
}

void solveNQueens(vector<int> &board, int row, int &count) {
	int n = board.size();
	if (row == n) {
		printBoard(board);
		count++;
		return;
	}

	for (int col = 0; col < n; ++col) {
		if (isSafe(board, row, col)) {
			board[row] = col;
			solveNQueens(board, row + 1, count);
		}
	}
}

int main() {
	int n = 4;
	int count = 0;
	vector<int> board(n, -1);
	solveNQueens(board, 0, count);
	cout << "Total solutions: " << count << endl;
	return 0;
}

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct BoardState {
	vector<int> board; // Current board configuration
	int row;           // Current row to place a queen
};

// Function to print the board
void printBoard(const vector<int> &board) {
	int size = board.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (board[i] == j) cout << "Q ";
			else cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(const vector<int> &board, int row, int col) {
	for (int i = 0; i < row; ++i) {
		// Check if the column or diagonals are attacked
		if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
			return false;
		}
	}
	return true;
}

// Function to solve the N-Queens problem using a stack
void solveNQueens(int size) {
	stack<BoardState> s;
	BoardState initialState = { vector<int>(size, -1), 0 }; 
	s.push(initialState);
	int solutionCount = 0;

	while (!s.empty()) {
		BoardState currentState = s.top();
		s.pop();

		if (currentState.row == size) {
			// All queens are placed, print the board
			printBoard(currentState.board);
			++solutionCount;
			continue;
		}

		for (int col = 0; col < size; ++col) {
			if (isSafe(currentState.board, currentState.row, col)) {
				BoardState newState = currentState;
				newState.board[currentState.row] = col;
				newState.row++;
				s.push(newState);
			}
		}
	}

	cout << "Total solutions: " << solutionCount << endl;
}

int main() {
	int size = 8;
	cout << "Solving the " << size << "-Queens problem using stack:\n";
	solveNQueens(size);
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	char *arr;
	int top;
	int capacity;

public:
	Stack(int size) {
		capacity = size;
		arr = new char[capacity];
		top = -1;
	}

	~Stack() { delete[] arr; }
	bool isEmpty() const { return top == -1; }
	void push(char c) {
		if (top >= capacity - 1) throw overflow_error("Stack overflow");
		arr[++top] = c;
	}

	char pop() {
		if (top < 0)  throw underflow_error("Stack underflow"); 
		return arr[top--];
	}

	char peek() const {
		if (top < 0) throw underflow_error("Stack is empty"); 
		return arr[top];
	}

};

bool isWellParenthesized(const string &expression) {
	Stack s(expression.size());
	for (char ch : expression) {
		switch (ch) {
			case '(':
			case '{':
			case '[': s.push(ch); break;
			case ')':
			case '}':
			case ']':
				if (s.isEmpty() || s.peek() != ch - 1) return false;
				s.pop();
				break;
		}
	}

	return s.isEmpty();
}

int main() {
	string expression;
	cout << "Enter the expression: ";
	getline(cin, expression);
	if (isWellParenthesized(expression)) cout << "The expression is well-parenthesized.\n";
	else cout << "The expression is not well-parenthesized.\n";
	return 0;
}

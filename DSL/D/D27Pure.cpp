#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
	string stack;

public:
	void push(char c) { stack += c; }
	char pop() {
		if (stack.empty()) { throw underflow_error("Stack underflow"); }
		char top = stack.back();
		stack.pop_back();
		return top;
	}

	char peek() const {
		if (stack.empty()) { throw underflow_error("Stack is empty"); }
		return stack.back();
	}

	bool isEmpty() const { return stack.empty(); }
	bool isDigit(char ch) const { return ch >= '0' && ch <= '9'; }
};

int precedence(char op) {
	switch (op) {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		default: return 0;
	}
}

string infixToPostfix(const string &infix) {
	Stack s;
	string postfix;

	for (char ch : infix) {
		if (ch >= '0' && ch <= '9') postfix += ch; 
		else if (ch == '(') s.push(ch);
		else if (ch == ')') {
			while (!s.isEmpty() && s.peek() != '(') {
				postfix += s.pop();
			}
			if (!s.isEmpty()) s.pop(); 
		} else {
			while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
				postfix += s.pop();
			}
			s.push(ch);
		}
	}

	while (!s.isEmpty()) postfix += s.pop();
	return postfix;
}

int evaluatePostfix(const string &postfix) {
	Stack s;
	for (char ch : postfix) {
		if (ch >= '0' && ch <= '9') s.push(ch);
		else {
			int right = s.pop() - '0'; 
			int left = s.pop() - '0';  

			switch (ch) {
				case '+': s.push((left + right) + '0'); break;
				case '-': s.push((left - right) + '0'); break;
				case '*': s.push((left * right) + '0'); break;
				case '/': s.push((left / right) + '0'); break;
			}
		}
	}

	return s.pop() - '0'; 
}

int main() {
	string infix, postfix;
	cout << "Enter the infix expression: ";
	getline(cin, infix);
	postfix = infixToPostfix(infix);
	cout << "Postfix expression: " << postfix << endl;
	int result = evaluatePostfix(postfix);
	cout << "Evaluation of postfix expression: " << result << endl;

	return 0;
}

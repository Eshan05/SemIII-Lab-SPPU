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
    if(top >= capacity - 1) {
      cout << "Stack overflow" << endl;
      return;
    }
    arr[++top] = c;
  }

  char pop() {
    if(top < 0) {
      cout << "Stack underflow" << endl;
      return '\0';
    }
    return arr[top--];
  }

  char peek() const {
    if(top < 0) {
      cout << "Stack is empty" << endl;
      return '\0';
    }
    return arr[top];
  }
};

bool isWellParenthesized(const string &expression) {
  Stack s(expression.size());
  for(int i = 0; i < expression.size(); ++i) {
    char ch = expression[i];
    switch(ch) {
      case '(':
      case '{':
      case '[': s.push(ch); break;
      case ')':
      case '}':
      case ']':
        if(s.isEmpty() || s.peek() != ch - 1) return false;
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
  if(isWellParenthesized(expression))
    cout << "The expression is well-parenthesized.\n";
  else cout << "The expression is not well-parenthesized.\n";
  return 0;
}

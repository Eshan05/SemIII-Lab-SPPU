/**
 * * Eshan Nahar
 * Implement C++ program for expression conversion as infix to postfix and its
evaluation using stack based on given conditions:

  1. Operands and operator, both must be single character.
  2. Input Postfix expression must be in a desired format.
  3. Only '+', '-', '*' and '/ ' operators are expected.
 */

#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

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
  stack<char> s;
  string postfix;
  for (char ch : infix) {
    if (isalnum(ch)) { postfix += ch; }
    else if (ch == '(') { s.push(ch); } 
    else if (ch == ')') {
      while (!s.empty() && s.top() != '(') {
        postfix += s.top();
        s.pop();
      }
      if (!s.empty()) s.pop(); 
    } else {
      while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
        postfix += s.top();
        s.pop();
      }
      s.push(ch);
    }
  }

  while (!s.empty()) {
    postfix += s.top();
    s.pop();
  }

  return postfix;
}

int evaluatePostfix(const string &postfix) {
  stack<int> s;
  for (char ch : postfix) {
    if (isdigit(ch)) {
      s.push(ch - '0');
    } else {
      int right = s.top();
      s.pop();
      int left = s.top();
      s.pop();

      switch (ch) {
        case '+': s.push(left + right); break;
        case '-': s.push(left - right); break;
        case '*': s.push(left * right); break;
        case '/': s.push(left / right); break;
      }
    }
  }

  return s.top();
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

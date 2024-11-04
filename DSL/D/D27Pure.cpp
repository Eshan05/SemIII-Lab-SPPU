#include <iostream>
using namespace std;

class Stack {
 private:
  char stack[100];
  int top;

 public:
  Stack() : top(-1) {}

  void push(char c) {
    if(top < 99) {
      stack[++top] = c;
    } else {
      cout << "Stack overflow" << endl;
      exit(1);
    }
  }

  char pop() {
    if(isEmpty()) {
      cout << "Stack underflow" << endl;
      exit(1);
    }
    return stack[top--];
  }

  char peek() const {
    if(isEmpty()) {
      cout << "Stack is empty" << endl;
      exit(1);
    }
    return stack[top];
  }

  bool isEmpty() const { return top == -1; }
};

int precedence(char op) {
  switch(op) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    default: return 0;
  }
}

void infixToPostfix(const char *infix, char *postfix) {
  Stack s;
  int pIndex = 0;
  int i = 0;

  while(infix[i] != '\0') {
    if(infix[i] >= '0' && infix[i] <= '9') {
      // Handle multi-digit numbers
      while(infix[i] >= '0' && infix[i] <= '9') {
        postfix[pIndex++] = infix[i++];
      }
      postfix[pIndex++] = ' '; // Add space after the number
    } else if(infix[i] == '(') {
      s.push(infix[i]);
      i++;
    } else if(infix[i] == ')') {
      while(!s.isEmpty() && s.peek() != '(') {
        postfix[pIndex++] = s.pop();
        postfix[pIndex++] = ' '; // Add space after operator
      }
      s.pop(); // Remove '('
      i++;
    } else {
      while(!s.isEmpty() && precedence(s.peek()) >= precedence(infix[i])) {
        postfix[pIndex++] = s.pop();
        postfix[pIndex++] = ' '; // Add space after operator
      }
      s.push(infix[i]);
      i++;
    }
  }

  while(!s.isEmpty()) {
    postfix[pIndex++] = s.pop();
    postfix[pIndex++] = ' '; // Add space after operator
  }
  postfix[pIndex] = '\0'; // Null-terminate the postfix string
}

int evaluatePostfix(const char *postfix) {
  Stack s;
  int i = 0;

  while(postfix[i] != '\0') {
    if(postfix[i] >= '0' && postfix[i] <= '9') {
      // Handle multi-digit numbers
      int num = 0;
      while(postfix[i] >= '0' && postfix[i] <= '9') {
        num = num * 10 + (postfix[i] - '0');
        i++;
      }
      s.push(num + '0'); // Push as character
    } else if(postfix[i] == ' ') {
      i++; // Skip space
    } else {
      int right = s.pop() - '0';
      int left = s.pop() - '0';

      switch(postfix[i]) {
        case '+': s.push((left + right) + '0'); break;
        case '-': s.push((left - right) + '0'); break;
        case '*': s.push((left * right) + '0'); break;
        case '/': s.push((left / right) + '0'); break;
      }
      i++;
    }
  }

  return s.pop() - '0';
}

int main() {
  char infix[100], postfix[200];
  cout << "Enter the infix expression: ";
  cin.getline(infix, 100);
  infixToPostfix(infix, postfix);
  cout << "Postfix expression: " << postfix << endl;
  int result = evaluatePostfix(postfix);
  cout << "Evaluation of postfix expression: " << result << endl;

  return 0;
}

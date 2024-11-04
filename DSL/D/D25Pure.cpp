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
      return; // Handle overflow
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
};

bool isSpace(char ch) { return ch == ' '; }

char toLower(char ch) {
  return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
  // Simple conversion to lowercase
}

void printOriginalAndReversed(const string &str) {
  Stack s(str.size());

  // Push all characters to the stack (Ignore space)
  for(int i = 0; i < str.size(); ++i) {
    char ch = str[i];
    if(!isSpace(ch)) s.push(ch);
  }

  cout << "Original string: ";
  for(int i = 0; i < str.size(); ++i) {
    char ch = str[i];
    if(!isSpace(ch)) cout << ch;
  }

  cout << "\nReversed string: ";
  while(!s.isEmpty()) cout << s.pop();
  cout << endl;
}

bool isPalindrome(const string &str) {
  Stack s(str.size());

  for(int i = 0; i < str.size(); ++i) {
    char ch = str[i];
    if(!isSpace(ch)) s.push(toLower(ch));
  }

  string cleanedStr;
  for(int i = 0; i < str.size(); ++i) {
    char ch = str[i];
    if(!isSpace(ch)) cleanedStr += toLower(ch);
  }

  string reversedStr;
  while(!s.isEmpty()) reversedStr += s.pop();

  return cleanedStr == reversedStr;
}

int main() {
  string input;
  cout << "Enter the string: ";
  getline(cin, input);
  printOriginalAndReversed(input);

  if(isPalindrome(input)) cout << "The string is a palindrome.\n";
  else cout << "The string is not a palindrome.\n";

  return 0;
}

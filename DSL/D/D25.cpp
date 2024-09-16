/**
 * * Eshan Nahar
 * A palindrome is a string of character that‘s the same forward and backward.
Typically, punctuation, capitalization, and spaces are ignored. For example,
“Poor Dan is in a droop” is a palindrome, as can be seen by examining the
characters “poor danisina droop” and observing that they are the same forward
and backward. One way to check for a palindrome is to reverse the characters in
the string and then compare with them the original-in a palindrome, the sequence
will be identical. Write C++ program with functions-

a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or no
*/

#include<iostream>
#include<string>
#include<cctype>
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

void printOriginalAndReversed(const string& str) {
	Stack s(str.size());
	// Push all characters to the stack (Ignore space)
	for (char ch : str) if (!isspace(ch)) s.push(ch);
	cout << "Original string: ";
	for (char ch : str) if (!isspace(ch)) cout << ch;
	cout << "\nReversed string: ";
	while (!s.isEmpty()) cout << s.pop();
	cout << endl;
}

bool isPalindrome(const string& str) {
	Stack s(str.size());
	for (char ch : str) if (!isspace(ch)) s.push(tolower(ch));
	string cleanedStr;
	for (char ch : str) if (!isspace(ch)) cleanedStr += tolower(ch);
	string reversedStr;
	while (!s.isEmpty()) reversedStr += s.pop();
	return cleanedStr == reversedStr;
}

int main() {
	string input;
	cout << "Enter the string: ";
	getline(cin, input);
	printOriginalAndReversed(input);		
	if (isPalindrome(input)) cout << "The string is a palindrome.\n";
	else cout << "The string is not a palindrome.\n";
	
		return 0;
}
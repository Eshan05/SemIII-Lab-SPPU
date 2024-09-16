/**
 * * Eshan Nahar
 * * Literally leetcode 20
 * In any language program mostly syntax error occurs due to unbalancing
delimiter such as (),{},[]. Write C++ program using stack to check whether given
expression is well parenthesized or not
 */

#include<bits/stdc++.h>
using namespace std;

bool isValid(string& s) {
	stack<char> st;
	for(char c : s) {
		if(c == '(' || c == '[' || c == '{') st.push(c);
		else {
			if(st.empty()) return false;
			char top = st.top();
			st.pop();
			if((c == ')' && top != '(') || 
				 (c == ']' && top != '[') ||
				 (c == '}' && top != '{')) return false;
		}
	}
	return st.empty();
}

int main() {
	string s = "{[()]}([{])";
	if(isValid(s)) cout << "Valid!";
	else cout << "Not properly arranged";
	return 0;
}
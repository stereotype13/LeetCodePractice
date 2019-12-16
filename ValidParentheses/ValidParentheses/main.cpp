/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> charStack;
		for (const char& c : s) {
			switch (c) {
			case '(':
			case '[':
			case '{':
				charStack.push(c);
				continue;

			case ')':
				if (charStack.size() == 0 || charStack.top() != '(')
					return false;
				charStack.pop();
				continue;

			case ']':
				if (charStack.size() == 0 || charStack.top() != '[')
					return false;
				charStack.pop();
				continue;

			case '}':
				if (charStack.size() == 0 || charStack.top() != '{')
					return false;
				charStack.pop();
				continue;


			default:
				return false;
			}
		}

		if (charStack.size() == 0)
			return true;

		return false;
	}
};

int main() {
	Solution solution;

	string s1{ "()"};
	string s2{ "()[]{}" };
	string s3{ "(]" };
	string s4{ "([)]" };
	string s5{ "{[]}" };
	string s6{ "}" };


	cout << s1 << ": " << solution.isValid(s1) << endl;
	cout << s2 << ": " << solution.isValid(s2) << endl;
	cout << s3 << ": " << solution.isValid(s3) << endl;
	cout << s4 << ": " << solution.isValid(s4) << endl;
	cout << s5 << ": " << solution.isValid(s5) << endl;
	cout << s6 << ": " << solution.isValid(s6) << endl;

	cin.get();
}
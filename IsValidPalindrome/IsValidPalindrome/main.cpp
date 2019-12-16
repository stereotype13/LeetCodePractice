

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		s.erase(remove_if(s.begin(), s.end(),
			[](auto const& c) -> bool { return !isalnum(c); }), s.end());

		transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) { return tolower(c); });

		int low = 0;
		int high = s.size() - 1;
		while (low < high) {
			if (s[low] != s[high])
				return false;

			++low;
			--high;
		}

		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	string s1{ "A man, a plan, a canal: Panama" };
	cout << solution.isPalindrome(s1) << endl;

	string s2{ "race a car" };
	cout << solution.isPalindrome(s2) << endl;

	cin.get();
}
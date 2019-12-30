/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int low = 0, high = 0;

		for (int i = 0; i < (int)s.size(); ++i) {
			
			if (s[i] == ' ') {
				//reverse from low to i - i, inclusive
				for (high = i - 1; low < high; ++low, --high) {
					swap(s[low], s[high]);
				}
				low = i + 1;
				high = i + 1;
				continue;
			}

			if (i == (int)s.size() - 1) {
				//reverse from low to s.size() - 1, inclusive
				for (high = i; low < high; ++low, --high) {
					swap(s[low], s[high]);
				}
			}
		}
		return s;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	cout << solution.reverseWords("Let's take LeetCode contest") << endl;
	cin.get();
	return 0;
}
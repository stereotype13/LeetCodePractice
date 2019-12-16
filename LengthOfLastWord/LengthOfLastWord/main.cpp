/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		bool lookingForNewWord = true;

		int lastWordCount = 0;
		for (const auto& c : s) {
			if (c == ' ')
				lookingForNewWord = true;

			if (lookingForNewWord && c != ' ') {
				lastWordCount = 1;
				lookingForNewWord = false;
				continue;
			}

			if (lookingForNewWord)
				continue;

			++lastWordCount;
				
		}

		return lastWordCount;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << solution.lengthOfLastWord("Hello World") << endl;
	cout << solution.lengthOfLastWord("Hello World   ") << endl;
	cout << solution.lengthOfLastWord("   Hello World   ") << endl;
	cout << solution.lengthOfLastWord("   ") << endl;
	cout << solution.lengthOfLastWord("") << endl;

	cin.get();
	return 0;
}
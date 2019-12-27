/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.


Example 1:

Input: "USA"
Output: True


Example 2:

Input: "FlaG"
Output: False


Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
	bool isCapital(char c) {
		return c >= 'A' && c <= 'Z';
	}
public:
	bool detectCapitalUse(string word) {
		if (word.size() == 1)
			return true;

		int capitalLetterCount = 0;

		for (const auto& c : word)
			if (isCapital(c))
				++capitalLetterCount;

		if (capitalLetterCount == word.size())
			return true;

		if (capitalLetterCount == 0)
			return true;

		if (capitalLetterCount == 1 && isCapital(word[0]))
			return true;

		return false;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	cout << solution.detectCapitalUse("USA") << endl;
	cout << solution.detectCapitalUse("FlaG") << endl;

	cin.get();
	return 0;
}
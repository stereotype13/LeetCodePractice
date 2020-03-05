/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.



Example 1:

Input: text = "nlaebolko"
Output: 1

Example 2:

Input: text = "loonbalxballpoon"
Output: 2

Example 3:

Input: text = "leetcode"
Output: 0



Constraints:

	1 <= text.length <= 10^4
	text consists of lower case English letters only.

*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		unordered_map<char, int> charCount;

		for (const auto& c : text)
			charCount[c]++;

		string balloon = "balloon";

		bool keepLooping = true;
		int count = 0;
		while (keepLooping) {
			for (const auto& c : balloon) {
				if (charCount[c] == 0) {
					keepLooping = false;
					break;
				}
				--charCount[c];
			}
			if(keepLooping)
				++count;
		}
		return count;
	}
};

class Solution2 {
public:
	int maxNumberOfBalloons(string text) {
		int charCount[26] = {0};

		for (const auto& c : text)
			charCount[c - 'a']++;

		return min(min(min(charCount['b' - 'a'], charCount['a' - 'a']), min(charCount['l' - 'a']/2, charCount['o' - 'a']/2)), charCount['n' - 'a']);
	}
};

int main() {
	Solution2 solution;

	cout << solution.maxNumberOfBalloons("nlaebolko") << endl;
	cout << solution.maxNumberOfBalloons("loonbalxballpoon") << endl;
	cout << solution.maxNumberOfBalloons("leetcode") << endl;

	cin.get();
	return 0;
}
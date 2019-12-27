/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
	bool isVowel(char c) {
		c = tolower(c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;

		return false;
	}
public:
	string reverseVowels(string s) {

		int low = 0, high = s.size() - 1;

		while (low < high) {
			if (!isVowel(s[low]) && !isVowel(s[high])) {
				++low;
				--high;
				continue;
			}

			if (isVowel(s[low]) && isVowel(s[high])) {
				swap(s[low], s[high]);
				++low;
				--high;
				continue;
			}

			if (isVowel(s[low]) && !isVowel(s[high])) {
				--high;
				continue;
			}

			++low;

			
		}

		return s;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << solution.reverseVowels("leetcode") << endl;

	cin.get();
	return 0;
}
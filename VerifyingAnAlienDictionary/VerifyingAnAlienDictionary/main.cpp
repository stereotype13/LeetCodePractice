/*
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. 
The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only 
if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to 
lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		if (words.size() < 2)
			return true;

		unordered_map<char, int> charOrder;

		for (int i = 0; i < (int)order.size(); ++i)
			charOrder[order[i]] = i;

		unsigned int i = 0;
		bool sorted = true;
		for (unsigned int j = 1; j < words.size(); ++j) {
			auto& wordLow = words[j - 1];
			auto& wordHigh = words[j];
			if (charOrder[words[j - 1][i]] > charOrder[words[j][i]])
				return false;

			if (charOrder[words[j - 1][i]] == charOrder[words[j][i]]) {
				int minLength = min(wordLow.size(), wordHigh.size());
				++i;
				while (i < minLength && charOrder[words[j - 1][i]] == charOrder[words[j][i]]) {
					++i;
					if (charOrder[words[j - 1][i]] > charOrder[words[j][i]])
						return false;
				}
				if (wordLow.size() > wordHigh.size())
					return false;

				i = 0;
			}

		}
		if (sorted)
			return true;

		return true;
	}
};

int main(int argc, const char* argv[]) { 
	Solution solution;

	vector<string> words1{ "hello","leetcode" };
	string order1 = "hlabcdefgijkmnopqrstuvwxyz";
	cout << boolalpha << solution.isAlienSorted(words1, order1) << endl;

	vector<string> words2{ "word","world","row" };
	string order2 = "worldabcefghijkmnpqstuvxyz";
	cout << boolalpha << solution.isAlienSorted(words2, order2) << endl;

	vector<string> words3{ "apple","app" };
	string order3 = "abcdefghijklmnopqrstuvwxyz";
	cout << boolalpha << solution.isAlienSorted(words3, order3) << endl;

	vector<string> words4{ "all", "wora", "wor" };
	string order4 = "abcdefghijklmnopqrstuvwxyz";
	cout << boolalpha << solution.isAlienSorted(words4, order4) << endl; //should be false

	vector<string> words5{ "all", "wor", "wora" };
	string order5 = "abcdefghijklmnopqrstuvwxyz";
	cout << boolalpha << solution.isAlienSorted(words5, order5) << endl; //should be true

	cin.get();
	return 0;
}
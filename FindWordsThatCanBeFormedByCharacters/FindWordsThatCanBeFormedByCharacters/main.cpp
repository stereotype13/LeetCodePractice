/*
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.



Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation:
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation:
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.



Note:

	1 <= words.length <= 1000
	1 <= words[i].length, chars.length <= 100
	All strings contain lowercase English letters only.

*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		unordered_map<char, int> charMap, tempMap;

		for (const auto& c : chars)
			charMap[c]++;

		int answer = 0;

		for (const auto& word : words) {
			tempMap = charMap;
			bool wordIsGood = true;
			for (const auto& c : word) {
				if (tempMap.find(c) == tempMap.end() || tempMap[c] == 0) {
					wordIsGood = false;
					break;
				}
				tempMap[c]--;
			}
			if (wordIsGood)
				answer += (int)word.size();
		}
		return answer;
	}
};

int main() {
	Solution solution;

	vector<string> words1{ "cat", "bt", "hat", "tree" };
	string chars1 = "atach";
	cout << solution.countCharacters(words1, chars1) << endl;

	vector<string> words2{ "hello","world","leetcode" };
	string chars2 = "welldonehoneyr";
	cout << solution.countCharacters(words2, chars2) << endl;

	cin.get();
	return 0;
}
/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		if (pattern.empty() || str.empty())
			return false;

		istringstream ss(str);

		vector<string> words;

		while (true) {
			string word;
			ss >> word;
			if (word == "")
				break;
			words.push_back(word);
		}

		if (pattern.size() != words.size())
			return false;

		unordered_map<char, string> charMap;
		unordered_set<string> seenWords;

		for (int i = 0; i < pattern.size(); ++i) {
			char c = pattern[i];
			string word = words[i];

			if (charMap.find(pattern[i]) == charMap.end() && seenWords.find(word) == seenWords.end()) {
				charMap[c] = words[i];
				seenWords.emplace(word);
				continue;
			}

			if (charMap[c] != words[i])
				return false;

		}

		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	string pattern1{ "abba" };
	string words1{ "dog cat cat dog" };
	cout << solution.wordPattern(pattern1, words1) << endl;

	string pattern2{ "abba" };
	string words2{ "dog cat cat fish" };
	cout << solution.wordPattern(pattern2, words2) << endl;

	string pattern3{ "abcabc" };
	string words3{ "dog cat fish dog cat fish" };
	cout << solution.wordPattern(pattern3, words3) << endl;
	
	cin.get();
	return 0;
}
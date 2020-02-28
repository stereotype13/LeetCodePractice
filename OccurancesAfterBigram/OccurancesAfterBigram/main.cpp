/*
Given words first and second, consider occurrences in some text of the form "first second third", where second comes 
immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.



Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]

Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]



Note:

	1 <= text.length <= 1000
	text consists of space separated words, where each word consists of lowercase English letters.
	1 <= first.length, second.length <= 10
	first and second consist of lowercase English letters.


*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> words;
		vector<string> result;

		string tempWord = "";
		for (const auto& c : text) {
			if (c == ' ') {
				words.push_back(tempWord);
				tempWord = "";
				continue;
			}
			tempWord += c;
		}
		words.push_back(tempWord);

		for (int i = 0; i < (int)words.size() - 2; ++i) {
			if (words[i] == first && words[i + 1] == second)
				result.push_back(words[i + 2]);
		}

		return result;
	}
};

int main() {
	Solution solution;

	string text1 = "alice is a good girl she is a good student";
	string first1 = "a", second1 = "good";
	auto result1 = solution.findOcurrences(text1, first1, second1);

	string text2 = "we will we will rock you";
	string first2 = "we", second2 = "will";
	auto result2 = solution.findOcurrences(text2, first2, second2);

	cin.get();
	return 0;
}
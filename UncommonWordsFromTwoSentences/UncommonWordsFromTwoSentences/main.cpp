/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words.

You may return the list in any order.



Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]


Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	void parseString(const string& s, vector<string>& words) {
	
		int begin = 0;
		for (int i = 0; i < (int)s.size(); ++i) {
			char c = s[i];
			if (c == ' ' && i != begin) {
				words.push_back(s.substr(begin, i - begin));
				begin = i + 1;
				continue;
			}
		}
		words.push_back(s.substr(begin, (int)s.size() - begin));
	}
public:
	vector<string> uncommonFromSentences(string A, string B) {
		vector<string> wordsA, wordsB;
		parseString(A, wordsA);
		parseString(B, wordsB);

		unordered_map<string, int> frequencyA, frequencyB;

		for (const auto& word : wordsA)
			frequencyA[word]++;

		for (const auto& word : wordsB)
			frequencyB[word]++;

		vector<string> result;

		for (const auto& p : frequencyA) {
			if (p.second == 1 && frequencyB.find(p.first) == frequencyB.end())
				result.push_back(p.first);
		}

		for (const auto& p : frequencyB) {
			if (p.second == 1 && frequencyA.find(p.first) == frequencyA.end())
				result.push_back(p.first);
		}

		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	string A1 = "this apple is sweet", B1 = "this apple is sour";
	auto result1 = solution.uncommonFromSentences(A1, B1);

	string A2 = "apple apple", B2 = "banana";
	auto result2 = solution.uncommonFromSentences(A2, B2);

	return 0;
}
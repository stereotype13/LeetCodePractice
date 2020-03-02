/*
Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. 
For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words 
such that f(queries[i]) < f(W), where W is a word in words.



Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").



Constraints:

	1 <= queries.length <= 2000
	1 <= words.length <= 2000
	1 <= queries[i].length, words[i].length <= 10
	queries[i][j], words[i][j] are English lowercase letters.


*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		vector<int> queryFrequency(queries.size(), 0);
		vector<int> wordFrequency(words.size(), 0);

		for (int i = 0; i < (int)queries.size(); ++i) {
			char minChar = 'z';
			for (const auto& c : queries[i]) 
				minChar = min(minChar, c);
			
			int frequency = 0;
			for (const auto& c : queries[i]) {
				if (c == minChar)
					++frequency;
			}

			queryFrequency[i] = frequency;
		}

		for (int i = 0; i < (int)words.size(); ++i) {
			char minChar = 'z';
			for (const auto& c : words[i])
				minChar = min(minChar, c);

			int frequency = 0;
			for (const auto& c : words[i]) {
				if (c == minChar)
					++frequency;
			}

			wordFrequency[i] = frequency;
		}

		vector<int> answer(queries.size(), 0);
		for (int i = 0; i < (int)queryFrequency.size(); ++i) {
			int count = 0;
			for (const auto& frequency : wordFrequency) {
				if (frequency > queryFrequency[i])
					++count;
			}
			answer[i] = count;
		}
		return answer;
	}
};

int main() {
	Solution solution;

	vector<string> queries1{ "cbd" };
	vector<string> words1{ "zaaaz" };
	auto result1 = solution.numSmallerByFrequency(queries1, words1);

	vector<string> queries2{ "bbb","cc" };
	vector<string> words2{ "a","aa","aaa","aaaa" };
	auto result2 = solution.numSmallerByFrequency(queries2, words2);

	cin.get();
	return 0;
}
/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all 
strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not
4 times, you need to include that character three times in the final answer.

You may return the answer in any order.



Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]



Note:

	1 <= A.length <= 100
	1 <= A[i].length <= 100
	A[i][j] is a lowercase letter


*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<vector<int>> charCounts;

		for (const auto& string : A) {
			vector<int> charCount(26, 0);

			for (const auto& c : string)
				charCount[c - 'a']++;

			charCounts.push_back(charCount);
		}

		vector<string> result;
		for (char i = 0; i < 26; ++i) {
			int count = INT_MAX;
			for (const auto& charCount : charCounts) {
				count = min(count, charCount[i]);

				if (count == 0)
					break;
			}
			if (count > 0) {
				for (int j = 0; j < count; ++j)
					result.push_back(string(1, i + 'a'));
			}
		}
		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<string> vec1{ "bella", "label", "roller" };
	auto result1 = solution.commonChars(vec1);

	cin.get();
	return 0;
}
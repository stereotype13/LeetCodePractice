/*
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically 
ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.



Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]


Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
	bool isNumericString(const string& s) {

		char firstValue;
		int i = 0;
		for (; i < (int)s.size(); ++i) {
			if (s[i] == ' ')
				break;
		}

		++i;
		firstValue = s[i];

		return firstValue >= '0' && firstValue <= '9';
	}

public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> result;

		vector<string> letterStrings, numberStrings;

		for (const auto& s : logs) {

			if (isNumericString(s))
				numberStrings.push_back(s);
			else
				letterStrings.push_back(s);
		}

		for (const auto& s : letterStrings)
			result.push_back(s);

		sort(result.begin(), result.end(), [](const string& s1, const string& s2) {

			string s1Key = "", s1Value = "", s2Key = "", s2Value = "";

			int i = 0;
			for (; i < (int)s1.size(); ++i) {
				auto& c = s1[i];
				if (c == ' ')
					break;

				s1Key += c;
			}

			s1Value = s1.substr(i + 1, (int)s1.size() - (i + 1));

			i = 0;
			for (; i < (int)s2.size(); ++i) {
				auto& c = s2[i];
				if (c == ' ')
					break;

				s2Key += c;
			}

			s2Value = s2.substr(i + 1, (int)s2.size() - (i + 1));

			if (s1Value < s2Value)
				return true;

			if (s1Value > s2Value)
				return false;

			return s1Key < s2Key;

		});

		for (const auto& s : numberStrings)
			result.push_back(s);

		return result;

	}
};

int main() {
	Solution solution;

	vector<string> log1{ "dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero" };
	auto result1 = solution.reorderLogFiles(log1);

	vector<string> log2{ "6p tzwmh ige mc", "ns 566543603829", "ubd cujg j d yf", "ha6 1 938 376 5", "3yx 97 666 56 5", "d 84 34353 2249", "0 tllgmf qp znc", "s 1088746413789", "ys0 splqqxoflgx", "uhb rfrwt qzx r", "u lrvmdt ykmox", "ah4 4209164350", "rap 7729 8 125", "4 nivgc qo z i", "apx 814023338 8" };
	auto result2 = solution.reorderLogFiles(log2);

	cin.get();
	return 0;
}
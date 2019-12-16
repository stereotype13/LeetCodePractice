/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;

		if (haystack.size() == 0)
			return -1;

		int needleIndex = 0;
		queue<int> startingIndices;
		for (int i = 0; i < haystack.size(); ++i) {
			if (haystack[i] == needle[0] && needleIndex != 0)
				startingIndices.push(i);

			if (haystack[i] == needle[needleIndex]) {
				++needleIndex;
				if (needleIndex == needle.size())
					return i - (needleIndex - 1);
				continue;
			}
				
			needleIndex = 0;
			if (!startingIndices.empty()) {
				i = startingIndices.front() - 1;
				startingIndices.pop();
			}
			

		}
		return -1;
	}
};


int main(int argc, char* argv[]) {
	Solution solution;

	string haystack1 = "hello", needle1 = "ll";
	cout << solution.strStr(haystack1, needle1) << endl;

	string haystack2 = "aaaaa", needle2 = "baa";
	cout << solution.strStr(haystack2, needle2) << endl;

	string haystack3 = "mississippi", needle3 = "issipi";
	cout << solution.strStr(haystack3, needle3) << endl;

	string haystack4 = "mississippi", needle4 = "issip";
	cout << solution.strStr(haystack4, needle4) << endl;

	cin.get();

	return 0;
}
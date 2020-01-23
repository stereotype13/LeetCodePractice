/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.



Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false


Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() < 2 || B.size() < 2 || A.size() != B.size())
			return false;

		vector<int> letterCountA(26, 0);
		vector<int> letterCountB(26, 0);

		vector<int> differingIndices;
		for (int i = 0; i < (int)A.size(); ++i) {
			char a = A[i];
			char b = B[i];

			letterCountA[a - 'a']++;
			letterCountB[b - 'a']++;

			if (a == b)
				continue;

			differingIndices.push_back(i);

			if (differingIndices.size() > 2)
				return false;
		}

		if (differingIndices.size() == 1)
			return false;

		if (differingIndices.size() == 2) {
			swap(A[differingIndices[0]], A[differingIndices[1]]);

			if (A == B)
				return true;

			return false;
		}

		int maxLetterCount = 0;
		for (int i = 0; i < 26; ++i) {
			maxLetterCount = max(maxLetterCount, letterCountA[i]);

			if (letterCountA[i] != letterCountB[i])
				return false;
		}

		if (maxLetterCount > 1)
			return true;

		return false;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	string A1 = "ab", B1 = "ba";
	cout << boolalpha << solution.buddyStrings(A1, B1) << endl;

	string A2 = "ab", B2 = "ab";
	cout << boolalpha << solution.buddyStrings(A2, B2) << endl;

	string A3 = "aa", B3 = "aa";
	cout << boolalpha << solution.buddyStrings(A3, B3) << endl;

	string A4 = "aaaaaaabc", B4 = "aaaaaaacb";
	cout << boolalpha << solution.buddyStrings(A4, B4) << endl;

	string A5 = "", B5 = "aa";
	cout << boolalpha << solution.buddyStrings(A5, B5) << endl;


	cin.get();
	return 0;
}
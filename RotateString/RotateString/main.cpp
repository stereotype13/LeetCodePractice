/*
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. 
For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. 
Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool rotateString(string A, string B) {
		unsigned int lengthA = A.size();
		unsigned int lengthB = B.size();

		if (lengthA == 0 && lengthB == 0)
			return true;

		if (lengthA == 0 || lengthB == 0 || lengthA != lengthB)
			return false;

		char firstLetterInA = A[0];

		for (unsigned int i = 0; i < lengthB; ++i) {
			char b = B[i];
			if (b == firstLetterInA) {
				
				bool canBeRotated = true;
				for (unsigned int j = 0, aIndex = 0; j < lengthB; ++j, ++aIndex) {
					if (A[aIndex] != B[(j + i) % lengthB]) {
						canBeRotated = false;
						break;
					}
				}
				if (canBeRotated)
					return true;
			}
		}

		return false;
	}
};

/*
"ohbrwzxvxe"
"uornhegseo"

Got true, expected false;
*/

int main() {
	Solution solution;

	string A1 = "abcde", B1 = "cdeab";
	cout << boolalpha << solution.rotateString(A1, B1) << endl;

	string A2 = "abcde", B2 = "abced";
	cout << boolalpha << solution.rotateString(A2, B2) << endl;

	string A3 = "ohbrwzxvxe", B3 = "uornhegseo";
	cout << boolalpha << solution.rotateString(A3, B3) << endl;

	cin.get();
	return 0;
}
/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
	void helper(string& S) {
		int backSpacesS = 0;
		int cursor = 0;
		for (int i = 0; i < (int)S.size(); ++i) {
			auto c = S[i];
			
			if (c == '#') {
				cursor = max(0, --cursor);
				continue;
			}
				
			S[cursor] = c;
			++cursor;
		}

		S.resize((size_t)cursor);
	}
public:
	bool backspaceCompare(string S, string T) {

		helper(S);
		helper(T);

		return S == T;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	string S1 = "ab#c", T1 = "ad#c";
	cout << boolalpha << solution.backspaceCompare(S1, T1) << endl;

	string S2 = "ab##", T2 = "c#d#";
	cout << boolalpha << solution.backspaceCompare(S2, T2) << endl;

	string S3 = "a##c", T3 = "#a#c";
	cout << boolalpha << solution.backspaceCompare(S3, T3) << endl;
	
	string S4 = "a#c", T4 = "b";
	cout << boolalpha << solution.backspaceCompare(S4, T4) << endl;

	cin.get();
	return 0;
}
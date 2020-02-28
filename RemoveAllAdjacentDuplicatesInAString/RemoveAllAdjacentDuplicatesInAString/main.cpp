/*
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.



Example 1:

Input: "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  
The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".



Note:

	1 <= S.length <= 20000
	S consists only of English lowercase letters.

*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string removeDuplicates(string S) {
		string temp = "";

		while (true) {

			for (int i = 0; i < (int)S.size(); ++i) {
				if (i < (int)S.size() - 1) {
					if (S[i] == S[i + 1])
						++i;
					else
						temp.push_back(S[i]);
				}
				else {
					temp.push_back(S[i]);
				}
			}

			if (S == temp)
				break;

			S = temp;
			temp.clear();
		}

		return S;

	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	cout << solution.removeDuplicates("abbaca") << endl;
	cout << solution.removeDuplicates("abbacaa") << endl;
	cout << solution.removeDuplicates("aaa") << endl;
	cout << solution.removeDuplicates("aaaa") << endl;
	cout << solution.removeDuplicates("a") << endl;
	cout << solution.removeDuplicates("") << endl;

	cin.get();
	return 0;
}
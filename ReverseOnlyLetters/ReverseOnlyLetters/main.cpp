/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.



Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S doesn't contain \ or "
*/
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution {
	bool isLetter(const char c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
public:
	string reverseOnlyLetters(string S) {
		stack<char> characters;
		queue<int> indices;

		for (int i = 0; i < (int)S.size(); ++i) {
			auto& c = S[i];
			if (!isLetter(c))
				continue;

			characters.push(c);
			indices.push(i);
		}

		while (!indices.empty()) {
			int index = indices.front();
			indices.pop();

			S[index] = characters.top();
			characters.pop();
		}

		return S;
	}
};

#include <list>

class Solution2 {
	bool isLetter(const char& c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
public:
	string reverseOnlyLetters(string S) {
		list<int> indices;

		for (int i = 0; i < (int)S.size(); ++i) {
			auto& c = S[i];
			if (!isLetter(c))
				continue;

			indices.push_back(i);
		}

		auto iteratorUp = indices.begin();
		auto iteratorDown = indices.rbegin();
		
		for (int i = 0; i < (int)indices.size() / 2; ++i) {
			swap(S[*iteratorUp], S[*iteratorDown]);
			++iteratorUp;
			++iteratorDown;
		}
			

		return S;
	}
};

int main() {
	Solution2 solution;

	string S1 = "ab-cd";
	cout << solution.reverseOnlyLetters(S1) << endl;

	string S2 = "a-bC-dEf-ghIj";
	cout << solution.reverseOnlyLetters(S2) << endl;

	string S3 = "Test1ng-Leet=code-Q!";
	cout << solution.reverseOnlyLetters(S3) << endl;

	cin.get();
	return 0;
}
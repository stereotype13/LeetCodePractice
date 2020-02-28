/*
For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.



Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""



Note:

	1 <= str1.length <= 1000
	1 <= str2.length <= 1000
	str1[i] and str2[i] are English uppercase letters.


*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1.size() < str2.size())
			swap(str1, str2);

		string candidate = "";
		string answer = "";
		for (int i = 0; i < (int)str2.size(); ++i) {
			candidate += str2[i];

			unsigned int candidateIndex = 0, str2Index = 0;
			bool isPotentialCandidate = true;
			for (int j = 0; j < (int)str1.size(); ++j) {
				if ((str1[j] != candidate[candidateIndex % candidate.size()] || (j == (int)str1.size() - 1 && candidateIndex % candidate.size() != candidate.size() - 1))
					|| (str2Index % str2.size() == (int)str2.size() - 1 && candidateIndex % candidate.size() != candidate.size() - 1)
					) {
					isPotentialCandidate = false;
					break;
				}
				++candidateIndex;
				++str2Index;
			}

			if (isPotentialCandidate && candidate.size() > answer.size())
				answer = candidate;

		}
		return answer;
	}
};

class Solution2 {
public:
	string gcdOfStrings(string str1, string str2) {
		//auto temp = str1.substr(str2.size());
		if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
		if (str2.empty()) return str1;
		if (str1.substr(0, str2.size()) != str2) return "";
		return gcdOfStrings(str1.substr(str2.size()), str2);
	}
};

int main(int argc, const char* argv[]) {
	Solution2 solution;

	string str1a = "ABABAB", str2a = "ABAB";
	cout << solution.gcdOfStrings(str1a, str2a) << endl;

	string str1b = "ABABABAB", str2b = "ABAB";
	cout << solution.gcdOfStrings(str1b, str2b) << endl;

	string str1c = "LEET", str2c = "CODE";
	cout << solution.gcdOfStrings(str1c, str2c) << endl;

	string str1d = "ABCAB", str2d = "ABC";
	cout << solution.gcdOfStrings(str1d, str2d) << endl;

	/*
	"TAUXXTAUXXTAUXXTAUXXTAUXX"
	"TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
	*/

	string str1e = "TAUXXTAUXXTAUXXTAUXXTAUXX", str2e = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
	cout << solution.gcdOfStrings(str1e, str2e) << endl;

	cin.get();
	return 0;
}
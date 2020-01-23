/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  
Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		for (auto& c : S)
			c = tolower(c);

		vector<string> result;
		unordered_set<string> resultSet;
		for (int i = 0; i <= pow(2, (int)S.size()); ++i) {
			
			string temp = S;
			for (int j = 0; j < (int)S.size(); ++j) {
				if (i & (1 << j))
					temp[S.size() - 1 - j] = toupper(temp[S.size() - 1 - j]);
				
			}
			resultSet.emplace(temp);
		}
		
		for (const auto& s : resultSet)
			result.push_back(s);

		return result;
	}
};

void print(vector<string>& vec) {
	for (string& s : vec)
		cout << s << endl;

}

vector<string> v1{ "FJkzh","FjKZH","FjKZh","FjKzH","FjkZH","Fjkzh","FjkZh","fjkZh","fJKZh","fjKzH","FJkzH","fjkZH","fjkzH","fjkzh","fJkzH","fjKZh","fjKZH","FjKzh","FjkzH","fJkzh","fJKzH","fJKZH","fJkZh","fJkZH","fjKzh","fJKzh" };
vector<string> v2{ "fjkzh","fjkzH","fjkZh","fjkZH","fjKzh","fjKzH","fjKZh","fjKZH","fJkzh","fJkzH","fJkZh","fJkZH","fJKzh","fJKzH","fJKZh","fJKZH","Fjkzh","FjkzH","FjkZh","FjkZH","FjKzh","FjKzH","FjKZh","FjKZH","FJkzh","FJkzH","FJkZh","FJkZH","FJKzh","FJKzH","FJKZh","FJKZH" };

class Solution2 {
public:
	vector<string> letterCasePermutation(string S) {
		vector<unsigned int> alphaIndices;
		for (int i = 0; i < (int)S.size(); ++i) {
			char& c = S[i];
			if (isalpha(c)) {
				c = tolower(c);
				alphaIndices.push_back(i);
			}

		}

		vector<string> result;
		result.push_back(S);

		for (const auto& alphaIndex : alphaIndices) {
			unsigned int currentResultSize = result.size();

			for (unsigned int j = 0; j < currentResultSize; ++j) {
				string temp = result[j];
				temp[alphaIndex] = toupper(temp[alphaIndex]);
				result.push_back(temp);
			}
		}
		return result;
	}
};


int main() {
	/*
	unordered_set<string> temp1;
	for (auto& s : v1)
		temp1.emplace(s);

	vector<string> notIncluded;
	for (auto& s : v2) {
		if (temp1.find(s) == temp1.end())
			notIncluded.push_back(s);
	}

	print(notIncluded);
	cin.get();

	return 0;
	Solution solution;
	auto string1 = "a1b2";
	auto result1 = solution.letterCasePermutation(string1);
	print(result1);
	*/
	
	Solution2 solution;
	cout << endl;
	auto string2 = "C";
	auto result2 = solution.letterCasePermutation(string2);
	print(result2);

	cin.get();
	return 0;
}
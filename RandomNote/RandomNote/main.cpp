/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a 
function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> ransomMap, magazineMap;

		for (const auto& c : ransomNote)
			ransomMap[c]++;

		for (const auto& c : magazine)
			magazineMap[c]++; 

		for (const auto& c : ransomNote) {
			if (!(magazineMap[c] > 0 && magazineMap[c] >= ransomMap[c]))
				return false;
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << solution.canConstruct("a", "b") << endl;
	cout << solution.canConstruct("aa", "ab") << endl;
	cout << solution.canConstruct("aa", "aab") << endl;

	cin.get();
	return 0;
}
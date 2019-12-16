/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		vector<int> sCount(26, 0);
		vector<int> tCount(26, 0);

		for (int i = 0; i < s.size(); ++i) {
			sCount[s[i] - 'a']++;
			tCount[t[i] - 'a']++;
		}

		return sCount == tCount;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	string s1{ "cat" };
	string s2{ "act" };

	cout << solution.isAnagram(s1, s2) << endl;

	cin.get();
	
	return 0;
}
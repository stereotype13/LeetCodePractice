/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, 
so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		if (J.empty() || S.empty())
			return 0;

		unordered_set<char> jewels;

		for (const auto& c : J)
			jewels.emplace(c);

		int count = 0;
		for (const auto& c : S)
			if (jewels.find(c) != jewels.end())
				++count;

		return count;
	}
};

int main() {
	Solution solution;
	
	string J1 = "aA";
	string S1 = "aAAbbbb";
	cout << solution.numJewelsInStones(J1, S1) << endl;

	string J2 = "z";
	string S2 = "ZZ";
	cout << solution.numJewelsInStones(J2, S2) << endl;

	cin.get();

	return 0;
}
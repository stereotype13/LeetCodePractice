/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, 
and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some 
characters (possibly none) being long pressed.



Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.


Note:

name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		if (name == typed)
			return true;

		if (name.size() > typed.size())
			return false;

		vector<pair<char, int>> nameCount, typedCount;

		char prev = name[0];
		int sameCount = 1;
		for (int i = 1; i < (int)name.size(); ++i) {
			auto& c = name[i];
			if (c == prev) {
				++sameCount;
				continue;
			}

			nameCount.push_back({ prev, sameCount });
			sameCount = 1;
			prev = c;
		}
		nameCount.push_back({ name.back(), sameCount });

		prev = typed[0];
		sameCount = 1;
		for (int i = 1; i < (int)typed.size(); ++i) {
			auto& c = typed[i];
			if (c == prev) {
				++sameCount;
				continue;
			}

			typedCount.push_back({ prev, sameCount });
			sameCount = 1;
			prev = c;
		}
		typedCount.push_back({ typed.back(), sameCount });

		if (nameCount.size() != typedCount.size())
			return false;

		for (int i = 0; i < (int)nameCount.size(); ++i) {
			if (nameCount[i].first != typedCount[i].first || nameCount[i].second > typedCount[i].second)
				return false;
		}
		
		return true;
	}
};

int main() {
	Solution solution;

	string name1 = "alex", typed1 = "aaleex";
	cout << boolalpha << solution.isLongPressedName(name1, typed1) << endl; //should be true

	string name2 = "saeed", typed2 = "ssaaedd";
	cout << boolalpha << solution.isLongPressedName(name2, typed2) << endl; //should be false

	string name3 = "leelee", typed3 = "lleeelee";
	cout << boolalpha << solution.isLongPressedName(name3, typed3) << endl; //should be true

	string name4 = "pyplrz", typed4 = "ppyypllr";
	cout << boolalpha << solution.isLongPressedName(name4, typed4) << endl; //should be false

	cin.get();
	return 0;
}
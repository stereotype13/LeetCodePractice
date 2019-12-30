/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool checkRecord(string s) {
		int aCount = 0;
		int consecutiveLCount = 0;

		for (const auto& c : s) {
			if (c == 'P') {
				consecutiveLCount = 0;
				continue;
			}
			

			if (c == 'A') {
				consecutiveLCount = 0;
				++aCount;
				if (aCount > 1)
					return false;
			}

			if (c == 'L') {
				++consecutiveLCount;
				if (consecutiveLCount > 2)
					return false;
			}
		}
		return true;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	cout << boolalpha << solution.checkRecord("PPALLP") << endl;
	cout << boolalpha << solution.checkRecord("PPALLL") << endl;

	cin.get();
	return 0;
}
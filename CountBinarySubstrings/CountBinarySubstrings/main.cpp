/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's 
and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int countBinarySubstrings(string s) {

		int count = 0;
		for (int i = 0; i < s.size() - 1; ++i) {
			int low = i, high = i + 1;

			if (s[low] == s[high])
				continue;

			++count;
			--low; ++high;
			while (low > -1 && high < s.size()) {
				if (s[low] == s[low + 1] && s[high] == s[high - 1]) 
					++count;
				else
					break;
				--low;
				++high;
			}
		}
		return count;

	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	string s1 = "00110011";
	cout << solution.countBinarySubstrings(s1) << endl;

	string s2 = "10101";
	cout << solution.countBinarySubstrings(s2) << endl;

	cin.get();
	return 0;
}
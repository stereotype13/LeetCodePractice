/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int startWindow = 0; startWindow < (int)s.size(); startWindow += 2 * k) {
			for (int low = startWindow, high = min(low + k - 1, (int)s.size() - 1); low < high; ++low, --high) {
				swap(s[low], s[high]);
			}
		}
		return s;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	string s1 = "abcdefg";
	cout << solution.reverseStr(s1, 2) << endl;

	cin.get();
	return 0;
}
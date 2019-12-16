/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

	1 -> A
	2 -> B
	3 -> C
	...
	26 -> Z
	27 -> AA
	28 -> AB
	...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string output = "";

		while (n > 0) {
			--n;
			char ch = (char)(n % 26 + 'A');
			n /= 26;
			output += ch;
		}
		reverse(output.begin(), output.end());
		return output;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.convertToTitle(1) << endl;
	cout << solution.convertToTitle(2) << endl;
	cout << solution.convertToTitle(3) << endl;

	cout << solution.convertToTitle(28) << endl;
	cout << solution.convertToTitle(701) << endl;
	cout << solution.convertToTitle(702) << endl;
	cout << solution.convertToTitle(703) << endl;

	cin.get();
	return 0;
}
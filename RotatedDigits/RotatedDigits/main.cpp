/*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  
Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 
6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation:
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Note:

N  will be in range [1, 10000].
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
	bool hasInvalidDigits(const string& number) {
		
		for (const auto& c : number) {
			if (c == '3' || c == '4' || c == '7')
				return true;
		}
		return false;
	}
public:
	int rotatedDigits(int N) {
		
		int count = 0;
		for (int i = 1; i <= N; ++i) {
			string number = to_string(i);
			string temp = number;
			if (hasInvalidDigits(temp))
				continue;

			for (auto& c : temp) {
				if (c == '0' || c == '1' || c == '8')
					continue;

				if (c == '2') {
					c = '5';
					continue;
				}

				if (c == '5') {
					c = '2';
					continue;
				}

				if (c == '6') {
					c = '9';
					continue;
				}

				if (c == '9') {
					c = '6';
					continue;
				}
			}

			if (number != temp)
				++count;
		}
		return count;
	}
};

int main() {
	Solution solution;

	cout << solution.rotatedDigits(10) << endl;

	cin.get();
	return 0;
}
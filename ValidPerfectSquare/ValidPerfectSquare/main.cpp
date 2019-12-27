/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		long long int s;
		long long int count = 0;
		do {
			s = count * count;
			if (s == num)
				return true;
			++count;
		} while (s < num);

		return false;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.isPerfectSquare(0) << endl;
	cout << solution.isPerfectSquare(1) << endl;
	cout << solution.isPerfectSquare(2) << endl;
	cout << solution.isPerfectSquare(3) << endl;
	cout << solution.isPerfectSquare(4) << endl;
	cout << solution.isPerfectSquare(5) << endl;
	cout << solution.isPerfectSquare(25) << endl;
	cout << solution.isPerfectSquare(64) << endl;
	cout << solution.isPerfectSquare(65) << endl;

	cin.get();
	return 0;
}
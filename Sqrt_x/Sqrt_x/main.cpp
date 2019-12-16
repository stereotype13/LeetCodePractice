/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
			 the decimal part is truncated, 2 is returned.
*/
#include <iostream>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		long int answer = 1;
		while (answer * answer <= x) {
			++answer;
		}
		return (int)answer - 1;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << "1: " << solution.mySqrt(1) << endl;
	cout << "2: " << solution.mySqrt(2) << endl;
	cout << "3: " << solution.mySqrt(3) << endl;
	cout << "4: " << solution.mySqrt(4) << endl;
	cout << "5: " << solution.mySqrt(5) << endl;
	cout << "6: " << solution.mySqrt(6) << endl;
	cout << "7: " << solution.mySqrt(7) << endl;
	cout << "8: " << solution.mySqrt(8) << endl;
	cout << "9: " << solution.mySqrt(9) << endl;

	cin.get();
	return 0;
}
/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/
#include <iostream>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		bool carry = false;
		int result = 0;

		int a_new, b_new;

		for (int i = 0; i < 32; ++i) {
			a_new = a & (1 << i);
			b_new = b & (1 << i);
			result |= (a_new ^ b_new ^ carry << i);
			carry = a_new & b_new | (carry << i) & (a_new ^ b);
		}
		return result;
	}
};

int main() {
	Solution solution;
	cout << solution.getSum(3, 5) << endl;
	cin.get();
}
/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits.



Example 1:

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 * 3 * 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15

Example 2:

Input: n = 4421
Output: 21
Explanation:
Product of digits = 4 * 4 * 2 * 1 = 32
Sum of digits = 4 + 4 + 2 + 1 = 11
Result = 32 - 11 = 21



Constraints:

	1 <= n <= 10^5

*/
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

class Solution {
public:
	int subtractProductAndSum(int n) {
		vector<int> digits;

		while (n > 0) {
			int digit = n % 10;
			n /= 10;
			digits.push_back(digit);
		}

		int sum = accumulate(digits.begin(), digits.end(), 0);
		int product = accumulate(digits.begin(), digits.end(), 1, multiplies<int>());

		return product - sum;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	cout << solution.subtractProductAndSum(234) << endl;
	cout << solution.subtractProductAndSum(4421) << endl;

	cin.get();
	return 0;
}
/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num == 1)
			return false;

		vector<int> divisors{ 1 };

		for (int i = 2; i * i <= num; ++i) {
			if (num % i == 0) {
				divisors.push_back(i);
				divisors.push_back(num / i);
			}
		}

		int sum = 0;
		for (const auto& divisor : divisors)
			sum += divisor;

		return sum == num;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	cout << solution.checkPerfectNumber(28) << endl;

	cin.get();
	return 0;
}
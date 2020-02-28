/*
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537



Constraints:

	0 <= n <= 37
	The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/
#include <iostream>


using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		if (n == 0)
			return 0;

		if (n < 3)
			return 1;

		int ts[3];
		ts[0] = 0;
		ts[1] = 1;
		ts[2] = 1;

		int answer = 0;
		for (int i = 3; i < n + 1; ++i) {
			answer = ts[0] + ts[1] + ts[2];
			ts[0] = ts[1];
			ts[1] = ts[2];
			ts[2] = answer;
		}
		return answer;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	cout << solution.tribonacci(0) << endl;
	cout << solution.tribonacci(1) << endl;
	cout << solution.tribonacci(2) << endl;
	cout << solution.tribonacci(3) << endl;
	cout << solution.tribonacci(4) << endl;
	cout << solution.tribonacci(25) << endl;

	cin.get();
	return 0;
}
/*
Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.



Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]


Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		if (A.size() < 2)
			return 0;

		int minimum = INT_MAX;
		int maximum = INT_MIN;

		for (const auto& i : A) {
			minimum = min(minimum, i);
			maximum = max(maximum, i);
		}

	
		return max(0, (maximum - K) - (minimum + K));
	}
};

int main() {
	Solution solution;

	vector<int> A1{ 1 }; int K1 = 0;
	cout << solution.smallestRangeI(A1, K1) << endl;

	vector<int> A2{ 0, 10 }; int K2 = 2;
	cout << solution.smallestRangeI(A2, K2) << endl;

	vector<int> A3{ 1, 3, 6 }; int K3 = 3;
	cout << solution.smallestRangeI(A3, K3) << endl;

	cin.get();
	return 0;
}
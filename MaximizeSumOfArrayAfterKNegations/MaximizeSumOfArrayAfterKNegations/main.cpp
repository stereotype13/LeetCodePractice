/*
Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], 
and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.



Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].

Example 2:

Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].

Example 3:

Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].



Note:

	1 <= A.length <= 10000
	1 <= K <= 10000
	-100 <= A[i] <= 100


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		int sum = 0;

		if (A.empty())
			return sum;

		if (A.size() == 1) {
			if (K % 2 == 0)
				return A[0];

			return -A[0];
		}

		sort(A.begin(), A.end());

		for (int i = 0, k = 0; i < (int)A.size() - 1 && k < K; ++i, ++k) {
			if (A[i] == 0)
				break;

			if (A[i] < 0 && A[i + 1] < 0) {
				A[i] = -A[i];
				continue;
			}

			if (A[i] < 0 && A[i + 1] == 0) {
				A[i] = -A[i];
				break;
			}

			if (A[i] < 0 && A[i + 1] > 0) {
				if ((K - k) % 2 == 1) {

					A[i] = -A[i];
					break;

				}
				else {
					if (abs(A[i]) > abs(A[i + 1])) {
						A[i] = -A[i];
						A[i + 1] = -A[i + 1];
					}
				}
				break;
			}

			if ((K - k) % 2 == 1) {

				A[i] = -A[i];
				break;

			}
			else {
				break;
			}
				
		}
			
			
		for (const auto& i : A)
			sum += i;

		return sum;
	}
};

int main() {
	Solution solution;

	vector<int> v1{ 4, 2, 3 };
	cout << solution.largestSumAfterKNegations(v1, 1) << endl; //5

	vector<int> v2{ 3,-1,0,2 };
	cout << solution.largestSumAfterKNegations(v2, 3) << endl; //6

	vector<int> v3{ 2,-3,-1,5,-4 };
	cout << solution.largestSumAfterKNegations(v3, 2) << endl; //13

	vector<int> v4{ 2,-3,-1,5,-4 };
	cout << solution.largestSumAfterKNegations(v4, 10) << endl; //13

	vector<int> v5{-2,9,9,8,4};
	cout << solution.largestSumAfterKNegations(v5, 5) << endl; //32

	/*
	[1,2,22,-23,-9,-30,-6,-9,1,8,24,2,21,29,10,-25,18,30,1,9,-8,-11,-22,-23,-17,-12,19,28,19,28]
	24
	Should get 467, NOT 463
	*/
	vector<int> v6{ 1,2,22,-23,-9,-30,-6,-9,1,8,24,2,21,29,10,-25,18,30,1,9,-8,-11,-22,-23,-17,-12,19,28,19,28 };
	cout << solution.largestSumAfterKNegations(v6, 24) << endl;

	/*
	[8,-7,-3,-9,1,9,-6,-9,3]
	8
	Should be 53, not 49
	*/
	vector<int> v7{ 8,-7,-3,-9,1,9,-6,-9,3 };
	cout << solution.largestSumAfterKNegations(v7, 8) << endl;

	cin.get();
	return 0;
}
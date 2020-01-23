/*
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
	Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1].

	Example 1:

Input: [0, 1, 0]
	Output : 1
	Example 2 :

	Input : [0, 2, 1, 0]
	Output : 1
	Note :

	3 <= A.length <= 10000
	0 <= A[i] <= 10 ^ 6
	A is a mountain, as defined above.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		if (A.size() < 3)
			return -1;

		for (int i = 1; i < (int)A.size() - 1; ++i)
			if (A[i] > A[i - 1] && A[i] > A[i + 1])
				return i;

		return -1;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	auto A1 = vector<int>{ 0, 1, 0 };
	cout << solution.peakIndexInMountainArray(A1) << '\n';

	auto A2 = vector<int>{ 0, 2, 1, 0 };
	cout << solution.peakIndexInMountainArray(A2) << '\n';


	cin.get();
	return 0;
}
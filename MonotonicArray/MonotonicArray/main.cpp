/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.



Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true


Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		if (A.empty())
			return false;

		if (A.size() == 1)
			return true;

		bool monotonicIncreasing = true;
		for (int i = 1; i < (int)A.size(); ++i)
			if (A[i - 1] > A[i]) {
				monotonicIncreasing = false;
				break;
			}
		
		if (monotonicIncreasing)
			return true;

		for (int i = 1; i < (int)A.size(); ++i)
			if (A[i - 1] < A[i])
				return false;
			

		return true;
	}
};

int main() {
	Solution solution;

	vector<int> A1{ 1, 2, 2, 3 };
	cout << boolalpha << solution.isMonotonic(A1) << endl;

	vector<int> A2{ 6,5,4,4 };
	cout << boolalpha << solution.isMonotonic(A2) << endl;

	vector<int> A3{ 1, 3, 2 };
	cout << boolalpha << solution.isMonotonic(A3) << endl;

	vector<int> A4{ 1, 2, 4, 5 };
	cout << boolalpha << solution.isMonotonic(A4) << endl;

	vector<int> A5{ 1, 1, 1 };
	cout << boolalpha << solution.isMonotonic(A5) << endl;


	cin.get();
	return 0;
}
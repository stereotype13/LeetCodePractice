/*
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]




Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true


Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		if (A.size() < 3)
			return false;

		bool increasing = true;

		int i = 1;
		while (i < (int)A.size() && A[i] > A[i - 1])
			++i;

		int j = (int)A.size() - 2;
		while (j > -1 && A[j] > A[j + 1])
			--j;

		return i - 1 == j + 1 && j + 1 > 0 && i - 1 < (int)A.size() - 1;
	}
};

int main() {
	Solution solution;

	vector<int> array1{ 2, 1 };
	cout << boolalpha << solution.validMountainArray(array1) << endl; //false

	vector<int> array2{ 3, 5, 5 };
	cout << boolalpha << solution.validMountainArray(array2) << endl; //false

	vector<int> array3{ 0, 3, 2, 1 };
	cout << boolalpha << solution.validMountainArray(array3) << endl; //true

	vector<int> array4{ 1,3,2 };
	cout << boolalpha << solution.validMountainArray(array4) << endl; //true

	vector<int> array5{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << boolalpha << solution.validMountainArray(array5) << endl; //false

	cin.get();
	return 0;
}
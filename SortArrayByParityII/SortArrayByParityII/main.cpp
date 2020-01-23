/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.



Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.


Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> evens, odds;

		for (const auto& i : A)
			if (i % 2 == 0)
				evens.push_back(i);
			else
				odds.push_back(i);

		int evenOddIndex = 0;
		for (int i = 0; i < (int)evens.size(); ++i) {
			A[evenOddIndex] = evens[i];
			evenOddIndex += 2;;
		}

		evenOddIndex = 1;
		for (int i = 0; i < (int)odds.size(); ++i) {
			A[evenOddIndex] = odds[i];
			evenOddIndex += 2;
		}

		return A;
	}
};

int main() {
	Solution solution;

	vector<int> A1{ 4, 2, 5, 7 };
	auto result1 = solution.sortArrayByParityII(A1);


	cin.get();
	return 0;
}
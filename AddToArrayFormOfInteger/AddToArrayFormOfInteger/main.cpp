/*
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  
For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.



Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000


Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		vector<int> result;
		int carry = 0;

		int AIndex = (int)A.size() - 1;
		while (K > 0 || AIndex > -1) {

			int temp = (AIndex > -1 ? A[AIndex] : 0) + (K % 10) + carry;
			carry = temp / 10;
			int digit = temp % 10;
			
			if(AIndex > -1)
				A[AIndex] = digit;

			result.push_back(digit);
			--AIndex;
			K /= 10;
		}
		if (carry != 0)
			result.push_back(carry);

		reverse(result.begin(), result.end());

		return result;

	}
};

int main() {
	Solution solution;

	vector<int> A1{ 1, 2, 0, 0 }; int K1 = 34;
	auto result1 = solution.addToArrayForm(A1, K1); //1234

	vector<int> A2{ 2, 7, 4 }; int K2 = 181;
	auto result2 = solution.addToArrayForm(A2, K2); //455

	vector<int> A3{ 2, 1, 5 }; int K3 = 806;
	auto result3 = solution.addToArrayForm(A3, K3); //1021

	vector<int> A4{ 9,9,9,9,9,9,9,9,9,9 }; int K4 = 1; //10000000000
	auto result4 = solution.addToArrayForm(A4, K4);

	vector<int> A5{ 0 }; int K5 = 23;
	auto result5 = solution.addToArrayForm(A5, K5); //23

	cin.get();
	return 0;
}
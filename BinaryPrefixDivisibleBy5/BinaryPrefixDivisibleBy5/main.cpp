/*
Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary 
number (from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Example 1:

Input: [0,1,1]
Output: [true,false,false]
Explanation:
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.

Example 2:

Input: [1,1,1]
Output: [false,false,false]

Example 3:

Input: [0,1,1,1,1,1]
Output: [true,false,false,false,true,false]

Example 4:

Input: [1,1,1,0,1]
Output: [false,false,false,false,false]



Note:

	1 <= A.length <= 30000
	A[i] is 0 or 1


*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> result;

		for (int i = 0; i < (int)A.size(); ++i) {
			bool odd = false;
			long long oddSum = 0, evenSum = 0;
			if ((i + 1) % 2 == 1) {
				odd = true;
				if (A[0] == 1)
					evenSum += 1;
			}

			for (int j = odd ? 1 : 0; j <= i; j += 2) {
				if (odd)
					oddSum += 2 * A[j] + A[j + 1];
				else
					evenSum += 2 * A[j] + A[j + 1];

				odd ^= 1;

			}

			if (abs(evenSum - oddSum) % 5 == 0)
				result.push_back(true);
			else
				result.push_back(false);
		}
		

		return result;
	}
};

class Solution2 {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector <vector <int> > v;
		v.push_back(vector<int>{0, 1});
		v.push_back(vector<int>{2, 3});
		v.push_back(vector<int>{4, 0});
		v.push_back(vector<int>{1, 2});
		v.push_back(vector<int>{3, 4});

		int act_mod = 0;
		vector <bool> res;

		for (auto w : A)
		{
			act_mod = v[act_mod][w];
			res.push_back(not act_mod);
		}
		return res;
	}
};

int main(int argc, const char* argv[]) {
	Solution2 solution;
	
	vector<int> input1{ 0,1,1 };
	auto result1 = solution.prefixesDivBy5(input1);

	vector<int> input2{ 1,1,1 };
	auto result2 = solution.prefixesDivBy5(input2);

	vector<int> input3{ 0,1,1,1,1,1 };
	auto result3 = solution.prefixesDivBy5(input3); //[true,false,false,false,true,false]

	vector<int> input4({ 1, 1, 0, 0, 0, 1, 0, 0, 1 });
	auto result4 = solution.prefixesDivBy5(input4); //[false,false,false,false,false,false,false,false,false]

	cin.get();
	return 0;
}
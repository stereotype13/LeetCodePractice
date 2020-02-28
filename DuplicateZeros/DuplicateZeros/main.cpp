/*
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.



Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]



Note:

	1 <= arr.length <= 10000
	0 <= arr[i] <= 9

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int zeroCount = 0;

		for (const auto& i : arr) {
			if (i == 0)
				++zeroCount;
		}
			

		for (int i = (int)arr.size() - 1; i >= 0; --i) {
			int shiftedIndex = i + zeroCount;
			if (arr[i] == 0) {
				
				if(shiftedIndex < (int)arr.size())
					arr[shiftedIndex] = 0;

				if (shiftedIndex - 1 < (int)arr.size())
					arr[shiftedIndex - 1] = 0;

				--zeroCount;
				continue;
			}

			if (shiftedIndex < (int)arr.size())
				arr[shiftedIndex] = arr[i];
		}
	}
};

int main() {
	Solution solution;

	vector<int> input1{ 1,0,2,3,0,4,5,0 };
	solution.duplicateZeros(input1);

	vector<int> input2{ 1,2,3 };
	solution.duplicateZeros(input2);

	vector<int> input3{ 0,0,0 };
	solution.duplicateZeros(input3);

	cin.get();
	return 0;
}
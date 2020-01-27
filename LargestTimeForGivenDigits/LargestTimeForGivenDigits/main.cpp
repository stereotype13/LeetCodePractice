/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.



Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""


Note:

A.length == 4
0 <= A[i] <= 9
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <unordered_set>

using namespace std;

class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {

		string result = "";

		string hours = "";
		string minutes = "";

		sort(A.begin(), A.end());

		do {

			hours = to_string(A[0]) + to_string(A[1]);
			minutes = to_string(A[2]) + to_string(A[3]);

			if (hours < "24" && minutes < "60") {
				string temp = hours + ":" + minutes;
				result = max(result, temp);
				temp = "";
			}

		} while (next_permutation(A.begin(), A.end()));

		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<int> vec1{ 1, 2, 3, 4 };
	cout << solution.largestTimeFromDigits(vec1) << endl;

	vector<int> vec2{ 5, 5, 5, 5 };
	cout << solution.largestTimeFromDigits(vec2) << endl;

	vector<int> vec3{ 0, 0, 1, 0 };
	cout << solution.largestTimeFromDigits(vec3) << endl;

	vector<int> vec4{ 4, 1, 0, 0 };
	cout << solution.largestTimeFromDigits(vec4) << endl;

	cin.get();
	return 0;
}
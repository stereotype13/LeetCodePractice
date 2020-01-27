/*
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.



Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5


Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		unordered_map<int, int> frequency;


		int N = A.size() / 2;

		for (const auto& i : A) {
			frequency[i]++;

			if (frequency[i] == N)
				return i;
		}

		return -1;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	
	vector<int> vec1{ 1, 2, 3, 3 };
	cout << solution.repeatedNTimes(vec1) << endl;

	vector<int> vec2{ 2,1,2,5,3,2 };
	cout << solution.repeatedNTimes(vec2) << endl;

	vector<int> vec3{ 5,1,5,2,5,3,5,4 };
	cout << solution.repeatedNTimes(vec3) << endl;

	cin.get();
	return 0;
}
/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version.
*/
#include <iostream>
#include <algorithm>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
	if (version >= 6)
		return true;

	return false;
}

class Solution {
	int helper(int low, int high) {
		if (low > high)
			return -1;

		int mid = low + (high - low) / 2;

		bool isBad = isBadVersion(mid);
		if (isBad && !isBadVersion(max(0, mid - 1))) {
			return mid;
		}

		if (!isBad) 
			return helper(mid + 1, high);

		return helper(low, mid - 1);
		
	}
public:
	int firstBadVersion(int n) {
		int high = n;
		int low = 0;

		return helper(low, high);
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.firstBadVersion(10) << endl;
	
	cin.get();
	return 0;
}
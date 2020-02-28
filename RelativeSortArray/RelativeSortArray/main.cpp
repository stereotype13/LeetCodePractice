/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  
Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.



Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]



Constraints:

	arr1.length, arr2.length <= 1000
	0 <= arr1[i], arr2[i] <= 1000
	Each arr2[i] is distinct.
	Each arr2[i] is in arr1.


*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		unordered_map<int, int> valuePositionMap;

		for (int i = 0; i < (int)arr2.size(); ++i)
			valuePositionMap[arr2[i]] = i;
		
		vector<pair<int, int>> valuePositionPairs;
		vector<int> elementsNotInArr2;
		for (const auto& i : arr1) {
			if (valuePositionMap.find(i) != valuePositionMap.end()) {
				valuePositionPairs.push_back({i, valuePositionMap[i]});
			}
			else {
				elementsNotInArr2.push_back(i);
			}
		}

		sort(valuePositionPairs.begin(), valuePositionPairs.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
		});

		sort(elementsNotInArr2.begin(), elementsNotInArr2.end());

		for (int i = 0; i < (int)valuePositionPairs.size(); ++i) 
			arr1[i] = valuePositionPairs[i].first;
		
		int arr1Index = (int)valuePositionPairs.size();
		for (const auto& i : elementsNotInArr2) {
			arr1[arr1Index] = i;
			++arr1Index;
		}
			
		return arr1;
	}
};

int main() {
	Solution solution;

	vector<int> arr11{ 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 }, arr21{ 2, 1, 4, 3, 9, 6 };
	auto result1 = solution.relativeSortArray(arr11, arr21);

	cin.get();
	return 0;
}
/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note:
You may assume that nums' length ≥ k-1 and k ≥ 1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
class KthLargest {
	multiset<int> data;
	int k = 1;
public:
	KthLargest(int k, vector<int>& nums) {
		this->k = k;

		for (const auto& i : nums)
			this->data.emplace(i);
	}

	int add(int val) {
		data.emplace(val);
		auto it = this->data.rbegin();

		for (int i = 0; i < this->k - 1; ++i)
			++it;

		return *it;
	}
};
*/



class KthLargest {
	priority_queue<int, vector<int>, greater<int>> data;
	int k = 1;
public:
	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (const auto& num : nums) {
			this->data.push(num);
			if (data.size() > this->k)
				data.pop();
		}
	}

	int add(int val) {
		if (this->data.size() < this->k || val > this->data.top())
			this->data.push(val);

		if (this->data.size() > this->k)
			this->data.pop();

		return this->data.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, const char* argv[]) {
	auto vec1 = vector<int>{ 4, 5, 8, 2 };
	KthLargest solution{ 3, vec1 };

	cout << solution.add(3) << endl;
	cout << solution.add(5) << endl;

	auto vec2 = vector<int>{};
	KthLargest solution2{ 1, vec2 };
	cout << solution2.add(-3) << endl;
	cout << solution2.add(-2) << endl;
	cout << solution2.add(-4) << endl;
	cout << solution2.add(0) << endl;
	cout << solution2.add(4) << endl;


	cin.get();
	return 0;
}
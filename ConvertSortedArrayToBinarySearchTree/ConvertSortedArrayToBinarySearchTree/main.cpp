/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

	  0
	 / \
   -3   9
   /   /
 -10  5
*/

#include <iostream>
#include <vector>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	void helper(vector<int>& nums, TreeNode* parent, bool isLeft, int low, int high) {
		if (low > high)
			return;

		if (high - low == 1) {
			auto newNode = new TreeNode(nums[low]);
			newNode->right = new TreeNode(nums[high]);

			if (isLeft)
				parent->left = newNode;
			else
				parent->right = newNode;

			return;
		}

		if(high - low == 0) {
			auto newNode = new TreeNode(nums[low]);

			if (isLeft)
				parent->left = newNode;
			else
				parent->right = newNode;

			return;
		}

		int mid = (high - low) / 2 + low;

		auto newNode = new TreeNode(nums[mid]);
		if (isLeft)
			parent->left = newNode;
		else
			parent->right = newNode;

		helper(nums, newNode, true, low, mid - 1);
		helper(nums, newNode, false, mid + 1, high);

		return;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return nullptr;

		if (nums.size() == 1)
			return new TreeNode(nums[0]);

		int low = 0, high = nums.size() - 1, mid = high / 2;
		auto newNode = new TreeNode(nums[mid]);

		helper(nums, newNode, true, 0, mid - 1);
		helper(nums, newNode, false, mid + 1, high);

		return newNode;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> input1{ -10,-3,0,5,9 };
	auto s1 = solution.sortedArrayToBST(input1);


	return 0;
}
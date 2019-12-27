/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

	  10
	 /  \
	5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	int mNumberOfPaths;

	void helper(TreeNode* root, vector<int>& nums, int sum) {
		if (!root)
			return;

		nums.push_back(root->val + nums.back());

		for (int i = nums.size() - 2; i > -1; --i) {
			if (nums.back() - nums[i] == sum)
				++mNumberOfPaths;
		}

		helper(root->left, nums, sum);
		helper(root->right, nums, sum);

		if(!nums.empty())
			nums.pop_back();

	}
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root)
			return 0;

		mNumberOfPaths = 0;
		vector<int> nums{0};
		helper(root, nums, sum);
		return mNumberOfPaths;
	}
};

class Solution2 {
public:
	void getPathSum(TreeNode* root, int sum, int currentSum, vector<int>& res, int& path) {
		if (!root)
			return;
		currentSum += root->val;
		res.push_back(root->val);
		if (currentSum == sum)
			path += 1;
		int k = currentSum;
		for (int i = 0; i < res.size() - 1; i++) {
			k -= res[i];
			if (k == sum) {
				path += 1;
			}
		}
		getPathSum(root->left, sum, currentSum, res, path);
		getPathSum(root->right, sum, currentSum, res, path);
		res.pop_back();
	}
	int pathSum(TreeNode* root, int sum) {
		int path = 0;
		if (!root)
			return path;
		vector<int> res;
		int currentSum = 0;
		getPathSum(root, sum, currentSum, res, path);
		return path;
	}
};

int main(int argc, char* argv[]) {
	Solution2 solution;
	auto tree1 = buildTree("[10,5,-3,3,2,null,11,3,-2,null,1]"); //3
	cout << solution.pathSum(tree1, 8) << endl;

	auto tree2 = buildTree("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
	cout << solution.pathSum(tree2, 22) << endl;

	auto tree3 = buildTree("[1, 2]");
	cout << solution.pathSum(tree3, 1) << endl;

	auto tree4 = buildTree("[1, 2]");
	cout << solution.pathSum(tree4, 2) << endl;

	auto tree5 = buildTree("[1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0]");
	cout << solution.pathSum(tree5, 2) << endl;

	auto tree6 = buildTree("[0, 0, null, 0, null, 0, null, 0]");
	cout << solution.pathSum(tree6, 0) << endl;

	cin.get();

	return 0;
}
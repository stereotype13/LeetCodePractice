/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

		  4
		/   \
	  2      6
	 / \
	1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
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
#include "..//..//LeetCodeTree.hpp"
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
	int minDiff = INT_MAX;

	pair<int, int> helper(TreeNode* node) {
		if (!node)
			return pair<int, int>{INT_MAX, INT_MIN};

		auto left = helper(node->left);
		minDiff = min(minDiff, abs(node->val - left.second));

		auto right = helper(node->right);
		minDiff = min(minDiff, abs(node->val - right.first));

		auto result = pair<int, int>{min(left.first, right.first), max(left.second, right.second)};
		result.first = min(node->val, result.first);
		result.second = max(node->val, result.second);



		return result;
	}
public:
	int minDiffInBST(TreeNode* root) {
		helper(root);
		return minDiff;
	}
};

int main() {
	Solution solution;

	auto tree1 = buildTree("[4,2,6,1,3,null,null]");
	cout << solution.minDiffInBST(tree1) << endl;

	auto tree2 = buildTree("[90,69,null,49,89,null,52,null,null,null,null]");
	cout << solution.minDiffInBST(tree2) << endl;

	cin.get();
	return 0;
}
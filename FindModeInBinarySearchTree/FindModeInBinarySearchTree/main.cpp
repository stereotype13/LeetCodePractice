/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


For example:
Given BST [1,null,2,2],

   1
	\
	 2
	/
   2


return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
#include <unordered_map>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	void helper(TreeNode* node, unordered_map<int, int>& frequencies) {
		if (!node)
			return;

		frequencies[node->val]++;
		helper(node->left, frequencies);
		helper(node->right, frequencies);
	}
public:
	vector<int> findMode(TreeNode* root) {
		if (!root)
			return {};

		unordered_map<int, int> frequencies;
		helper(root, frequencies);

		int maxFrequency = 0;
		for (const auto& p : frequencies) {
			if (p.second >= maxFrequency)
				maxFrequency = p.second;
		}

		vector<int> result;
		for (const auto& p : frequencies) {
			if (p.second == maxFrequency)
				result.push_back(p.first);
		}
		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	auto tree1 = buildTree("[1,null,2,2]");
	auto result1 = solution.findMode(tree1);

	cin.get();
	return 0;
}
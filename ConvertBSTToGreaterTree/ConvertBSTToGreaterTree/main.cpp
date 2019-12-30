/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original 
key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
			  5
			/   \
		   2     13

Output: The root of a Greater Tree like this:
			 18
			/   \
		  20     13
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
#include <algorithm>

using namespace std;

class Solution {
	int helper(TreeNode* node, int sumAbove) {
		if (!node->left && !node->right) {
			node->val += sumAbove;
			return node->val;
		}

		if (node->right)
			node->val += helper(node->right, sumAbove);
		else
			node->val += sumAbove;
	
		if (node->left)
			return helper(node->left, node->val);
		
		return node->val;
	}

public:
	TreeNode* convertBST(TreeNode* root) {
		if (!root)
			return nullptr;

		helper(root, 0);
		return root;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	auto tree1 = buildTree("[5, 3, 7, 2, 4, 6, 8, 1, null, null, null, null, null, null, 9]");
	auto result1 = solution.convertBST(tree1);

	return 0;
}
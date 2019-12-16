/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

	3
   / \
  9  20
	/  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

	   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
Return false.
*/

#include <iostream>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	pair<bool, int> helper(TreeNode* root, int currentDepth) {
		if (!root->left && !root->right)
			return {true, currentDepth};

		pair<bool, int> leftPair{ true, currentDepth }, rightPair{true, currentDepth};
		if (root->left) {
			leftPair = helper(root->left, currentDepth + 1);
			if (!leftPair.first)
				return {false, 0};
		}
			

		if (root->right) {
			rightPair = helper(root->right, currentDepth + 1);
			if (!rightPair.first)
				return { false, 0 };
		}

		if (abs(leftPair.second - rightPair.second) < 2)
			return { true, max(leftPair.second, rightPair.second) };

		return { false, 0 };
			
	}
public:
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;

		return helper(root, 1).first;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	auto tree1 = buildTree("[3,9,20,null,null,15,7]");
	cout << solution.isBalanced(tree1) << endl;

	auto tree2 = buildTree("[1,2,2,3,3,null,null,4,4]");
	cout << solution.isBalanced(tree2) << endl;

	auto tree3 = buildTree("[1,2]");
	cout << solution.isBalanced(tree3) << endl;

	auto tree4 = buildTree("[1,2,3,4,5,null,6,7]");
	cout << solution.isBalanced(tree4) << endl;

	cin.get();
	return 0;
}

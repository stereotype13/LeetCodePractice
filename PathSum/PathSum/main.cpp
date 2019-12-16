/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

	  5
	 / \
	4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
#include <iostream>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	int target;

	bool helper(TreeNode* root, int sum) {
		if (!root->left && !root->right && sum + root->val == target)
			return true;


		if (root->left && helper(root->left, sum + root->val)) return true;
		if (root->right && helper(root->right, sum + root->val)) return true;
			
		return false;
	}
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) 
			return false;

		target = sum;
		return helper(root, 0);
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	auto tree1 = buildTree("[5, 4, 8, 11, null, 13, 4, 7, 2, null, 1]");
	cout << solution.hasPathSum(tree1, 22) << endl;

	auto tree2 = buildTree("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
	cout << solution.hasPathSum(tree2, 22) << endl;

	cin.get();
	return 0;
}
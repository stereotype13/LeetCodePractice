/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.



Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23


Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
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

using namespace std;

class Solution {
	void getSum(TreeNode* node, int L, int R, int& sum) {

		if (!node)
			return;

		if (node->val >= L && node->val <= R) {
			sum += node->val;
			getSum(node->left, L, R, sum);
			getSum(node->right, L, R, sum);
			return;
		}

		if (node->val > R) {
			getSum(node->left, L, R, sum);
			return;
		}
			
		getSum(node->right, L, R, sum);

	}
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		int sum = 0;
		getSum(root, L, R, sum);
		return sum;
	}
};

int main() {
	Solution solution;

	auto tree1 = buildTree("[10,5,15,3,7,null,18]");
	cout << solution.rangeSumBST(tree1, 7, 15) << endl;



	cin.get();
	return 0;
}
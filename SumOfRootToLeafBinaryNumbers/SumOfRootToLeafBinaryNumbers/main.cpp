/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.



Example 1:

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22



Note:

	The number of nodes in the tree is between 1 and 1000.
	node.val is 0 or 1.
	The answer will not exceed 2^31 - 1.


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
#include <numeric>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	void helper(TreeNode* node, vector<int>& data, vector<int>& result) {
		if (!node->left && !node->right) {
			int sum = 0, exponent = 0;

			data.push_back(node->val);
			for (int i = (int)data.size() - 1; i > -1; --i) {
				sum += pow(2, exponent) * data[i];
				++exponent;
			}
				

			result.push_back(sum);
			data.pop_back();
			return;
		}

		data.push_back(node->val);

		if (node->left)
			helper(node->left, data, result);

		if (node->right)
			helper(node->right, data, result);

		data.pop_back();
			

	}
public:
	int sumRootToLeaf(TreeNode* root) {
		if (!root)
			return 0;

		vector<int> data, result;
		helper(root, data, result);

		return accumulate(result.begin(), result.end(), 0);
	}
};

int main() {
	Solution solution;

	auto tree1 = buildTree("[1,0,1,0,1,0,1]");
	cout << solution.sumRootToLeaf(tree1) << endl;


	cin.get();
	return 0;
}
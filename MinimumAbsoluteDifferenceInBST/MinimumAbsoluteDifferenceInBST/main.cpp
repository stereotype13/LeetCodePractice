/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
	\
	 3
	/
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note: There are at least two nodes in this BST.
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
#include <vector>

using namespace std;

class Solution {
	void helper(TreeNode* root, vector<int>& numbers) {
		if (!root)
			return;

		numbers.push_back(root->val);
		helper(root->left, numbers);
		helper(root->right, numbers);
		
	}
public:
	int getMinimumDifference(TreeNode* root) {
		vector<int> numbers;
		helper(root, numbers);

		sort(numbers.begin(), numbers.end());

		int minDifference = INT_MAX;
		for (int i = 1; i < numbers.size(); ++i) {
			minDifference = min(minDifference, abs(numbers[i] - numbers[i - 1]));
		}
		return minDifference;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	auto tree1 = buildTree("[1, null, 3, null, null, 2, null]");
	cout << solution.getMinimumDifference(tree1) << endl;

	auto tree2 = buildTree("[5, 3, 7, 2, 4, 6, 8, 1, null, null, null, null, null, null, 9]");
	cout << solution.getMinimumDifference(tree2) << endl;

	auto tree3 = buildTree("[236,104,701,null,227,null,911]");
	cout << solution.getMinimumDifference(tree3) << endl;

	cin.get();
	return 0;

}
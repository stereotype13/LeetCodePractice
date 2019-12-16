/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
		  / \       / \
		 2   3     2   3

		[1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
		  /           \
		 2             2

		[1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
		  / \       / \
		 2   1     1   2

		[1,2,1],   [1,1,2]

Output: false
*/
#include <iostream>
#include <string>
#include <vector>
#include "LeetCodeTree.hpp"

using namespace std;

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;

		if ((p && !q) || (!p && q))
			return false;

		if (p->val != q->val)
			return false;

		if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
			return true;

		return false;
	}
};


int main(int argc, char* argv[]) {

	Solution solution;

	auto tree1 = buildTree("[390, 255, 2266, -273, 337, 1105, 3440, -425, 4113, null, null, 600, 1355, 3241, 4731, -488, -367, 16, null, 565, 780, 1311, 1755, 3075, 3392, 4725, 4817, null, null, null, null, -187, 152, 395, null, 728, 977, 1270, null, 1611, 1786, 2991, 3175, 3286, null, 164, null, null, 4864, -252, -95, 82, null, 391, 469, 638, 769, 862, 1045, 1138, null, 1460, 1663, null, 1838, 2891, null, null, null, null, 3296, 3670, 4381, null, 4905, null, null, null, -58, null, null, null, null, null, null, null, null, 734, null, 843, 958, null, null, null, 1163, 1445, 1533, null, null, null, 2111, 2792, null, null, null, 3493, 3933, 4302, 4488, null, null, null, null, null, null, 819, null, null, null, null, 1216, null, null, 1522, null, 1889, 2238, 2558, 2832, null, 3519, 3848, 4090, 4165, null, 4404, 4630, null, null, null, null, null, null, 1885, 2018, 2199, null, 2364, 2678, null, null, null, 3618, 3751, null, 4006, null, null, 4246, null, null, 4554, null, null, null, 1936, null, null, null, null, 2444, 2642, 2732, null, null, null, null, null, null, null, 4253, null, null, null, null, 2393, 2461, null, null, null, null, 4250, null, null, null, null, 2537]");
	auto tree2 = buildTree("[390, 255, 2266, -273, 337, 1105, 3440, -425, 4113, null, null, 600, 1355, 3241, 4731, -488, -367, 16, null, 565, 780, 1311, 1755, 3075, 3392, 4725, 4817, null, null, null, null, -187, 152, 395, null, 728, 977, 1270, null, 1611, 1786, 2991, 3175, 3286, null, 164, null, null, 4864, -252, -95, 82, null, 391, 469, 638, 769, 862, 1045, 1138, null, 1460, 1663, null, 1838, 2891, null, null, null, null, 3296, 3670, 4381, null, 4905, null, null, null, -58, null, null, null, null, null, null, null, null, 734, null, 843, 958, null, null, null, 1163, 1445, 1533, null, null, null, 2111, 2792, null, null, null, 3493, 3933, 4302, 4488, null, null, null, null, null, null, 819, null, null, null, null, 1216, null, null, 1522, null, 1889, 2238, 2558, 2832, null, 3519, 3848, 4090, 4165, null, 4404, 4630, null, null, null, null, null, null, 1885, 2018, 2199, null, 2364, 2678, null, null, null, 3618, 3751, null, 4006, null, null, 4246, null, null, 4554, null, null, null, 1936, null, null, null, null, 2444, 2642, 2732, null, null, null, null, null, null, null, 4253, null, null, null, null, 2461, 2393, null, null, null, null, 4250, null, null, null, null, 2537]");

	cout << "tree1 and tree2 are " << (solution.isSameTree(tree1, tree2) ? "" : "NOT ") << "equal." << endl;

	delete tree1;
	delete tree2;

	cin.get();
	return 0;
}
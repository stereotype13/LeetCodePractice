/*
A quadtree is a tree data in which each internal node has exactly four children: topLeft, topRight, bottomLeft and bottomRight. 
Quad trees are often used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions.

We want to store True/False information in our quad tree. The quad tree is used to represent a N * N boolean grid. 
For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same. 
Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. 
The val attribute for a leaf node contains the value of the region it represents.

For example, below are two quad trees A and B:

A:
+-------+-------+   T: true
|       |       |   F: false
|   T   |   T   |
|       |       |
+-------+-------+
|       |       |
|   F   |   F   |
|       |       |
+-------+-------+
topLeft: T
topRight: T
bottomLeft: F
bottomRight: F

B:
+-------+---+---+
|       | F | F |
|   T   +---+---+
|       | T | T |
+-------+---+---+
|       |       |
|   T   |   F   |
|       |       |
+-------+-------+
topLeft: T
topRight:
	 topLeft: F
	 topRight: F
	 bottomLeft: T
	 bottomRight: T
bottomLeft: T
bottomRight: F


Your task is to implement a function that will take two quadtrees and return a quadtree that represents the logical OR (or union) of the two trees.
*/

#define NULL nullptr


// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {
		Node* node;
		if (quadTree1->isLeaf && quadTree2->isLeaf) {
			node = new Node(quadTree1->val || quadTree2->val, true, NULL, NULL, NULL, NULL);
		}
		else if (quadTree1->isLeaf) {
			if (quadTree1->val) node = quadTree1;
			else node = quadTree2;
		}
		else if (quadTree2->isLeaf) {
			if (quadTree2->val) node = quadTree2;
			else node = quadTree1;
		}
		else {
			node = new Node(quadTree1->val || quadTree2->val, false, NULL, NULL, NULL, NULL);

			node->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
			node->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
			node->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
			node->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

			if (node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf  // all leaves
				&& ((node->topLeft->val && node->topRight->val && node->bottomLeft->val && node->bottomRight->val)        // all true
					|| (!node->topLeft->val && !node->topRight->val && !node->bottomLeft->val && !node->bottomRight->val))) {  // all false
				node->val = node->topLeft->val;
				node->topLeft = NULL;
				node->topRight = NULL;
				node->bottomLeft = NULL;
				node->bottomRight = NULL;
				node->isLeaf = true;
			}
		}
		return node;
	}
};

int main(int argc, const char* argv[]) {
	Node* tree1 = new Node();
	tree1->isLeaf = false;
	tree1->topLeft = new Node(true, true, nullptr, nullptr, nullptr, nullptr);
	tree1->topRight = new Node(true, true, nullptr, nullptr, nullptr, nullptr);
	tree1->bottomLeft = new Node(false, true, nullptr, nullptr, nullptr, nullptr);
	tree1->bottomRight = new Node(false, true, nullptr, nullptr, nullptr, nullptr);

	Node* tree2 = new Node();
	tree2->topLeft = new Node(true, true, nullptr, nullptr, nullptr, nullptr);
	tree2->topRight = new Node(true, false, nullptr, nullptr, nullptr, nullptr);

	tree2->topRight->topRight = new Node(false, true, nullptr, nullptr, nullptr, nullptr);
	tree2->topRight->topLeft = new Node(false, true, nullptr, nullptr, nullptr, nullptr);
	tree2->topRight->bottomLeft = new Node(true, true, nullptr, nullptr, nullptr, nullptr);
	tree2->topRight->bottomRight = new Node(true, true, nullptr, nullptr, nullptr, nullptr);

	tree2->bottomLeft = new Node(true, true, nullptr, nullptr, nullptr, nullptr);
	tree2->bottomRight = new Node(false, true, nullptr, nullptr, nullptr, nullptr);

	Solution solution;
	auto result = solution.intersect(tree1, tree2);

	return 0;
}
/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/*
 * Definition for singly-linked list.
 */

 

#include <iostream>
#include <vector>
#include "..//..//LeetCodeList.hpp"

using namespace std;


class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head)
			return nullptr;

		ListNode *parent = nullptr, *child = head, *originalHead = head;

		while (child) {
			if (child->val == val) {
				if (parent)
					parent->next = child->next;
				else {
					originalHead = child->next;
					child->next = nullptr;
					delete child;
					child = originalHead;
					parent = nullptr;
					continue;
				}
					

				child->next = nullptr;
				delete child;
				child = parent->next;
				continue;
			}

			parent = child;
			child = child->next;
		}
		return originalHead;
	}
};


int main(int argc, char* argv[]) {
	Solution solution;
	ListNode* list1 = makeList(vector<int>{6, 1, 2, 6, 3, 4, 5, 6});
	printList(solution.removeElements(list1, 6));

	cin.get();
	return 0;
}
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/
#include <iostream>
#include <unordered_set>

using namespace std;

 struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
 };
 
class Solution {
public:
	/*This is for BOTH a SORTED and UNSORTED linked list.*/
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return 0;

		ListNode* first = head;

		unordered_set<int> seenNumbers;

		ListNode* previous = 0;
		while (head) {
			int val = head->val;

			if (seenNumbers.find(val) == seenNumbers.end()) {
				seenNumbers.emplace(val);
				previous = head;
				head = head->next;
				continue;
			}

			previous->next = head->next;
			ListNode* temp = head;
			head = previous->next;

			delete temp;
		}

		return first;
	}
};

void printList(ListNode* node) {
	while (node) {
		cout << node->val << '\t';
		node = node->next;
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	Solution solution;

	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(1);
	list1->next->next = new ListNode(2);

	printList(solution.deleteDuplicates(list1));

	ListNode* list2 = new ListNode(1);
	list2->next = new ListNode(1);
	list2->next->next = new ListNode(2);
	list2->next->next->next = new ListNode(3);
	list2->next->next->next->next = new ListNode(3);

	printList(solution.deleteDuplicates(list2));

	cin.get();
	return 0;
}
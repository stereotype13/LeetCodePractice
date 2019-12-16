#pragma once

#include <iostream>
#include <vector>

#define NULL nullptr

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* makeList(const std::vector<int> vec) {
	if (vec.size() == 0)
		return nullptr;

	ListNode* head = new ListNode(vec[0]);
	ListNode* originalHead = head;

	for (int i = 1; i < vec.size(); ++i) {
		head->next = new ListNode(vec[i]);
		head = head->next;
	}

	return originalHead;
}

void printList(ListNode* head) {
	while (head) {
		std::cout << head->val;
		if (head->next)
			std::cout << "->";

		head = head->next;
	}
}
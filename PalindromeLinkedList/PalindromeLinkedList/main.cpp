/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include <iostream>
#include "..//..//LeetCodeList.hpp"

using namespace std;

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head)
			return true;

		vector<int> listArray;

		while (head) {
			listArray.push_back(head->val);
			head = head->next;
		}

		int low = 0, high = listArray.size() - 1;

		while (low < high) {
			if (listArray[low] != listArray[high])
				return false;

			++low;
			--high;
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	ListNode* list1 = makeList({ 1, 2 });
	cout << solution.isPalindrome(list1) << endl;

	ListNode* list2 = makeList({ 1, 2, 2, 1 });
	cout << solution.isPalindrome(list2) << endl;

	cin.get();
	return 0;
}
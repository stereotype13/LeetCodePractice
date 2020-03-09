/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.



Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include "..//..//LeetCodeList.hpp"

using namespace std;

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		vector<int> digits;

		while (head) {
			digits.push_back(head->val);
			head = head->next;
		}

		int result = 0;
		int power = 1;
		while (!digits.empty()) {
			result += power * digits.back();
			digits.pop_back();
			power *= 2;
		}

		return result;
	}
};

int main() {
	Solution solution;

	auto list1 = makeList({ 1, 0, 1 });
	cout << solution.getDecimalValue(list1) << endl;

	auto list2 = makeList({ 0 });
	cout << solution.getDecimalValue(list2) << endl;

	auto list3 = makeList({ 1 });
	cout << solution.getDecimalValue(list3) << endl;

	auto list4 = makeList({ 1,0,0,1,0,0,1,1,1,0,0,0,0,0,0 });
	cout << solution.getDecimalValue(list4) << endl;

	auto list5 = makeList({ 0,0 });
	cout << solution.getDecimalValue(list5) << endl;


	cin.get();
	return 0;
}
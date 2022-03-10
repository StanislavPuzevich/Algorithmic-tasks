//2. Add Two Numbers
//
//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order,
//and each of their nodes contains a single digit.Add the two numbersand return the sum as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example 1:
//Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
//Output : [7, 0, 8]
//Explanation : 342 + 465 = 807.

//Constraints:
//The number of nodes in each linked list is in the range[1, 100].
//0 <= Node.val <= 9
//It is guaranteed that the list represents a number that does not have leading zeros.

#include <iostream>

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* res = new ListNode;
		ListNode* head = res;

		bool ch = false;
		while (l1 != nullptr && l2 != nullptr)
		{
			res->next = new ListNode;
			res = res->next;
			if ((l1->val + l2->val + ch) >= 10)
			{
				res->val = (l1->val + l2->val + ch) % 10;
				ch = true;
			}
			else
			{
				res->val = l1->val + l2->val + ch;
				ch = false;
			}
			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != nullptr)
		{
			res->next = new ListNode;
			res = res->next;
			if ((l1->val + ch) >= 10)
			{
				res->val = (l1->val + ch) % 10;
				ch = true;
			}
			else
			{
				res->val = l1->val + ch;
				ch = false;
			}
			l1 = l1->next;
		}
		while (l2 != nullptr)
		{
			res->next = new ListNode;
			res = res->next;
			if ((l2->val + ch) >= 10)
			{
				res->val = (l2->val + ch) % 10;
				ch = true;
			}
			else
			{
				res->val = l2->val + ch;
				ch = false;
			}
			l2 = l2->next;
		}
		if (ch)
		{
			res->next = new ListNode;
			res = res->next;
			res->val = 1;
		}
		return head->next;
	}
};
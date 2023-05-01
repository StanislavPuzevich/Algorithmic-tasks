//61. Rotate List
//
//Given the head of a linked list, rotate the list to the right by k places.
//
//Example 1:
//Input: head = [1, 2, 3, 4, 5], k = 2
//Output : [4, 5, 1, 2, 3]
//
//Example 2 :
//Input : head = [0, 1, 2], k = 4
//Output : [2, 0, 1]
//
//Constraints :
//	The number of nodes in the list is in the range[0, 500].
//	- 100 <= Node.val <= 100
//	0 <= k <= 2 * 10^9

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
	ListNode* rotateRight(ListNode* head, int k)
	{
		size_t size = 0;
		ListNode* cur = head;

		while (cur != nullptr)
		{
			cur = cur->next;
			size++;
		}

		if (size == 0 || size == 1 || k % size == 0) return head;

		k %= size;
		cur = head;
		int i = 1;
		while (cur != nullptr && i < size - k)
		{
			cur = cur->next;
			i++;
		}
		ListNode* temp = cur->next;
		cur->next = nullptr;

		cur = temp;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = head;

		return cur;
	}
};

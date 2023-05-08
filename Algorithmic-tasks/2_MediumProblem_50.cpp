//19. Remove Nth Node From End of List(Medium)
//
//----------------------------------------------------------------------------- 
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
//----------------------------------------------------------------------------- 
// 
//Given the head of a linked list, remove the nth node from the end of the listand return its head.
//
//Example 1:
//	Input: head = [1, 2, 3, 4, 5], n = 2
//	Output : [1, 2, 3, 5]
//
//Example 2 :
//	Input : head = [1], n = 1
//	Output : []
//
//Example 3 :
//	Input : head = [1, 2], n = 1
//	Output : [1]
//
//Constraints :
//	The number of nodes in the list is sz.
//	1 <= sz <= 30
//	0 <= Node.val <= 100
//	1 <= n <= sz
//
//Follow up : Could you do this in one pass?

#include <iostream>
#include <vector>

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution
 {
 public:
	 //Doesn't fulfill the requirement 'do this in one pass' 
	 ListNode* removeNthFromEnd(ListNode* head, int n)
	 {
		 int counter = 0;
		 ListNode* copy = head;

		 while (copy)
		 {
			 counter++;
			 copy = copy->next;
		 }

		 copy = head;
		 if (counter == n) return head->next;

		 while (counter - n - 1)
		 {
			 counter--;
			 copy = copy->next;
		 }

		 copy->next = copy->next->next;

		 return head;
	 }

	 //Fulfills the requirement 'do this in one pass' 
	 ListNode* removeNthFromEnd_vers2(ListNode* head, int n)
	 {
		 ListNode* fast = head;
		 ListNode* slow = head;

		 while (n--)
			 fast = fast->next;

		 if (!fast)
			 return head->next;

		 while (fast->next)
		 {
			 slow = slow->next; 
			 fast = fast->next;
		 }

		 slow->next = slow->next->next;

		 return head;
	 }
 };

int main()
{
	Solution s;
	ListNode fifth (5);
	ListNode fourth(4, &fifth);
	ListNode third (3, &fourth);
	ListNode second(2, &third);
	ListNode first (1, &second);

	std::cout << s.removeNthFromEnd_vers2(&first, 2) << std::endl;

	return 0;
}

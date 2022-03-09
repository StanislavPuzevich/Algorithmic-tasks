//82. Remove Duplicates from Sorted List II
//
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.Return the linked list sorted as well.
//
//Example 1:
//Input: head = [1, 2, 3, 3, 4, 4, 5]
//Output : [1, 2, 5]
//
//Constraints :
//    The number of nodes in the list is in the range[0, 300].
//    - 100 <= Node.val <= 100
//    The list is guaranteed to be sorted in ascending order.

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* p = new ListNode(0, head);
        ListNode* q = p;
        bool rep = false;

        while (head != nullptr)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                    head = head->next;
                q->next = head->next;
            }
            else
                q = head;
            head = head->next;
        }
        return p->next;
    }
};

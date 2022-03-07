//21. Merge Two Sorted Lists
// 
//You are given the heads of two sorted linked lists list1 and list2.
//Merge the two lists in a one sorted list.The list should be made by splicing together the nodes of the first two lists.
//Return the head of the merged linked list.
//
//Example 1:
//    Input: list1 = [1, 2, 4], list2 = [1, 3, 4]
//    Output : [1, 1, 2, 3, 4, 4]
//Example 2 :
//    Input : list1 = [], list2 = []
//    Output : []
//
//Constraints :
//    The number of nodes in both lists is in the range[0, 50].
//    - 100 <= Node.val <= 100
//    Both list1 and list2 are sorted in non - decreasing order.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* temp = new ListNode(0,list1);
        ListNode* result = new ListNode(0, temp);

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                temp -> next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else
            {
                temp-> next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        while (list1 != nullptr)
        {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }

        return result->next->next;
    }
};
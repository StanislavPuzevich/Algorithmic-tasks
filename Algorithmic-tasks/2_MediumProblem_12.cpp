﻿//148. Sort List
//
//Given the head of a linked list, return the list after sorting it in ascending order.
//
//Example 1:
//Input: head = [4, 2, 1, 3]
//Output : [1, 2, 3, 4]
//
//Example 2 :
//Input : head = [-1, 5, 3, 4, 0]
//Output : [-1, 0, 3, 4, 5]
//
//Constraints :
//    The number of nodes in the list is in the range[0, 5 * 104].
//    - 105 <= Node.val <= 105
//
// Follow up : Can you sort the linked list in O(n logn) time and O(1) memory(i.e.constant spac

#include <iostream>   
#include <vector> 
#include <algorithm>


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
    ListNode* sortList(ListNode* head) 
    {
        std::vector<int> vec; 
        ListNode* temp = head;
        
        while (temp != nullptr)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        sort(vec.begin(), vec.end());

        temp = head;
        for (auto i : vec)
        {
            temp->val = i;
            temp = temp->next;
        }

        return head;
    }
};
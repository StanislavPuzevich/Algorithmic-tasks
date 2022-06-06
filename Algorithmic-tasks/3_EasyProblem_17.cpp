//160. Intersection of Two Linked Lists
//
//Given the heads of two singly linked - lists headA and headB, return the node at which the two lists intersect.If the two linked lists have no intersection at all, return null.
//For example, the following two linked lists begin to intersect at node c1 :
//
//The test cases are generated such that there are no cycles anywhere in the entire linked structure.
//Note that the linked lists must retain their original structure after the function returns.
//
//Custom Judge :
//The inputs to the judge are given as follows(your program is not given these inputs) :
//    intersectVal - The value of the node where the intersection occurs.This is 0 if there is no intersected node.
//    listA - The first linked list.
//    listB - The second linked list.
//    skipA - The number of nodes to skip ahead in listA(starting from the head) to get to the intersected node.
//    skipB - The number of nodes to skip ahead in listB(starting from the head) to get to the intersected node.
//    The judge will then create the linked structure based on these inputs and pass the two heads, headAand headB to your program.If you correctly return the intersected node,
//    then your solution will be accepted.
//
//Example 1:
//Input: intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 6, 1, 8, 4, 5], skipA = 2, skipB = 3
//Output : Intersected at '8'
//Explanation : The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
//From the head of A, it reads as[4, 1, 8, 4, 5].From the head of B, it reads as[5, 6, 1, 8, 4, 5].There are 2 nodes before the intersected node in A; 
//There are 3 nodes before the intersected node in B.
//
//Constraints:
//The number of nodes of listA is in the m.
//The number of nodes of listB is in the n.
//1 <= m, n <= 3 * 104
//1 <= Node.val <= 105
//0 <= skipA < m
//    0 <= skipB < n
//    intersectVal is 0 if listAand listB do not intersect.
//    intersectVal == listA[skipA] == listB[skipB] if listAand listB intersect

#include <iostream>


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
    ListNode* getIntersectionNode_1(ListNode* headA, ListNode* headB)       // 1st version 12.03.2022
    {
        int sizeA = 0, sizeB = 0;
        ListNode* listA = headA;
        ListNode* listB = headB;

        while (listA || listB)
        {
            if (listA)
            {
                listA = listA->next;
                sizeA++;
            }
            if (listB)
            {
                listB = listB->next;
                sizeB++;
            }
        }

        listA = headA;
        listB = headB;

        if (sizeA >= sizeB)
        {
            sizeA -= sizeB;
            while (sizeA)
            {
                listA = listA->next;
                sizeA--;
            }
        }
        else
        {
            sizeB -= sizeA;
            while (sizeB)
            {
                listB = listB->next;
                sizeB--;
            }
        }

        while (listA && listB)
        {
            if (listA == listB)
                return listA;
            else
            {
                listA = listA->next;
                listB = listB->next;
            }
        }
        return nullptr;
    }
    
    ListNode* getIntersectionNode_2(ListNode* headA, ListNode* headB)       // 2nd version 06.06.2022
    {
        int dif = 0;
        bool check;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 && temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1)
        {
            check = true;
            while (temp1)
            {
                temp1 = temp1->next;
                dif++;
            }
        }
        else
        {
            check = false;
            while (temp2)
            {
                temp2 = temp2->next;
                dif++;
            }
        }
        
        if (check)
        {
            while (dif)
            {
                headA = headA->next;
                dif--;
            }
        }
        else
        {
            while (dif)
            {
                headB = headB->next;
                dif--;
            }
        }

        while (headA && headB)
        {
            if (headA == headB) return headA;

            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};

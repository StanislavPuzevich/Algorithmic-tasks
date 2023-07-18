//445. Add Two Numbers II(Medium)
//
//--------------------------------------------------- 
// https://leetcode.com/problems/add-two-numbers-ii/
//--------------------------------------------------- 
// 
//You are given two non - empty linked lists representing two non - negative integers.
//The most significant digit comes first and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example 1:
//    Input: l1 = [7, 2, 4, 3], l2 = [5, 6, 4]
//    Output : [7, 8, 0, 7]
//
//Example 2 :
//    Input : l1 = [2, 4, 3], l2 = [5, 6, 4]
//    Output : [8, 0, 7]
// 
//Example 3 :
//    Input : l1 = [0], l2 = [0]
//    Output : [0]
//
//Constraints :
//    The number of nodes in each linked list is in the range[1, 100].
//    0 <= Node.val <= 9
//    It is guaranteed that the list represents a number that does not have leading zeros.

#include <iostream>
#include <stack>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// This solution looks so awful, but it works
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sizeL1 = LestLenght(l1);
        int sizeL2 = LestLenght(l2);

        ListNode* head = l1;
        if (sizeL1 == sizeL2)
        {
            int sum = addTwoNumbersHelper(l1, l2);
            if (sum)
            {
                ListNode* previous = new ListNode(sum, head);
                head = previous;
            }
        }
        else
        {
            if (sizeL2 > sizeL1)
            {
                ListNode* temp = l1;
                l1 = l2;
                l2 = temp;
            }

            head = l1;
            int diff = abs(sizeL1 - sizeL2);
            std::stack<ListNode*> st;
            while (--diff > 0)
            {
                st.push(l1);
                l1 = l1->next;
            }

            st.push(l1);
            l1->val += addTwoNumbersHelper(l1->next, l2);
            if (l1->val > 9)
            {
                int check = l1->val;
                l1->val -= 10;
                st.pop();
                while (!st.empty())
                {
                    st.top()->val += 1;
                    check = st.top()->val;
                    if (check < 10)
                        return head;
                    st.top()->val -= 10;
                    st.pop();
                }

                if (check > 9)
                {
                    ListNode* previous = new ListNode(1, head);
                    head = previous;
                }
            }
        }

        return head;
    }
    
    int LestLenght(ListNode* list)
    {
        int lenght = 0;
        while (list)
        {
            lenght++;
            list = list->next;
        }
        return lenght;
    }

    int addTwoNumbersHelper(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr || l2 == nullptr) return 0;

        int sum = 0;
        sum += addTwoNumbersHelper(l1->next, l2->next);

        if (l1->val + l2->val + sum > 9)
        {
            l1->val += l2->val + sum - 10;
            return 1;
        }

        l1->val += l2->val + sum;
        return 0;
    }
};

// 1-st list: 6 -> 4 -> 5 -> 0 -> 4 -> 4 -> 9 -> 4 -> 1
// 2-nd list: 3 -> 8 -> 8 -> 0 -> 3 -> 0 -> 1 -> 4 -> 8
void testInput(ListNode& l1, ListNode& l2)
{
    static ListNode firstList(1);
    static ListNode firstList_(4, &firstList);
    static ListNode firstList__(9, &firstList_);
    static ListNode firstList___(4, &firstList__);
    static ListNode firstList____(4, &firstList___);
    static ListNode firstList_____(0, &firstList____);
    static ListNode firstList______(5, &firstList_____);
    static ListNode firstList_______(4, &firstList______);
    l1.val = 6;
    l1.next = &firstList_______;

    static ListNode secondList(8);
    static ListNode secondList_(4, &secondList);
    static ListNode secondList__(1, &secondList_);
    static ListNode secondList___(0, &secondList__);
    static ListNode secondList____(3, &secondList___);
    static ListNode secondList_____(0, &secondList____);
    static ListNode secondList______(8, &secondList_____);
    static ListNode secondList_______(8, &secondList______);
    l2.val = 3;
    l2.next = &secondList_______;
}

int main()
{
    Solution s;

    ListNode list1;
    ListNode list2;

    testInput(list1, list2);
    
    ListNode* result = s.addTwoNumbers(&list1, &list2);
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}

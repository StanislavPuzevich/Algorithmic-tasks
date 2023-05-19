//23. Merge k Sorted Lists(Hard)
//
//----------------------------------------------------------------- 
// https://leetcode.com/problems/merge-k-sorted-lists/description/
//----------------------------------------------------------------- 
// 
//You are given an array of k linked - lists lists, each linked - list is sorted in ascending order.
//Merge all the linked - lists into one sorted linked - list and return it.
//
//Example 1:
//	Input: lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
//	Output : [1, 1, 2, 3, 4, 4, 5, 6]
//	Explanation : The linked - lists are :
//	[
//		1->4->5,
//		1->3->4,
//		2->6
//	]
//merging them into one sorted list :
//1->1->2->3->4->4->5->6
//
//Example 2 :
//	Input : lists = []
//	Output : []
//
//Example 3 :
//	Input : lists = [[]]
//	Output : []
//
//Constraints :
//	k == lists.length
//	0 <= k <= 10^4
//	0 <= lists[i].length <= 500
//	- 10^4 <= lists[i][j] <= 10^4
//	lists[i] is sorted in ascending order.
//	The sum of lists[i].length will not exceed 10^4.

#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
	 void freeListNode(ListNode*);
 };

void ListNode::freeListNode(ListNode* head)
{
	while (head)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}
 
class Solution 
{
public:
	ListNode* mergeKLists(std::vector<ListNode*>&lists) 
	{
		std::vector<int> nums;

		for (auto node : lists)
		{
			while (node)
			{
				nums.push_back(node->val);
				node = node->next;
			}
		}

		if (nums.empty()) return nullptr;

		std::sort(nums.begin(), nums.end());

		ListNode* head = new ListNode(nums[0]);
		ListNode* copy = head;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			copy->next = new ListNode(nums[i + 1]);
			copy = copy->next;
		}

		return head;
	}
};

int main()
{
	Solution s;

	ListNode third  (5);
	ListNode second (4, &third);
	ListNode first  (1, &second);
	ListNode sixth  (4);
	ListNode fifth  (3, &sixth);
	ListNode fourth (1, &fifth);
	ListNode eighth (6);
	ListNode seventh(2, &eighth);

	std::vector vec = {&first, &fourth, &seventh};

	ListNode* head = s.mergeKLists(vec);
	ListNode* copy = head;
	
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;

	copy->freeListNode(copy);

	return 0;
}

//215. Kth Largest Element in an Array
//
//---------------------------------------------------------------
//https://leetcode.com/problems/kth-largest-element-in-an-array/
//---------------------------------------------------------------
//
//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Example 1:
//    Input: nums = [3, 2, 1, 5, 6, 4], k = 2
//    Output : 5
//
//Example 2 :
//    Input : nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
//    Output : 4
//
//Constraints :
//    1 <= k <= nums.length <= 10^4
//    - 10^4 <= nums[i] <= 10^4

#include <iostream>   
#include <vector>
#include <queue>

class Solution
{
public:
    int findKthLargest_1(std::vector<int>& nums, int k)     // 1-st version (02/21/2022 20:10) using sorting;
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
   
    int findKthLargest_2(std::vector<int>& nums, int k)     // 2-nd version(06/22/18:15) using Heap(priority_queue)
    {
        std::priority_queue<int> que;

        for (int i : nums)
            que.push(i);

        while (k > 1)
        {
            que.pop();
            k--;
        }

        return que.top();
    }
};


int main()
{
    Solution s;
    std::vector<int> vec{ 3,2,3,1,2,4,5,5,6 };

    std::cout << s.findKthLargest(vec, 4) << std::endl;
    return 0;
}

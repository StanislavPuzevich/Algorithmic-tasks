//215. Kth Largest Element in an Array
//
//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Example 1:
//Input: nums = [3, 2, 1, 5, 6, 4], k = 2
//Output : 5
//
//Example 2 :
//Input : nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
//Output : 4
//
//Constraints :
//    1 <= k <= nums.length <= 104
//    - 104 <= nums[i] <= 104

#include <iostream>   
#include <vector>
#include <algorithm>


class Solution
{
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};


int main()
{
    Solution s;
    std::vector<int> vec{ 3,2,3,1,2,4,5,5,6 };
    int k = 4;

    std::cout << s.findKthLargest(vec, k) << std::endl;

    return 0;
}
//896. Monotonic Array(Easy)
//
//-----------------------------------------------
//https://leetcode.com/problems/monotonic-array/
//----------------------------------------------- 
// 
//An array is monotonic if it is either monotone increasing or monotone decreasing.
//An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
//Given an integer array nums, return true if the given array is monotonic, or false otherwise.
//
//Example 1:
//    Input: nums = [1, 2, 2, 3]
//    Output : true
//
//Example 2 :
//    Input : nums = [6, 5, 4, 4]
//    Output : true
//
//Example 3 :
//    Input : nums = [1, 3, 2]
//    Output : false
//
//Constraints :
//    1 <= nums.length <= 10^5
//    - 10^5 <= nums[i] <= 10^5

#include <iostream>
#include <vector>

class Solution
{
public:
    bool isMonotonic_vers1(std::vector<int>& nums)
    {
        if (nums[0] < nums[nums.size() - 1])
        {
            for (int i = 1; i < nums.size(); ++i)
                if (nums[i - 1] > nums[i])
                    return false;
        }
        else
        {
            for (int i = 1; i < nums.size(); ++i)
                if (nums[i - 1] < nums[i])
                    return false;
        }

        return true;
    }

    bool isMonotonic_vers2(std::vector<int>& nums)
    {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
                decreasing = false;
            else if (nums[i] < nums[i - 1])
                increasing = false;

            if (!decreasing && !increasing)
                break;
        }

        return increasing || decreasing;
    }
};

int main()
{
    Solution s;
    std::vector vec = { 1,2,2,3 };

    std::cout << s.isMonotonic_vers1(vec) << std::endl;

    return 0;
}

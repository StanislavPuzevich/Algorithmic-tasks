//136. Single Number (Easy)
//
//---------------------------------------------------------- 
// https://leetcode.com/problems/single-number/description/ 
//---------------------------------------------------------- 
// 
//Given a non - empty array of integers nums, every element appears twice except for one.Find that single one.
//
//You must implement a solution with a linear runtime complexityand use only constant extra space.
//
//Example 1:
//Input: nums = [2, 2, 1]
//Output : 1
//
//Example 2 :
//    Input : nums = [4, 1, 2, 1, 2]
//    Output : 4
//    
//Example 3 :
//    Input : nums = [1]
//    Output : 1
//
//Constraints :
//    1 <= nums.length <= 3 * 104
//    - 3 * 104 <= nums[i] <= 3 * 104
//    Each element in the array appears twice except for one element which appears only once.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution 
{
public:
    // new O(1) solution right now
    int singleNumber_vers2(std::vector<int>& nums)
    {
        int temp = 0;

        for (auto i : nums) 
            temp ^= i;

        return temp;
    }

    // more than 1 year ago O(N*log(N) solution
    int singleNumber_vers1(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        if (nums.size() == 1)
            return nums[0];

        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (i == 1 && nums[0] != nums[i] && nums[0] != nums[i + 1])
                return nums[0];
            if (nums[nums.size() - 1] != nums[nums.size() - 2] && nums[nums.size() - 1] != nums[nums.size() - 3])
                return nums[nums.size() - 1];
            if (nums[i + 1] != nums[i] && nums[i] != nums[i - 1])
                return nums[i];
        }
        return 0;
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ 4,1,2,1,2 };

    std::cout << s.singleNumber_vers2(vec) << std::endl;

    return 0;
}

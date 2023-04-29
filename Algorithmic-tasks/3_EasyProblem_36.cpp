//1. Two Sum(Easy)
// 
//----------------------------------------
// https://leetcode.com/problems/two-sum/
//---------------------------------------- 
// 
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
//
//Example 1:
//Input: nums = [2, 7, 11, 15], target = 9
//Output : [0, 1]
//Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
//
//Example 2 :
//    Input : nums = [3, 2, 4], target = 6
//    Output : [1, 2]
//
//Example 3 :
//    Input : nums = [3, 3], target = 6
//    Output : [0, 1]
//
//Constraints :
//    2 <= nums.length <= 104
//    - 109 <= nums[i] <= 109
//    - 109 <= target <= 109
//    Only one valid answer exists.
//
//Follow - up: Can you come up with an algorithm that is less than O(n2) time complexity?

#include <iostream>
#include <vector>
#include <map>

class Solution 
{
public:
    std::vector<int> twoSum_vers1(std::vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return { i,j };

        return {};
    }

    std::vector<int> twoSum_vers2(std::vector<int>& nums, int target)
    {
        std::multimap<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp.insert(std::make_pair(nums[i], i));

        for (auto iter_first = mp.begin(); iter_first != mp.end(); iter_first++)
            for (auto iter_second = std::next(iter_first, 1); iter_second != mp.end(); iter_second++)
                if (iter_first->first + iter_second->first == target)
                    return { iter_first->second, iter_second->second };

        return {};
    }
};

int main()
{
    Solution s;

    std::vector nums{ 3,2,4 };
    std::vector<int> res = s.twoSum_vers1(nums, 6);

    for (auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;  
}

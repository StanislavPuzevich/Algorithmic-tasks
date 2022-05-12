//47. Permutations II
// 
//--------------------------------------------------------------------
//The link to the task: https://leetcode.com/problems/permutations-ii/
//--------------------------------------------------------------------
//
//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
//
//Example 1:
//    Input: nums = [1, 1, 2]
//    Output : [[1, 1, 2],[1, 2, 1],[2, 1, 1]]
//
//Example 2 :
//    Input : nums = [1, 2, 3]
//    Output : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
//
//Constraints :
//    1 <= nums.length <= 8
//    - 10 <= nums[i] <= 10

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<std::vector<int>>result;
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        work_function(nums, 0);
        return result;
    }

    void work_function(std::vector<int>& nums, int i)
    {
        if (i == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }
        std::unordered_set<int>ust;
        for (int j = i; j < nums.size(); j++)
        {
            if (ust.find(nums[j]) != ust.end()) continue;
            ust.insert(nums[j]);
            std::swap(nums[i], nums[j]);
            work_function(nums, i + 1);
            std::swap(nums[i], nums[j]);
        }
    }
};


int main()
{
    Solution s;
    std::vector<int> nums { 1,2,3 };
    std::vector<std::vector<int>> result = s.permuteUnique(nums);

    for (auto i : result)
    {
        for (auto j : i)
            std::cout << j << "  ";
        std::cout << std::endl;
    }

    return 0;
}
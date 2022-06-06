//78. Subsets
//
//---------------------------------------
//https://leetcode.com/problems/subsets/
//---------------------------------------
//
//Given an integer array nums of unique elements, return all possible subsets(the power set).
//The solution set must not contain duplicate subsets.Return the solution in any order.
//
//Example 1:
//    Input: nums = [1, 2, 3]
//    Output : [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//
//Example 2 :
//    Input : nums = [0]
//    Output : [[], [0]]
//
//Ñonstraints :
//    1 <= nums.length <= 10
//    - 10 <= nums[i] <= 10
//    All the numbers of nums are unique.

#include <iostream>
#include <vector>


class Solution1   // 0-3 ms
{
public:
    std::vector<std::vector<int>> result; 

    std::vector<std::vector<int>> subsets_1(std::vector<int>& nums)
    {
        result.push_back({});
        for (int i = 0; i < nums.size(); i++)
        {
            std::vector<int> temp;
            solve_func_1(nums, temp, i);
        }

        return result;
    }

    void solve_func_1(std::vector<int>& nums, std::vector<int> temp, int index)
    {
        if (index >= nums.size()) return;

        temp.push_back(nums[index]);
        int i = 1;
        while (index + i < nums.size())
        {
            solve_func_1(nums, temp, index + i);
            i++;
        }
        result.push_back(temp);
    }
};

class Solution2   // 3+ ms
{
public:
    std::vector<std::vector<int>> subsets2(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;

        solve_func_2(result, nums, temp, 0);

        return result;
    }

    void solve_func_2(std::vector<std::vector<int>>& result, std::vector<int>& nums, std::vector<int> temp, int index)
    {
        if (index == nums.size())
        {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve_func_2(result, nums, temp, index + 1);
        temp.pop_back();
        solve_func_2(result, nums, temp, index + 1);
    }
};

int main()
{
    Solution1 s;
    std::vector<int> nums { 1,2,3 };
    std::vector<std::vector<int>> result;

    result = s.subsets_1(nums);

    for (std::vector<int> i : result)
    {
        for (int j : i)
            std::cout << j << "  ";
        std::cout << std::endl;
    }

    return 0;
}
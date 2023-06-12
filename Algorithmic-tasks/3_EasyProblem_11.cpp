//228. Summary Ranges(Easy)
//
//----------------------------------------------- 
// https://leetcode.com/problems/summary-ranges/
//----------------------------------------------- 
// 
//You are given a sorted unique integer array nums.
//A range[a, b] is the set of all integers from a to b(inclusive).
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly.That is, each element of nums is covered by exactly one of the ranges, 
//and there is no integer x such that x is in one of the ranges but not in nums.
//Each range[a, b] in the list should be output as :
//    "a->b" if a != b
//    "a" if a == b
//
//Example 1:
//    Input: nums = [0, 1, 2, 4, 5, 7]
//    Output : ["0->2", "4->5", "7"]
//    Explanation : The ranges are :
//    [0, 2] -- > "0->2"
//    [4, 5] -- > "4->5"
//    [7, 7] -- > "7"
//
//Example 2:
//    Input: nums = [0, 2, 3, 4, 6, 8, 9]
//    Output : ["0", "2->4", "6", "8->9"]
//    Explanation : The ranges are :
//    [0, 0] -- > "0"
//    [2, 4] -- > "2->4"
//    [6, 6] -- > "6"
//    [8, 9] -- > "8->9"
//
//Constraints:
//    0 <= nums.length <= 20
//    -2^31 <= nums[i] <= 2^(31-1)
//    All the values of nums are unique.
//    nums is sorted in ascending order.

#include <iostream>   
#include <string>
#include <vector>


class Solution
{
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
        if (nums.empty()) return {};

        std::vector<std::string> result;
        bool check;

        for (int i = 0, j = 1; j <= nums.size(); j++)
        {
            check = false;
            while (j < nums.size() && nums[j - 1] + 1 == nums[j])
            {
                ++j;
                check = true;
            }

            if (check)
                result.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[j - 1]));
            else if (j == nums.size())
                result.push_back(std::to_string(nums[j - 1]));
            else
                result.push_back(std::to_string(nums[i]));

            i = j;
        }
        return result;
    }
    
    std::vector<std::string> summaryRanges_2(std::vector<int>&nums)
    {
        if (nums.empty()) return {};

        std::vector<std::string> answ;
        int low = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 1) continue;

            if (nums[i - 1] == low)
                answ.push_back(std::to_string(low));
            else
                answ.push_back(std::to_string(low) + "->" + std::to_string(nums[i-1]));

            low = nums[i];
        }

        if(low != nums[nums.size() - 1])
            answ.push_back(std::to_string(low) + "->" + std::to_string(nums[nums.size() - 1]));
        else 
            answ.push_back(std::to_string(low));

        return answ;
    }
};


int main()
{
    Solution s;
    std::vector nums = { 0,2,3,4,6,8,9 };
    std::vector<std::string> res = s.summaryRanges_2(nums);

    for (const auto& i : res)
        std::cout << i << std::endl;

    return 0;
}

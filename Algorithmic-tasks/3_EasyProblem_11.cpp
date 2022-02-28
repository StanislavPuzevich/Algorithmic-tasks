//228. Summary Ranges
//You are given a sorted unique integer array nums.
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly.That is, each element of nums is covered by exactly 
//one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//Each range[a, b] in the list should be output as :
//
//"a->b" if a != b
//"a" if a == b
//
//Example 1:
//Input: nums = [0, 1, 2, 4, 5, 7]
//Output : ["0->2", "4->5", "7"]
//Explanation : The ranges are :
//[0, 2] -- > "0->2"
//[4, 5] -- > "4->5"
//[7, 7] -- > "7"
//
//Constraints:
//0 <= nums.length <= 20
//- 231 <= nums[i] <= 231 - 1
//All the values of nums are unique.
//nums is sorted in ascending order.

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
};


int main()
{
    Solution s;
    std::vector<int> nums{ 0,1,2,4,5,7 };
    std::vector<std::string> result = s.summaryRanges(nums);

    for (auto i : result)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
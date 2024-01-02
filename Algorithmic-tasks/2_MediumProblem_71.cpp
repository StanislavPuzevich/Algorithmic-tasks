//2610. Convert an Array Into a 2D Array With Conditions(Medium)
//
//--------------------------------------------------------------------------------- 
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
//--------------------------------------------------------------------------------- 
// 
//You are given an integer array nums.You need to create a 2D array from nums satisfying the following conditions :
//
//The 2D array should contain only the elements of the array nums.
//Each row in the 2D array contains distinct integers.
//The number of rows in the 2D array should be minimal.
//Return the resulting array.If there are multiple answers, return any of them.
//
//Note that the 2D array can have a different number of elements on each row.
//
//Example 1:
//    Input: nums = [1, 3, 4, 1, 2, 3, 1]
//    Output : [[1, 3, 4, 2], [1, 3], [1]]
//    Explanation : We can create a 2D array that contains the following rows :
//    -1, 3, 4, 2
//    - 1, 3
//    - 1
//    All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
//    It can be shown that we cannot have less than 3 rows in a valid array.
//
//Example 2:
//    Input: nums = [1, 2, 3, 4]
//    Output : [[4, 3, 2, 1]]
//    Explanation : All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
//
//Constraints :
//    1 <= nums.length <= 200
//    1 <= nums[i] <= nums.length

#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> answ;
        int currentLine = 0;

        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (answ.size() > currentLine)
                answ[currentLine].push_back(nums[i - 1]);
            else
                answ.push_back({ nums[i - 1] });

            if (nums[i] == nums[i - 1])
                currentLine++;
            else
                currentLine = 0;
        }

        if (answ.size() > currentLine)
            answ[currentLine].push_back(nums.back());
        else
            answ.push_back({ nums.back() });

        return answ;
    }

    std::vector<std::vector<int>> findMatrix_vers2(std::vector<int>& nums)  //Solution after discussion on the LeetCode forum
    {
        std::vector<std::vector<int>> answ;
        std::unordered_map<int, int> ump;

        for (const auto i : nums)
            ump[i]++;

        while (!ump.empty())
        {
            std::vector<int> temp;
            for (auto it = ump.begin(); it != ump.end();)
            {
                temp.push_back(it->first);
                it->second--;
                if (it->second == 0)
                    ump.erase(it);
                else
                    it++;
            }

            answ.push_back(temp);
        }

        return answ;
    }
};

int main()
{
    Solution s;

    std::vector<int> nums = { 1,3,4,1,2,3,1 };
    std::vector<std::vector<int>> result = s.findMatrix(nums);

    for (const auto& line : result)
    {
        for (const auto i : line)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}

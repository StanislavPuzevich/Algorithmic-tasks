//442. Find All Duplicates in an Array(Medium)
//
//---------------------------------------------------------------- 
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
//---------------------------------------------------------------- 
// 
//Given an integer array nums of length n where all the integers of nums are in the range[1, n] and each integer appears once or twice, 
//return an array of all the integers that appears twice.
//
//You must write an algorithm that runs in O(n) time and uses only constant extra space.
//
//Example 1:
//    Input: nums = [4, 3, 2, 7, 8, 2, 3, 1]
//    Output : [2, 3]
//
//Example 2 :
//    Input : nums = [1, 1, 2]
//    Output : [1]
//
//Example 3 :
//    Input : nums = [1]
//    Output : []
//
//Constraints :
//    n == nums.length
//    1 <= n <= 10^5
//    1 <= nums[i] <= n
//    Each element in nums appears once or twice.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution 
{
public:
    //using hash
    std::vector<int> findDuplicates_vers1(std::vector<int>& nums)
    {
        std::vector<int> answ;
        std::unordered_map<int, int> hash;

        for (const auto i : nums)
            hash[i]++;

        for (const auto it : hash)
            if (it.second == 2)
                answ.push_back(it.first);

        return answ;
    }

    //using sorting
    std::vector<int> findDuplicates_vers2(std::vector<int>& nums)
    {
        std::vector<int> answ;

        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                answ.push_back(nums[i]);

        return answ;
    }

    //using logic
    std::vector<int> findDuplicates_vers3(std::vector<int>& nums)
    {
        std::vector<int> answ;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[abs(nums[i]) - 1] *= -1;
            if (nums[abs(nums[i]) - 1] > 0)
                answ.push_back(abs(nums[i]));
        }

        return answ;
    }
};

int main()
{
    Solution s;
    std::vector<int> result;
    std::vector<int> nums = { 4,3,2,7,8,2,3,1 };

    result = s.findDuplicates_vers3(nums);

    for (auto i : result)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

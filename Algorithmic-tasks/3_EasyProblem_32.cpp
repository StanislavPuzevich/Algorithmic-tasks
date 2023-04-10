//268. Missing Number (Easy)
//
//----------------------------------------------------------- 
// https://leetcode.com/problems/missing-number/description/ 
//----------------------------------------------------------- 
// 
//Given an array nums containing n distinct numbers in the range[0, n], return the only number in the range that is missing from the array.
//
//Example 1:
//    Input: nums = [3, 0, 1]
//    Output : 2
//    Explanation : n = 3 since there are 3 numbers, so all numbers are in the range[0, 3]. 2 is the missing number in the range since
//    it does not appear in nums.
//
//Example 2 :
//    Input : nums = [0, 1]
//    Output : 2
//    Explanation : n = 2 since there are 2 numbers, so all numbers are in the range[0, 2]. 2 is the missing number in the range since 
//    it does not appear in nums.
//
//Example 3 :
//    Input : nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
//    Output : 8
//    Explanation : n = 9 since there are 9 numbers, so all numbers are in the range[0, 9]. 8 is the missing number in the range since
//    it does not appear in nums.
//
//Constraints :
//    n == nums.length
//    1 <= n <= 104
//    0 <= nums[i] <= n
//    All the numbers of nums are unique.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution
{
public:
    int missingNumber_vers1(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        for (int i = 0, j = 1; j < nums.size(); i++, j++)
            if (nums[j] - nums[i] > 1)
                return nums[j] - 1;

        return nums[0] == 0 ? nums[nums.size() - 1] + 1 : 0;
    }

    int missingNumber_vers2(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size())
        {
            if ((nums[i] ^ i) != 0)
                return i;
            i++;
        }

        return i;
    }

    int missingNumber_vers3(std::vector<int>& nums) //  O(N)       Runtime: 21ms Beats 58.78% | Memory: 17.8MB Beats94.74%
    {
        return nums.size() * (nums.size() + 1) / 2 - std::reduce(nums.begin(), nums.end());
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ 9,6,4,2,3,5,7,0,1 };

    std::cout << "Answer: " << s.missingNumber_vers3(vec) << std::endl;

    return 0;
}

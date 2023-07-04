//260. Single Number III(Medium)
//
//-------------------------------------------------- 
// https://leetcode.com/problems/single-number-iii/
//-------------------------------------------------- 
// 
//Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//Find the two elements that appear only once.You can return the answer in any order.
//
//You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
//
//Example 1:
//    Input: nums = [1, 2, 1, 3, 2, 5]
//    Output : [3, 5]
//    Explanation : [5, 3] is also a valid answer.
//
//Example 2 :
//    Input : nums = [-1, 0]
//    Output : [-1, 0]
//
//Example 3 :
//    Input : nums = [0, 1]
//    Output : [1, 0]
//
//Constraints :
//    2 <= nums.length <= 3 * 10^4
//    - 2^31 <= nums[i] <= 2^31 - 1
//    Each integer in nums will appear twice, only two integers will appear once.

#include <iostream>
#include <vector>

class Solution 
{
public:
    // The 1-st solution
    // With EXTRA SPACE
    std::vector<int> singleNumber_vers1(std::vector<int>& nums)
    {
        int temp = 0;
        for (const auto i : nums)
            temp ^= i;

        std::vector<int> first;
        std::vector<int> second;
        long long index = 1;
        while ((temp & 1) != 1)
        {
            temp >>= 1;
            index *= 2;
        }

        for (const auto i : nums)
            i & index ? first.push_back(i) : second.push_back(i);

        int firstNumb = 0;
        for (const auto i : first)
            firstNumb ^= i;

        int secondNumb = 0;
        for (const auto i : second)
            secondNumb ^= i;

        return { firstNumb , secondNumb };
    }

    // The 2-nd solution
    // Without EXTRA SPACE and faster than the 1-st solution
    std::vector<int> singleNumber_vers2(std::vector<int>& nums)
    {
        int tempXOR = 0;
        for (const auto i : nums)
            tempXOR ^= i;

        // We are looking for a bit equal to 1. It means that our two numbers are different in this place
        long long index = 1;
        while ((tempXOR & 1) != 1)
        {
            tempXOR >>= 1;
            index *= 2;
        }

        // We can divide numbers of vector into two groups, in the first of which the i-th bit is 1, and in the second the i-th bit is 0
        // and calculate XOR for each group
        int firstNumb = 0;
        int secondNumb = 0;
        for (const auto i : nums)
            i & index ? firstNumb ^= i : secondNumb ^= i;

        return { firstNumb , secondNumb };
    }
};

int main()
{
    Solution s;

    std::vector<int> vect = { 1,2,1,3,2,5 };
    std::vector<int> result = s.singleNumber_vers2(vect);

    std::cout << result[0] << " " << result[1] << std::endl;

    return 0;
}

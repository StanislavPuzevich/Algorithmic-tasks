//1493. Longest Subarray of 1's After Deleting One Element(Medium)
//
//---------------------------------------------------------------------------------- 
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//---------------------------------------------------------------------------------- 
// 
//Given a binary array nums, you should delete one element from it.
//Return the size of the longest non - empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
//
//Example 1:
//    Input: nums = [1, 1, 0, 1]
//    Output : 3
//    Explanation : After deleting the number in position 2, [1, 1, 1] contains 3 numbers with value of 1's.
//
//Example 2 :
//    Input : nums = [0, 1, 1, 1, 0, 1, 1, 0, 1]
//    Output : 5
//    Explanation : After deleting the number in position 4, [0, 1, 1, 1, 1, 1, 0, 1] longest subarray with value of 1's is [1,1,1,1,1].
//
//    Example 3 :
//    Input : nums = [1, 1, 1]
//    Output : 2
//    Explanation : You must delete one element.
//
//Constraints :
//    1 <= nums.length <= 10^5
//    nums[i] is either 0 or 1.

#include <iostream>
#include <vector>

class Solution 
{
public:
    // Both solution are fast, however the second one is more readable
    int longestSubarray_vers1(std::vector<int>& nums) 
    {
        int answ = 0;
        int next = 0;
        int start = 0;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroCount++;

                if (zeroCount == 2)
                {
                    zeroCount = 0;
                    answ = std::max(answ, i - start - 1);
                    start = next + 1;
                    i = next;
                    continue;
                }

                next = i;
            }
        }

        if (zeroCount == 1 || zeroCount == 0)
            answ = std::max(answ, static_cast<int>(nums.size()) - 1 - start);

        return answ;
    }

    // The version after discussing on the LeetCode forum
    int longestSubarray_vers2(std::vector<int>& nums)
    {
        int answ = 0;
        int left = 0;
        int right = 0;
        int zeroCount = 0;

        while (right < nums.size())
        {
            if (nums[right] == 0)
                zeroCount++;

            if (zeroCount > 1)
            {
                while (nums[left++]) {}
                zeroCount--;
            }
            answ = std::max(answ, right - left);
            right++;
        }

        return answ;
    }
};

int main()
{
    Solution s;
    std::vector<int> vect = { 0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1 };

    std::cout << s.longestSubarray_vers1(vect) << std::endl;

    return 0;
}

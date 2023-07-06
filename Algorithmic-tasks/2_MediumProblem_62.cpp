//209. Minimum Size Subarray Sum(Medium)
//
//----------------------------------------------------------
// https://leetcode.com/problems/minimum-size-subarray-sum/
//----------------------------------------------------------
//
//Given an array of positive integers nums and a positive integer target, return the minimal length of a
//subarray
//whose sum is greater than or equal to target.If there is no such subarray, return 0 instead.
//
//Example 1:
//    Input: target = 7, nums = [2, 3, 1, 2, 4, 3]
//    Output : 2
//    Explanation : The subarray[4, 3] has the minimal length under the problem constraint.
//
//Example 2 :
//    Input : target = 4, nums = [1, 4, 4]
//    Output : 1
//
//Example 3 :
//    Input : target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
//    Output : 0
//
//Constraints :
//    1 <= target <= 10^9
//    1 <= nums.length <= 10^5
//    1 <= nums[i] <= 10^4

#include <iostream>
#include <vector>

class Solution 
{
public:
    int minSubArrayLen(int target, std::vector<int>& nums) 
    {
        int minLenght = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size())
        {
            sum += nums[right];

            while (sum >= target)
            { 
                minLenght = std::min(minLenght, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return minLenght == INT_MAX ? 0 : minLenght;
    }
};

int main()
{
    Solution s;
    std::vector<int> vect = { 2,3,1,2,4,3 };

    std::cout << s.minSubArrayLen(7, vect) << std::endl;

    return 0;
}

//53. Maximum Subarray (Medium)
//
//-------------------------------------------------------------
// https://leetcode.com/problems/maximum-subarray/description/ 
//------------------------------------------------------------- 
// 
//Given an integer array nums, find thesubarray with the largest sum, and return its sum.
//
//Example 1:
//    Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//    Output : 6
//    Explanation : The subarray[4, -1, 2, 1] has the largest sum 6.
//
//Example 2 :
//
//    Input : nums = [1]
//    Output : 1
//    Explanation : The subarray[1] has the largest sum 1.
//   
//Example 3 :
//    Input : nums = [5, 4, -1, 7, 8]
//    Output : 23
//    Explanation : The subarray[5, 4, -1, 7, 8] has the largest sum 23.
//
//Constraints :
//    1 <= nums.length <= 10^5
//    - 10^4 <= nums[i] <= 10^4
//
//Follow up : If you have figured out the O(n) solution, try coding another solution using the divideand conquer approach, which is more subtle.

#include <iostream>
#include <vector>

class Solution 
{
public:
    // This function works correctly but for a long input vector we have "Time Limit Exceeded"
    int maxSubArray_ver1(std::vector<int>&nums)
    {
        int max = nums[0];

        for (int i = 0, j = i + 1; j < nums.size(); i++, j++)
        {
            int temp = nums[i];
            if (nums[j] > nums[i] && nums[i] < 0 && max < nums[j])
            {
                max = nums[j];
            }
            else
            {
                for (int k = j; k < nums.size(); k++)
                {
                    temp += nums[k];
                    if (temp > max) max = temp;
                }
                if (temp > max) max = temp;
            }
        }

        return max;
    }

    // The solution after reviewing the issue on the forum
    int maxSubArray_vers2(std::vector<int>& nums)
    {
        int max_sum = nums[0];
        int current_sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        { 
            current_sum = std::max(current_sum + nums[i], nums[i]);
            max_sum = std::max(current_sum, max_sum);
        }
        
        return max_sum;
    }
};

int main()
{
    Solution s;

    std::vector<int> vec{ -2,1,-3,4,-1,2,1,-5,4 };
    std::cout << s.maxSubArray_vers2(vec) << std::endl;

    return 0;
}

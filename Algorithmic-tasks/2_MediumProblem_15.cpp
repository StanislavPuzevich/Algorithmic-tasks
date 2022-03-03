//413. Arithmetic Slices
//
//An integer array is called arithmetic if it consists of at least three elementsand if the difference between 
//any two consecutive elements is the same.
//
//For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
//Given an integer array nums, return the number of arithmetic subarrays of nums.
//A subarray is a contiguous subsequence of the array.
//
//Example 1:
//Input: nums = [1, 2, 3, 4]
//Output : 3
//Explanation : We have 3 arithmetic slices in nums : [1, 2, 3] , [2, 3, 4] and [1, 2, 3, 4] itself.
//
//Constraints :
//    1 <= nums.length <= 5000
//    - 1000 <= nums[i] <= 1000

#include <iostream>
#include <vector>


class Solution 
{
public:
    int numberOfArithmeticSlices(std::vector<int>& nums)
    {
        if (nums.size() < 3) return 0;
        int size = 0, count = 0, i = 2;

        while (i < nums.size())
        {
            while (i < nums.size() && (nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2]))
            {
                size++;
                i++;
            }
            if (size)
                while (size > 0)
                    count += size--;
            i++;
        }
        return count;
    }
};


int main()
{   
    Solution s;
    std::vector<int> nums{ 1,2,3,4,5,6,7,12,15,18,33 };
    
    std::cout << "Result: " << s.numberOfArithmeticSlices(nums) << std::endl;

    return 0;
}

//303. Range Sum Query - Immutable(Easy)
//
//---------------------------------------------------------- 
// https://leetcode.com/problems/range-sum-query-immutable/
//---------------------------------------------------------- 
// 
//Given an integer array nums, handle multiple queries of the following type :
//
//Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
//Implement the NumArray class :
//
//    NumArray(int[] nums) Initializes the object with the integer array nums.
//    int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive(i.e.nums[left] + nums[left + 1] + ... + nums[right]).
//
//Example 1:
//    Input
//    ["NumArray", "sumRange", "sumRange", "sumRange"]
//    [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
//    Output
//    [null, 1, -1, -3]
//    
//    Explanation
//    NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
//    numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
//    numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
//    numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
//
//Constraints:
//    1 <= nums.length <= 10^4
//    - 10^5 <= nums[i] <= 10^5
//    0 <= left <= right < nums.length
//    At most 10^4 calls will be made to sumRange.

#include <iostream>
#include <vector>

// Prefix Sum solution
class NumArray 
{
    std::vector<int> arr;

public:
    NumArray(std::vector<int>& nums) : arr(nums)
    {
        for (int i = 1; i < arr.size(); ++i)
            arr[i] += arr[i - 1];
    }

    int sumRange(int left, int right) 
    {
        return left == 0 ? arr[right] : arr[right] - arr[left - 1];
    }
};

// Brute force solution
class NumArray_vers1
{
    std::vector<int> arr;

public:
    NumArray_vers1(std::vector<int>& nums) : arr(nums)
    { 

    }

    int sumRange(int left, int right)
    {
        int sum = arr[left];

        for (int i = left + 1; i <= right; ++i)
            sum += arr[i];

        return sum;
    }
};

int main()
{
    std::vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray na(nums);

    std::cout << na.sumRange(0, 2) << std::endl;
    std::cout << na.sumRange(2, 5) << std::endl;
    std::cout << na.sumRange(0, 5) << std::endl;

    return 0;
}

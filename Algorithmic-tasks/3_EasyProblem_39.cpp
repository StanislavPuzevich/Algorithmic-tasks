//1822. Sign of the Product of an Array(Easy)
//
//---------------------------------------------------------------------------- 
// https://leetcode.com/problems/sign-of-the-product-of-an-array/description/ 
//---------------------------------------------------------------------------- 
// 
//There is a function signFunc(x) that returns :
//    1 if x is positive.
//  - 1 if x is negative.
//    0 if x is equal to 0.
//You are given an integer array nums.Let product be the product of all values in the array nums.
//Return signFunc(product).
//
//Example 1:
//    Input: nums = [-1, -2, -3, -4, 3, 2, 1]
//    Output : 1
//    Explanation : The product of all values in the array is 144, and signFunc(144) = 1
//
//Example 2 :
//    Input : nums = [1, 5, 0, 2, -3]
//    Output : 0
//    Explanation : The product of all values in the array is 0, and signFunc(0) = 0
//
//Example 3 :
//    Input : nums = [-1, 1, -1, 1, -1]
//    Output : -1
//    Explanation : The product of all values in the array is - 1, and signFunc(-1) = -1
//
//Constraints :
//    1 <= nums.length <= 1000
//    - 100 <= nums[i] <= 100

#include <iostream>
#include <vector>

class Solution
{
public:
    // Fastest
    int arraySign_ver1(std::vector<int>& nums) 
    {
        int counter_negative = 0;

        for (auto i : nums)
        {
            if (i == 0) return 0;
            if (i < 0) counter_negative++;
        }

        return counter_negative % 2 == 0 ? 1 : -1;
    }

    int arraySign_ver2(std::vector<int>& nums)
    {
        double sum = 1;

        for (auto i : nums)
            sum *= i;

        if (sum > 0) return 1;
        if (sum < 0) return -1;

        return 0;
    }
};

int main()
{
    Solution s;

    std::vector vec{ -1,-2,-3,-4,3,2,1 };

    std::cout << s.arraySign_ver1(vec) << std::endl;

    return 0;  
}

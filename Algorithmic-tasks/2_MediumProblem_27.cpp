//6. 3Sum Closest
//Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
//Return the sum of the three integers.
//You may assume that each input would have exactly one solution.
//
//Example 1:
//  Input: nums = [-1, 2, 1, -4], target = 1
//  Output : 2
//  Explanation : The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//Example 2 :
//    Input : nums = [0, 0, 0], target = 1
//    Output : 0
//
//Constraints :
//    3 <= nums.length <= 1000
//    - 1000 <= nums[i] <= 1000
//    - 10^4 <= target <= 10^4

#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX_SIZE = 100000;

class Solution 
{
public:
    //O^n3
    int threeSumClosest_1(std::vector<int>& nums, int target) 
    {
        int min = MAX_SIZE, result = 0;
        int size = nums.size();
        for (int i = 0; i < size - 2; i++)
            for (int j = i + 1; j < size - 1; j++)
                for (int k = j + 1; k < size; k++)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == target)
                        return sum;
                    comparison(target, sum, min, result);
                }
        return result;
    }

    //O^n2
    int threeSumClosest_2(std::vector<int>& nums, int target)
    {
        int min = MAX_SIZE, result = 0;
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = size - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;
                else if (sum < target)
                {
                    comparison(target, sum, min, result);
                    j++;
                }
                else
                {
                    comparison(target, sum, min, result);
                    k--;
                }
            }
        }
        return result;
    }

    void comparison(int target, int sum, int& min, int& result)
    {
        if (abs(sum - target) < min)
        {
            min = abs(sum - target);
            result = sum;
        }
    }
};

int main()
{
    Solution s;
    std::vector input { -1,2,1,-4 };    // initializing a vector from C++17
    
    std::cout << s.threeSumClosest_2(input, 1) << std::endl;

    return 0;
}

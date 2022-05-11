//18. 4Sum
// 
//----------------------------------------------------------
//The link to the task: https://leetcode.com/problems/4sum/
//----------------------------------------------------------
// 
//Given an array nums of n integers, return an array of all the unique quadruplets[nums[a], nums[b], nums[c], nums[d]] such that :
//    0 <= a, b, c, d < n
//    a, b, c, and d are distinct.
//    nums[a] + nums[b] + nums[c] + nums[d] == target
//You may return the answer in any order.
//
//Example 1:
//    Input: nums = [1, 0, -1, 0, -2, 2], target = 0
//    Output : [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
//
//Example 2 :
//    Input : nums = [2, 2, 2, 2, 2], target = 8
//    Output : [[2, 2, 2, 2]]
//
//Constraints :
//    1 <= nums.length <= 200
//    - 10^9 <= nums[i] <= 10^9
//    - 10^9 <= target <= 10^9

#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> result;
        int size = nums.size();
        if (size < 4) return result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 3 && nums[i] <= target / 4; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < size - 2; j++)
            {
                if ( j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int n = size - 1;

                while (k < n)
                {
                    // long long type and "1ll*" coverage "runtime error: signed integer overflow: 2000000000 + 1000000000 cannot be represented in type 'int' (solution.cpp)"
                    // we can also use type casting ex.(long long)nums[i];
                    long long sum = 1ll * nums[i] + 1ll * nums[j] + 1ll * nums[k] + 1ll * nums[n];

                    if (sum == target)
                    {
                        result.push_back({ nums[i], nums[j], nums[k], nums[n] });

                        while (k < n && nums[n] == nums[n - 1]) n--;
                        while (k < n && nums[k] == nums[k + 1]) k++;

                        k++;
                        n--;
                    }
                    else if (sum < target) k++;
                    else n--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums { -3,-2,-1,0,0,1,2,3};
    std::vector<std::vector<int>> result = s.fourSum(nums, 0);

    for (auto i : result)
    {
        for (auto j : i)
            std::cout << j << "  ";
        std::cout << std::endl;
    }

    return 0;
}
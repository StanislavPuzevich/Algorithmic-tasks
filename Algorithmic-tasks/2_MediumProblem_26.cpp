//15. 3Sum
//Given an integer array nums, 
//return all the triplets[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//Notice that the solution set must not contain duplicate triplets.
//
//Example 1:
//Input: nums = [-1, 0, 1, 2, -1, -4]
//Output : [[-1, -1, 2], [-1, 0, 1]]
//
//Example 3:
//Input: nums = [0]
//Output : []
//
//Constraints :
//    0 <= nums.length <= 3000
//    - 105 <= nums[i] <= 105

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:

    // each subsequent solution is faster than the previous one

    // O^n3
    std::vector<std::vector<int>> threeSum_1(std::vector<int>& nums)
    {
        std::vector<std::vector<int>>result;
        int size = nums.size();
        for (int i = 0; i < size - 2; i++)
            for (int j = i + 1; j < size - 1; j++)
                for (int k = j + 1; k < size; k++)
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        std::vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        std::sort(temp.begin(), temp.end());
                        if (std::find(result.begin(), result.end(), temp) == result.end())
                            result.push_back(temp);
                    }
        return result;
    }

    // O^n3
    std::vector<std::vector<int>> threeSum_2(std::vector<int>& nums)
    {
        std::vector<std::vector<int>>result;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2 && nums[i] <= 0; i++)
            for (int j = i + 1; j < size - 1; j++)
                for (int k = size - 1; k > 0 && nums[k] >= 0; k--)
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        std::vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        std::sort(temp.begin(), temp.end());
                        if (std::find(result.begin(), result.end(), temp) == result.end())
                            result.push_back(temp);
                    }
        return result;
    }

    // O^n3
    std::vector<std::vector<int>> threeSum_3(std::vector<int>& nums)
    {
        std::vector<std::vector<int>>result;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2 && nums[i] <= 0; i++)
            for (int j = i + 1; j < size - 1; j++)
                for (int k = size - 1; k > j && nums[k] >= 0; k--)
                {
                    while (j + 1 < k && nums[i] + nums[j] + nums[k] < 0)
                        j++;

                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        std::vector<int>temp = { nums[i] ,nums[j] ,nums[k] };
                        std::sort(temp.begin(), temp.end());
                        if (std::find(result.begin(), result.end(), temp) == result.end())
                            result.push_back(temp);
                    }
                }
        return result;
    }

    // O^n3
    std::vector<std::vector<int>> threeSum_4(std::vector<int>& nums)
    {
        std::vector<std::vector<int>>result;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2 && nums[i] <= 0; i++)
        {
            int j = i + 1;
            int k = size - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    std::vector<int>temp = { nums[i] ,nums[j] ,nums[k] };
                    if (std::find(result.begin(), result.end(), temp) == result.end())
                        result.push_back(temp);
                    k--;
                }
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }

    // O^n2
    std::vector<std::vector<int>> threeSum_5(std::vector<int>& nums)
    {
        std::vector<std::vector<int>>result;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2 && nums[i] <= 0; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = size - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    result.push_back({ nums[i] ,nums[j] ,nums[k] });

                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    while (j < k && nums[j] == nums[j + 1])
                        j++;

                    k--;
                    j++;
                }
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector input { -1,0,1,2,-1,-4 };    // initializing a vector from C++20
    std::vector<std::vector<int>>result = s.threeSum_4(input);
    for (auto i : result)
    {
        for (auto j : i)
            std::cout << j << "\t";
        std::cout << std::endl;
    }

    return 0;
}
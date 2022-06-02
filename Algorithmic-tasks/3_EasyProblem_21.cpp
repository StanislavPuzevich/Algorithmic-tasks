//1480. Running Sum of 1d Array
//
//-------------------------------------------------------- 
// https://leetcode.com/problems/running-sum-of-1d-array/
//-------------------------------------------------------- 
// 
//Given an array nums.We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
//Return the running sum of nums.
//
//Example 1:
//    Input: nums = [1, 2, 3, 4]
//    Output : [1, 3, 6, 10]
//    Explanation : Running sum is obtained as follows : [1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4] .
//
//Example 2 :
//    Input : nums = [1, 1, 1, 1, 1]
//    Output : [1, 2, 3, 4, 5]
//    Explanation : Running sum is obtained as follows : [1, 1 + 1, 1 + 1 + 1, 1 + 1 + 1 + 1, 1 + 1 + 1 + 1 + 1] .
//        
//Example 3 :
//    Input : nums = [3, 1, 2, 10, 1]
//    Output : [3, 4, 6, 16, 17]
//
//Constraints :
//    1 <= nums.length <= 1000
//    - 10 ^ 6 <= nums[i] <= 10 ^ 6

#include <iostream>
#include <vector>


class Solution
{
public:
    std::vector<int> runningSum_1(std::vector<int>& nums)
    {
        std::vector<int> result;
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
            result.push_back(sum);
        }
        return result;
    }

    void runningSum_2(std::vector<int>& nums)
    {
        if (nums.size() < 2) return;

        for (int i = 0, j = 1; j < nums.size(); i++, j++)
            nums[j] += nums[i];
    }

    void runningSum_3(std::vector<int>& nums)
    {
        if (nums.size() < 2) return;

        auto it1 = nums.begin();
        auto it2 = nums.begin() + 1;

        while (it2 != nums.end())
        {
            *it2 += *it1;
            it2++;
            it1++;
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> vec { 3,1,2,10,1 };

    s.runningSum_3(vec);        //or vec = s.runningSum_1(vec);
    for (int i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
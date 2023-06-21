//2448. Minimum Cost to Make Array Equal(Hard)
//
//----------------------------------------------------------------------------- 
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/
//----------------------------------------------------------------------------- 
// 
//You are given two 0 - indexed arrays nums and cost consisting each of n positive integers.
//You can do the following operation any number of times :
//Increase or decrease any element of the array nums by 1.
//The cost of doing one operation on the i^th element is cost[i].
//Return the minimum total cost such that all the elements of the array nums become equal.
//
//Example 1:
//    Input: nums = [1, 3, 5, 2], cost = [2, 3, 1, 14]
//    Output : 8
//    Explanation : We can make all the elements equal to 2 in the following way :
//        -Increase the 0th element one time.The cost is 2.
//        - Decrease the 1st element one time.The cost is 3.
//        - Decrease the 2nd element three times.The cost is 1 + 1 + 1 = 3.
//        The total cost is 2 + 3 + 3 = 8.
//        It can be shown that we cannot make the array equal with a smaller cost.
//
//Example 2:
//    Input: nums = [2, 2, 2, 2, 2], cost = [4, 2, 8, 1, 3]
//    Output : 0
//    Explanation : All the elements are already equal, so no operations are needed.
//
//Constraints :
//    n == nums.length == cost.length
//    1 <= n <= 10^5
//    1 <= nums[i], cost[i] <= 10^6

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // brute force Solution (40/48 testcases passed, the "Time Limit Exceeded" error)
    long long minCost_vers1(std::vector<int>& nums, std::vector<int>& cost)
    {
        std::vector<std::pair<int, int>> vect;

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] < nums[i])
                    sum += (nums[i] - nums[j]) * cost[j];
                else if (nums[j] > nums[i])
                    sum += (nums[j] - nums[i]) * cost[j];
            }

            vect.push_back({ sum,nums[i] });
        }

        return std::min_element(vect.begin(), vect.end())->first;
    }

    // binary searching
    long long minCost_vers2(std::vector<int>& nums, std::vector<int>& cost)
    {
        auto findCost = [&](long long val)
        {
            long long sum = 0;

            for (int i = 0; i < nums.size(); i++)
                sum += abs(nums[i] - val) * cost[i];

            return sum;
        };

        long long answ = 0;
        std::vector<std::pair<int, int>> vect;

        for (int i = 0; i < nums.size(); i++)
            vect.push_back({ nums[i], cost[i] });

        std::sort(vect.begin(), vect.end());

        unsigned left = 0;
        unsigned right = vect.size() - 1;

        while (left < right)
        {
            unsigned mid = (left + right) / 2;

            if (findCost(vect[mid].first) < findCost(vect[mid].first + 1))
                right = mid;
            else
                left = mid + 1;
        }

        return findCost(vect[left].first);
    }
};

int main()
{
    Solution s;
    std::vector nums = { 6,5,8,2,9,8,8,2,4,8,8,2,1,8,8,6,3,8,9,7,7,9,3,9,4,3,7,5,1,3,6,3,1,2,6 };
    std::vector cost = { 4,8,7,8,5,2,4,5,8,4,2,2,3,7,5,4,2,3,5,3,5,2,8,5,9,3,6,8,2,8,3,1,8,5,1 };

    std::cout << s.minCost_vers2(nums, cost) << std::endl;

    return 0;
}

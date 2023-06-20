//2090. K Radius Subarray Averages(Medium)
//
//----------------------------------------------------------------------- 
// https://leetcode.com/problems/k-radius-subarray-averages/description/
//----------------------------------------------------------------------- 
// 
//You are given a 0 - indexed array nums of n integers, and an integer k.
//
//The k - radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k(inclusive).
//If there are less than k elements before or after the index i, then the k - radius average is - 1.
//
//Build and return an array avgs of length n where avgs[i] is the k - radius average for the subarray centered at index i.
//
//The average of x elements is the sum of the x elements divided by x, using integer division.The integer division truncates toward zero, which means losing its fractional part.
//
//For example, the average of four elements 2, 3, 1, and 5 is(2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.
//
//Example 1:
//    Input: nums = [7, 4, 3, 9, 1, 8, 5, 2, 6], k = 3
//    Output : [-1, -1, -1, 5, 4, 4, -1, -1, -1]
//    Explanation :
//        -avg[0], avg[1], and avg[2] are - 1 because there are less than k elements before each index.
//        - The sum of the subarray centered at index 3 with radius 3 is : 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
//        Using integer division, avg[3] = 37 / 7 = 5.
//        - For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
//        - For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
//        - avg[6], avg[7], and avg[8] are - 1 because there are less than k elements after each index.
//
//Example 2 :
//    Input : nums = [100000], k = 0
//    Output : [100000]
//    Explanation :
//        -The sum of the subarray centered at index 0 with radius 0 is : 100000.
//        avg[0] = 100000 / 1 = 100000.
//
//Example 3 :
//    Input : nums = [8], k = 100000
//    Output : [-1]
//        Explanation :
//        -avg[0] is - 1 because there are less than k elements before and after index 0.
//
//Constraints :
//    n == nums.length
//    1 <= n <= 10^5
//    0 <= nums[i], k <= 10^5

#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k)
    {
        std::vector<int> res(nums.size(), -1);
        std::vector<long long> temp(nums.begin(), nums.end());
        int window = 2 * k + 1;

        if (nums.size() < window)
            return res;

        for (int i = 1; i < temp.size(); i++)
            temp[i] += temp[i - 1];

        res[k] = (temp[k + k] / window);
        for (int i = k + 1; i < nums.size() - k; i++)
            res[i] = ((temp[i + k] - temp[i - k - 1]) / window);


        return res;
    }

    // This solution works but has "Time Limit Exceeded" with a long array
    std::vector<int> getAverages_vers1(std::vector<int>& nums, int k) 
    {
        std::vector<int> res;
        res.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k && i + k < nums.size())
            {
                int sum = 0;
                int counter = 0;
                for (int j = i - k; j <= i + k && j < nums.size(); j++)
                {
                    sum += nums[j];
                    counter++;
                }
                res.emplace_back(sum / counter);
            }
            else
                res.emplace_back(-1);
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::vector arr = { 7,4,3,9,1,8,5,2,6 };
    std::vector<int> res = s.getAverages(arr, 3);

    for (const auto& i : res)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

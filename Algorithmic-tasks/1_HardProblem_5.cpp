//41. First Missing Positive(Hard)
//
//------------------------------------------------------------------- 
// https://leetcode.com/problems/first-missing-positive/description/ 
//------------------------------------------------------------------- 
// 
//Given an unsorted integer array nums, return the smallest missing positive integer.
//You must implement an algorithm that runs in O(n) time and uses constant extra space.
//
//Example 1:
//    Input: nums = [1, 2, 0]
//    Output : 3
//    Explanation : The numbers in the range[1, 2] are all in the array.
//
//Example 2 :
//    Input : nums = [3, 4, -1, 1]
//    Output : 2
//    Explanation : 1 is in the array but 2 is missing.
//
//Example 3 :
//    Input : nums = [7, 8, 9, 11, 12]
//    Output : 1
//    Explanation : The smallest positive integer 1 is missing.
//
//Constraints :
//    1 <= nums.length <= 105
//    - 231 <= nums[i] <= 231 - 1

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    // The first solution is in my head
    int firstMissingPositive_vers1(std::vector<int>& nums)
    {
        std::map<int, int> mp;

        for (int i = 1; i <= nums.size(); i++)
            mp[i];

        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        int  i = 1;
        while (i < mp.size() + 1)
        {
            if (mp[i] == 0)
                return i;
            i++;
        }

        return i;
    }

    // I deleted 1 extra loop
    int firstMissingPositive_vers2(std::vector<int>& nums)
    {
        std::map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        int  i = 1;
        while (i < mp.size() + 1)
        {
            if (mp[i] == 0)
                return i;
            i++;
        }

        return i;
    }

    // this algorithm's more faster with unordered_map than with map, we don't need to sort the hash
    int firstMissingPositive_vers3(std::vector<int>& nums)
    {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        int  i = 1;
        while (i < mp.size() + 1)
        {
            if (mp[i] == 0)
                return i;
            i++;
        }

        return i;
    }

    // THE FASTEST ALGORITHM
    // Solution after discussion on the forum
    int firstMissingPositive_vers4(std::vector<int>& nums)  
    {
        std::vector vec(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0 && nums[i] <= nums.size())
                vec[nums[i]] = 1;

        for (int i = 1; i <= vec.size(); i++)
            if (i == 0)
                return i;

        return vec.size();
    }
};

int main()
{
    Solution s;
    std::vector vec{ 1 };
    std::vector vec2{ 3,4,-1,1 };
    std::cout << s.firstMissingPositive_vers4(vec);
    std::cout << s.firstMissingPositive_vers4(vec2);
    return 0;
}

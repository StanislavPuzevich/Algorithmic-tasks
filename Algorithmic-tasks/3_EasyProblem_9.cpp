//217. Contains Duplicate
// 
//---------------------------------------------------------------
// https://leetcode.com/problems/contains-duplicate/description/
//---------------------------------------------------------------
// 
//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
//
//Example 1:
//    Input: nums = [1, 2, 3, 1]
//    Output : true
//
//Example 2 :
//    Input : nums = [1, 2, 3, 4]
//    Output : false
//
//Example 3 :
//    Input : nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
//    Output : true
//
//Constraints :
//    1 <= nums.length <= 10^5
//    - 10^9 <= nums[i] <= 10^9

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution 
{
public:
    bool containsDuplicate_vers1(std::vector<int>& nums)    // O(N*log(N)) Runtime: ~123ms Beats 91.26% | Memory: 57.4MB Beats 71.4%
    {                                                      
        std::sort(nums.begin(), nums.end());               
                                                           
        for (int i = 0, j = i + 1; j < nums.size(); i++)
            if (nums[i] == nums[j])                        
                return true;                               
                                                           
        return false;                                      
    }                                                      
                                                           
    bool containsDuplicate_vers2(std::vector<int>& nums)    // O(N)        Runtime: ~160ms Beats 37.50% | Memory: 71.5MB Beats 25.41%
    {
        std::unordered_set<int> ust;        //std::unordered_map<int,int> ump;

        for (auto i : nums) ust.insert(i);  //unp[i];

        return nums.size() > ust.size() ? true : false;
    }

    bool containsDuplicate_vers3(std::vector<int>& nums)    // O(N)        Runtime: ~135ms Beats 78.35% | Memory: 69.6MB Beats 52.7%
    {
        std::unordered_set<int> ust;

        for (auto i : nums)
            if (ust.find(i) != ust.end())
                return true;

        return nums.size() > ust.size() ? true : false;
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ 5,5,3,4,1 };

    std::cout << "Answer: " << s.containsDuplicate_vers2(vec) << std::endl;

    return 0;
}

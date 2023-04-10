//448. Find All Numbers Disappeared in an Array (Easy)
//
//-------------------------------------------------------------------------------------
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
//-------------------------------------------------------------------------------------
//
//Given an array nums of n integers where nums[i] is in the range[1, n], return an array of all the integers in the range[1, n] that do not appear in nums.
//
//Example 1:
//Input: nums = [4, 3, 2, 7, 8, 2, 3, 1]
//Output : [5, 6]
//
//Example 2 :
//    Input : nums = [1, 1]
//    Output : [2]
//
//Constraints :
//    n == nums.length
//    1 <= n <= 105
//    1 <= nums[i] <= n
//
//Follow up : Could you do it without extra spaceand in O(n) runtime ? You may assume the returned list does not count as extra space.

#include <iostream>
#include <vector>
#include <set>

class Solution 
{
public:
    std::vector<int> findDisappearedNumbers_vers1(std::vector<int>&nums)
    {       
        std::vector<int> result;
        std::set<int> st(nums.begin(), nums.end());

        auto iter = st.begin();
        for (int i = 1, j = 0; i <= nums.size(); i++)
        {
            if (i != *iter)
            {
                result.push_back(i);
            }
            else
                iter++;
        }

        return result;
    }    
     
    // this function works but for a long vector we have "Time Limit Exceeded"
    std::vector<int> findDisappearedNumbers_vers2(std::vector<int>& nums)
    { 
        std::vector<int> result;
        
        for (int i = 1; i <= nums.size(); i++)
        {
            if (std::find(nums.begin(), nums.end(), i) == nums.end())
            {
                result.push_back(i);
            }
        }

        return result;
    }

    // Implementation after reviewing the issue on the forum
    std::vector<int> findDisappearedNumbers_vers3(std::vector<int>& nums)
    {
        std::vector<int> result;

        int i = 0;
        while (i < nums.size())
        {
            int pos = nums[i] - 1;
            if (nums[i] != nums[pos])
            {
                std::swap(nums[i], nums[pos]);
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                result.push_back(i + 1);
            }
        }

        return result;
    }

    // Implementation after reviewing the issue on the forum
    std::vector<int> findDisappearedNumbers_vers4(std::vector<int>& nums)
    {
        std::vector<bool> vec(nums.size() + 1);
        std::vector<int> result;

        for (auto i : nums)
        {
            vec[i] = true;
        }

        for (int i = 1; i < vec.size(); i++)
        {
            if (!vec[i])
            {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ 4,3,2,7,8,2,3,1 };

    for (auto i : s.findDisappearedNumbers_vers4(vec))
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

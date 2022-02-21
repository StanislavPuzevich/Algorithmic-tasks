//217. Contains Duplicate
//
//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
//
//Example 1:
//Input: nums = [1, 2, 3, 1]
//Output : true
//
//Example 2 :
//Input : nums = [1, 2, 3, 4]
//Output : false
//
//Constraints :
//    1 <= nums.length <= 105
//    - 109 <= nums[i] <= 109

#include <iostream>   
#include <vector>
#include <set>
#include <algorithm>


class Solution                        
{
public:
    bool containsDuplicate1(std::vector<int>& nums)     //fast solution ~111ms
    {
        if (nums.size() == 1) return false;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;

        return false;
    }

    bool containsDuplicate2(std::vector<int>& nums)     //slow solution ~160ms
    {
        std::set<int> st;

        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);

        return nums.size() == st.size() ? false : true;
    }
};


int main()
{
    Solution s;
    std::vector<int> vec{ 1,1,1,3,3,4,3,2,4,2 };

    std::cout << s.containsDuplicate1(vec) << std::endl;
    std::cout << s.containsDuplicate2(vec) << std::endl;

    return 0;
}
//88. Merge Sorted Array
//
//--------------------------------------------------
//https://leetcode.com/problems/merge-sorted-array/
//--------------------------------------------------
//
//You are given two integer arrays nums1 and nums2, sorted in non - decreasing order, and two integers mand n, 
//representing the number of elements in nums1and nums2 respectively.
//Merge nums1and nums2 into a single array sorted in non - decreasing order.
//The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
//To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
//and the last n elements are set to 0 and should be ignored.nums2 has a length of n.
//
//Example 1:
//    Input: nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//    Output : [1, 2, 2, 3, 5, 6]
//    Explanation : The arrays we are merging are[1, 2, 3] and [2, 5, 6].
//    The result of the merge is[1, 2, 2, 3, 5, 6] with the underlined elements coming from nums1.
//
//Example 2 :
//    Input : nums1 = [1], m = 1, nums2 = [], n = 0
//    Output : [1]
//    Explanation : The arrays we are merging are[1] and [].
//    The result of the merge is[1].
//
//Example 3 :
//    Input : nums1 = [0], m = 0, nums2 = [1], n = 1
//    Output : [1]
//    Explanation : The arrays we are merging are[] and [1].
//    The result of the merge is[1].
//    Note that because m = 0, there are no elements in nums1.The 0 is only there to ensure the merge result can fit in nums1.
//
//Constraints :
//    nums1.length == m + n
//    nums2.length == n
//    0 <= m, n <= 200
//    1 <= m + n <= 200
//    - 109 <= nums1[i], nums2[j] <= 109
//
//Follow up : Can you come up with an algorithm that runs in O(m + n) time ?

#include <iostream>
#include <vector>
#include <algorithm>


class Solution
{
public:
    void merge1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)  //1 version 02.2022
    {
        int size = nums1.size();
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (j < n && nums1[i] > nums2[j])
            {
                nums1.emplace(nums1.begin() + i, nums2[j]);
                j++;
                m++;
                nums1.pop_back();
            }
        }

        while (j < n)
        {
            nums1.emplace(nums1.begin() + m, nums2[j]);
            nums1.pop_back();
            m++;
            j++;
        }
    }

    // MORE FAST
    void merge2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)  // 2nd version 06.2022
    {
        for (int i = m, j = 0; i < nums1.size(); i++, j++)
            nums1[i] = nums2[j];

        std::sort(nums1.begin(), nums1.end());
    }

    void merge3(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)  // 3rd version after parsing on the Internet 06.2022
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
                nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};

int main()
{
    Solution s;
    std::vector<int> nums1 { 2,0 };
    std::vector<int> nums2 { 1 };

    s.merge2(nums1, 1, nums2, 1);

    for (auto i : nums1)
        std::cout << i << "  ";
    std::cout << std::endl;

    return 0;
}
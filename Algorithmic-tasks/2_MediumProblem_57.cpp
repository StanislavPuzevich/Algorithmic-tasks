//373. Find K Pairs with Smallest Sums(Medium)
//
//----------------------------------------------------------------
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
//----------------------------------------------------------------
// 
//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//Define a pair(u, v) which consists of one element from the first array and one element from the second array.
//Return the k pairs(u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
//
//Example 1:
//    Input: nums1 = [1, 7, 11], nums2 = [2, 4, 6], k = 3
//    Output : [[1, 2], [1, 4], [1, 6]]
//    Explanation : The first 3 pairs are returned from the sequence : [1, 2] , [1, 4], [1, 6], [7, 2], [7, 4], [11, 2], [7, 6], [11, 4], [11, 6]
//
//Example 2 :
//    Input : nums1 = [1, 1, 2], nums2 = [1, 2, 3], k = 2
//    Output : [[1, 1], [1, 1]]
//    Explanation : The first 2 pairs are returned from the sequence : [1, 1] , [1, 1], [1, 2], [2, 1], [1, 2], [2, 2], [1, 3], [1, 3], [2, 3]
//
//Example 3 :
//    Input : nums1 = [1, 2], nums2 = [3], k = 3
//    Output : [[1, 3], [2, 3]]
//    Explanation : All possible pairs are returned from the sequence : [1, 3] , [2, 3]
//
//Constraints :
//    1 <= nums1.length, nums2.length <= 10^5
//    - 10^9 <= nums1[i], nums2[i] <= 10^9
//    nums1 and nums2 both are sorted in ascending order.
//    1 <= k <= 10^4

#include <iostream>
#include <vector>
#include <queue>

class Solution 
{
public:
    std::vector<std::vector<int>> kSmallestPairs_vers2(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        std::vector<std::vector<int>> answ;
        std::priority_queue<std::pair<int, std::pair<int, int>>> heap;

        for (auto i : nums1)
            for (auto j : nums2)
            {
                int sum = i + j;

                if (heap.size() < k)
                    heap.push({ sum,{i,j} });
                else if (sum < heap.top().first)
                {
                    heap.pop();
                    heap.push({ sum,{i,j} });
                }
                else break;
            }

        while (!heap.empty())
        {
            answ.push_back({ heap.top().second.first, heap.top().second.second });
            heap.pop();
        }  

        return answ;
    }

    // Time Limit Exceeded
    std::vector<std::vector<int>> kSmallestPairs_vers1(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        std::vector<std::vector<int>> answ;
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;

        for (auto i : nums1)
            for (auto j : nums2)
                pq.push({ i + j,{i,j} });

        while (pq.size() > k)
            pq.pop();

        while (!pq.empty())
        {
            answ.push_back({ pq.top().second.first, pq.top().second.second });
            pq.pop();
        }

        return answ;
    }
};

int main()
{
    Solution s;
    std::vector nums1 = { 1, 7, 11 };
    std::vector nums2 = { 2, 4, 6 };

    std::vector<std::vector<int>> vect = s.kSmallestPairs_vers2(nums1, nums2, 3);

    for (const auto& vec : vect)
    {
        for (const auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}

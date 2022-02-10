//560. Subarray Sum Equals K
//
//Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k
//
//Example 2:
//Input: nums = [1, 2, 3], k = 3
//Output : 2
//
//Constraints :
//
//    1 <= nums.length <= 2 * 104
//    - 1000 <= nums[i] <= 1000
//    - 107 <= k <= 107

#include <iostream>   
#include <vector> 
#include <unordered_map>


int subarraySum(std::vector<int>& nums, int k)
{
    int sum = 0, count = 0;
    std::unordered_map<int, int> map;
    for (auto i : nums)
    {
        sum += i;
        if (sum == k)count++;
        if (map.find(sum - k) != map.end()) count += map[sum - k];
        map[sum + i]++;
    }
    return count;
}


int main()                                                 
{
    std::vector<int>vec{ 28,54,7,-70,22,65,-6};

    std::cout << subarraySum(vec, 100) << std::endl;

	return 0;
}
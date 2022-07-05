//128. Longest Consecutive Sequence
//
//------------------------------------------------------------
//https://leetcode.com/problems/longest-consecutive-sequence/
//------------------------------------------------------------
//
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.
//
//Example 1:
//	Input: nums = [100, 4, 200, 1, 3, 2]
//	Output : 4
//	Explanation : The longest consecutive elements sequence is[1, 2, 3, 4].Therefore its length is 4.
//
//Example 2 :
//	Input : nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
//	Output : 9
//
//Constraints :
//	0 <= nums.length <= 10^5
//	- 10^9 <= nums[i] <= 10^9

#include <iostream>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
	// 1-st version (faster then 2-nd) O((log n) + n)
	int longestConsecutive(std::vector<int>& nums)
	{
		if (nums.empty()) return 0;

		int counter = 1, max = 0;
		std::sort(nums.begin(), nums.end());

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] - nums[i - 1] == 1)
				counter++;
			else if(nums[i] - nums[i - 1] != 0)
			{
				max = std::max(max, counter);
				counter = 1;
			}
		}
		max = std::max(max, counter);

		return max;
	}

	// 2-nd version
	int longestConsecutive_2(std::vector<int>& nums)
	{
		if (nums.empty()) return 0;

		std::unordered_set<int> us(nums.begin(), nums.end());
		int max = 0;

		for (int i : nums)
		{
			if (us.count(i - 1))continue;
			int counter = 1;
			while (us.find(i + 1) != us.end())
			{
				counter++;
				i++;
			}
			max = std::max(max, counter);
		}

		return max;
	}
};

int main()
{
	Solution s;
	std::vector<int> num{0,3,7,2,5,8,4,6,0,1};

	std::cout << "Result: " << s.longestConsecutive(num) << std::endl;

	return 0;
}
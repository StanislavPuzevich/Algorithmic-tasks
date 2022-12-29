﻿//268. Missing Number
// 
//----------------------------------------------------------
//https://leetcode.com/problems/missing-number/description/ 
//----------------------------------------------------------
//  
//Given an array nums containing n distinct numbers in the range[0, n], return the only number in the range that is missing from the array.
//
//Example 1:
//	Input: nums = [3, 0, 1]
//	Output : 2
//	Explanation : n = 3 since there are 3 numbers, so all numbers are in the range[0, 3]. 
//	2 is the missing number in the range since it does not appear in nums.
//
//Example 2 :
//	Input : nums = [0, 1]
//	Output : 2
//	Explanation : n = 2 since there are 2 numbers, so all numbers are in the range[0, 2].
//  2 is the missing number in the range since it does not appear in nums.
//	
//Example 3 :
//	Input : nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
//	Output : 8
//	Explanation : n = 9 since there are 9 numbers, so all numbers are in the range[0, 9]. 
//  8 is the missing number in the range since it does not appear in nums.
//
//Constraints :
//	n == nums.length
//	1 <= n <= 104
//	0 <= nums[i] <= n
//	All the numbers of nums are unique.
// 
//Follow up : Could you implement a solution using only O(1) extra space complexityand O(n) runtime complexity ?

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	int missingNumber(std::vector<int>& nums)		//1-st solution in my head
	{
		std::sort(nums.begin(), nums.end());
		if (*(nums.begin()) != 0) return 0;

		for (int i = 0, j = 1; j < nums.size(); i++, j++)
			if (nums[j] - nums[i] != 1)
				return (nums[j] + nums[i]) / 2;

		return nums[nums.size() - 1] + 1;
	}

	int missingNumber_1(std::vector<int>& nums)		//2-nd solution after discussing on the forum
	{
		std::sort(nums.begin(), nums.end());

		int i = 0;
		for (;i < nums.size(); i++)
			if ((nums[i] ^ i) != 0)
				break;

		return i;
	}
};

int main()
{
	Solution s;
	std::vector<int> vec = { 9, 6, 4, 2, 3, 5, 7, 0, 1, 8, 11, 12 };
	std::cout << "Result: " << s.missingNumber(vec);
	return 0;
}
//525. Contiguous Array
//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
//
//Constraints:
//1 <= nums.length <= 105
//nums[i] is either 0 or 1.
//
//Example 1:
//	Input: nums = [0, 1]
//	Output : 2
//	Explanation : [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
//
//Example 2 :
//	Input : nums = [0, 1, 0]
//	Output : 2
//	Explanation : [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

#include <iostream>               
#include <vector>          
#include <unordered_map>
#include <Algorithm> 


int findMaxLength(std::vector<int>& nums)     //O(n)
{
	int sum = 0, map_max = 0;
	std::unordered_map<int, int> map{ {0,-1} };

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
			sum += 1;
		else sum -= 1;

		if (map.count(sum)) map_max = std::max(map_max, (i - map[sum]));
		else map[sum] = i;
	}
	return map_max;
}


int main()                                                 
{           
	std::vector<int>vec{ 1,1,1,1,1,1,0,0 };
													
	std::cout << "RESULT: " << findMaxLength(vec) << std::endl;

	return 0;
}

//int findMaxLength(std::vector<int>& nums)          O(n^2)     TIME LIMIT Exceeded, but this function works with a small arrays!
//{
//	int max = 0, sum;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		sum = 0;
//		for (int j = i; j < nums.size(); j++)
//		{
//			if (nums[j] == 0)
//				sum -= 1;
//			else
//				sum += 1;
//			if (sum == 0 && (j - i) > max)
//				max = j - i;
//		}
//	}
//	return max;
//}
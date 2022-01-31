//189. Rotate Array
//Given an array, rotate the array to the right by k steps, where k is non - negative.
// 
//Constraints:
//1 <= nums.length <= 105
//- 231 <= nums[i] <= 231 - 1
//0 <= k <= 105
//
//Follow up :
//Try to come up with as many solutions as you can.There are at least three different ways to solve this problem.
//Could you do it in - place with O(1) extra space ?
 
#include <iostream>
#include <vector> 

void rotate(std::vector<int>& nums, int k)
{
	std::vector<int>nums2 = nums;
	k %= nums.size();
	nums.erase(nums.end() - k, nums.end());
	nums2.erase(nums2.begin(), nums2.begin() + (nums2.size() - k));
	nums.insert(nums.begin(), nums2.begin(), nums2.end());
}

void showArray(std::vector<int>& nums)
{
	for (auto& i : nums)
		std::cout << i << " ";
}

int main()
{
	std::vector<int>vect{ 1,2,3,4,5,6,7 };
	int k;

	std::cout << "Enter the number: ";
	std::cin >> k;
    
	rotate(vect, k);
	showArray(vect);

	return 0;
}

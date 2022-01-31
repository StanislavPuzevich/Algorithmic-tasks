/*4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/

#include <iostream>
#include <vector>
#include <Algorithm>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	nums1.insert(nums1.end(), nums2.begin(), nums2.end());

	sort(nums1.begin(), nums1.end());
	if (nums1.size() % 2)
		return nums1[nums1.size() / 2];
	return double(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
}

int main()
{
	std::vector<int>v1{1,4};       //we can write different values to vectors;
	std::vector<int>v2{2,3,5,7};
	
	std::cout << "RESULT: " << findMedianSortedArrays(v1, v2);
	
	return 0;
}

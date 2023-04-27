//42. Trapping Rain Water
//
//----------------------------------------------------
// https://leetcode.com/problems/trapping-rain-water/
//----------------------------------------------------
//
//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//
//Example 1:
//Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//Output : 6
//Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain 
//water(blue section) are being trapped.
//
//Example 2:
//Input: height = [4, 2, 0, 3, 2, 5]
//Output : 9
//
//Constraints :
//	n == height.length
//	1 <= n <= 2 * 104
//	0 <= height[i] <= 105

#include <iostream>               
#include <vector>          
#include <Algorithm>

int trap_vers1(std::vector<int>& height)                        //плохой код - решал как мог(без подсказок)
{
	long long sum = 0;
	int left = 0, right = height.size() - 1;

	int i = left + 1;
	int j = right - 1;
	while (left < right && (height[left] <= height[i] || height[right] <= height[j]))
	{
		if (height[left] <= height[i])
		{
			left++; i++;
		}
		if (height[right] <= height[j])
		{
			right--; j--;
		}
	}

	int max = *(std::max_element(height.begin(), height.end()));

	if (max != height[left])
		while (i <= j && height[i] < max)
		{
			if (std::min(height[left], max) >= height[i])
			{
				sum += std::min(height[left], max) - height[i];
				i++;
			}
			else
			{
				left = i;
				i++;
			}
		}

	while (i <= j && height[j] <= max)
	{
		if (std::min(height[right], max) >= height[j])
		{
			sum += std::min(height[right], max) - height[j];
			j--;
		}
		else
		{
			right = j;
			j--;
		}
	}

	return sum;
}

int trap_vers2(std::vector<int>& height)              //после анализа чужих функций, переписал свою
{
	int sum = 0;
	int left = 0, right = height.size() - 1;
	int maxLeft = 0, maxRight = 0;

	while (left < right)
	{
		if (height[left] < height[right])
		{
			if (height[left] > maxLeft)
				maxLeft = height[left];
			else sum += maxLeft - height[left];
			left++;
		}
		else
		{
			if (height[right] > maxRight)
				maxRight = height[right];
			else sum += maxRight - height[right];
			right--;
		}
	}

	return sum;
}

int main()                                                 
{             
	std::vector<int>vec{ 0,1,0,2,1,0,1,3,2,1,2,1 };
													
	std::cout << "RESULT: " << trap_vers2(vec) << std::endl;

	return 0;
}

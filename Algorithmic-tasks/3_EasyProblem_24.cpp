//1710. Maximum Units on a Truck ( + TIMERS)
//
//--------------------------------------------------------
//https://leetcode.com/problems/maximum-units-on-a-truck/
//--------------------------------------------------------
//
//You are assigned to put some amount of boxes onto one truck.You are given a 2D array boxTypes, 
//where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
//numberOfBoxesi is the number of boxes of type i.
//numberOfUnitsPerBoxi is the number of units in each box of the type i.
//You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck.
//You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
//Return the maximum total number of units that can be put on the truck.
//
//Example 1:
//	Input: boxTypes = [[1, 3], [2, 2], [3, 1]], truckSize = 4
//	Output : 8
//	Explanation : There are :
//	-1 box of the first type that contains 3 units.
//	- 2 boxes of the second type that contain 2 units each.
//	- 3 boxes of the third type that contain 1 unit each.
//	You can take all the boxes of the first and second types, and one box of the third type.
//	The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
//	
//Example 2:
//	Input: boxTypes = [[5, 10], [2, 5], [4, 7], [3, 9]], truckSize = 10
//	Output : 91
//
//Constraints :
//	1 <= boxTypes.length <= 1000
//	1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
//	1 <= truckSize <= 10^6

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/*The input values are too small to reflect the real difference in the performance of the methods.
But the second version is much faster according to the LeetCode website.*/

class Solution 
{
public:
	// 2-nd version
	int maximumUnits_1(std::vector<std::vector<int>>& boxTypes, int truckSize)
	{
		int result = 0;
		std::sort(boxTypes.begin(), boxTypes.end(), [](std::vector<int>& a, std::vector<int>& b) {return a[1] > b[1]; });

		for (auto i : boxTypes)
		{
			while (i[0] - truckSize > 0 && i[0] > 0)
				i[0]--;

			result += i[0] * i[1];
			truckSize -= i[0];

			if (truckSize == 0) break;
		}

		return result;
	}

	// 1-st version
	int maximumUnits_2(std::vector<std::vector<int>>& boxTypes, int truckSize)    
	{
		int result = 0, counter = 0;
		std::sort(boxTypes.begin(), boxTypes.end(), [](std::vector<int>& a, std::vector<int>& b) {return a[1] > b[1]; });

		for (auto i : boxTypes)
		{
			if (counter + i[0] < truckSize)
			{
				result += i[0] * i[1];
				counter += i[0];
			}
			else
			{
				while (counter + i[0] > truckSize && i[0] > 0)
					i[0]--;

				result += i[0] * i[1];
				counter += i[0];
			}
			if (counter == truckSize) break;
		}

		return result;
	}
};

int main()
{
	Solution s;
	int truckSize = 100000;
	std::vector<std::vector<int>> boxTypes
	{
		{5,10},{2,5},{4,7},{3,9},{112,5},{24,0},{1,24},{6,14},{26,53},{2,13},{43,1},
		{5,21},{22,5},{4,17},{13,9},{11,5},{12,1},{7,20},{3,14},{26,8},{2,111},{23,3},
		{1,221},{2,45},{4,10},{13,92},{111,1},{2,8},{11,20},{13,19},{20,4},{4,22},{2,3},
	};

	std::cout << "Result: " << s.maximumUnits_1(boxTypes, truckSize) << std::endl << std::endl;

	//--------------------------------------- ADDITIONAL PART ---------------------------------------

	std::vector<std::vector<int>> time_results(10, std::vector<int>(2, 0));

	int times = 10;
	while (times)
	{
		auto time_begin_1 = std::chrono::steady_clock::now();
		s.maximumUnits_1(boxTypes, truckSize);
		auto time_end_1 = std::chrono::steady_clock::now();

		auto time_begin_2 = std::chrono::steady_clock::now();
		s.maximumUnits_2(boxTypes, truckSize);
		auto time_end_2 = std::chrono::steady_clock::now();

		auto time_difference_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end_1 - time_begin_1);
		auto time_difference_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end_2 - time_begin_2);
		time_results[times - 1][0] = time_difference_1.count();
		time_results[times - 1][1] = time_difference_2.count();

		times--;
	}

	std::cout << "Time reaults: " << std::endl;
	for (int i = 0; i < time_results.size(); i++)
		std::cout << time_results[i][0] << '\t' << time_results[i][1] << std::endl;

	return 0;
}

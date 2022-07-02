//1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
//
//--------------------------------------------------------------------------------------------------
//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
//--------------------------------------------------------------------------------------------------
//
//You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
//horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
//verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
//Return the maximum area of a piece of cake after you cut at each horizontaland vertical position provided in the arrays 
//horizontalCutsand verticalCuts.Since the answer can be a large number, return this modulo 10^9 + 7.
//
//Example 1:
//	Input: h = 5, w = 4, horizontalCuts = [1, 2, 4], verticalCuts = [1, 3]
//	Output : 4
//	Explanation : The figure above represents the given rectangular cake.Red lines are the horizontal and vertical cuts.
//	After you cut the cake,the green piece of cake has the maximum area.
//
//Example 2 :
//	Input : h = 5, w = 4, horizontalCuts = [3, 1], verticalCuts = [1]
//	Output : 6
//	Explanation : The figure above represents the given rectangular cake.Red lines are the horizontal and vertical cuts.
//	After you cut the cake, the green and yellow pieces of cake have the maximum area.
//
//Example 3 :
//	Input : h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
//	Output : 9
//
//Constraints :
//	2 <= h, w <= 10^9
//	1 <= horizontalCuts.length <= min(h - 1, 10^5)
//	1 <= verticalCuts.length <= min(w - 1, 10^5)
//	1 <= horizontalCuts[i] < h
//	1 <= verticalCuts[i] < w
//	All the elements in horizontalCuts are distinct.
//	All the elements in verticalCuts are distinct.

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	// concise version
	int maxArea_1(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts)
	{
		int max_horizontal = 0, max_vertical = 0;

		horizontalCuts.push_back(0); horizontalCuts.push_back(h);
		verticalCuts.push_back(0); verticalCuts.push_back(w);

		std::sort(horizontalCuts.begin(), horizontalCuts.end());
		std::sort(verticalCuts.begin(), verticalCuts.end());

		for (int i = 1; i < horizontalCuts.size(); i++)
			max_horizontal = std::max(max_horizontal, horizontalCuts[i] - horizontalCuts[i - 1]);

		for (int i = 1; i < verticalCuts.size(); i++)
			max_vertical = std::max(max_vertical, verticalCuts[i] - verticalCuts[i - 1]);

		return (1ll * max_horizontal * max_vertical) % 1000000007;
	}

	// more faster version ('for' cycle is replaced by 'while' cycle)
	int maxArea_2(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts)
	{
		int max_horizontal = 0, max_vertical = 0;

		horizontalCuts.push_back(0); horizontalCuts.push_back(h);
		verticalCuts.push_back(0); verticalCuts.push_back(w);

		std::sort(horizontalCuts.begin(), horizontalCuts.end());
		std::sort(verticalCuts.begin(), verticalCuts.end());

		int hor_size = horizontalCuts.size();
		int vert_size = verticalCuts.size();

		int i = 1;
		while (i < hor_size && i < vert_size)
		{
			max_horizontal = std::max(max_horizontal, horizontalCuts[i] - horizontalCuts[i - 1]);
			max_vertical = std::max(max_vertical, verticalCuts[i] - verticalCuts[i - 1]);
			i++;
		}

		while (i < hor_size)
		{
			max_horizontal = std::max(max_horizontal, horizontalCuts[i] - horizontalCuts[i - 1]);
			i++;
		}
		while (i < vert_size)
		{
			max_vertical = std::max(max_vertical, verticalCuts[i] - verticalCuts[i - 1]);
			i++;
		}

		return (1ll * max_horizontal * max_vertical) % 1000000007;
	}
};

int main()
{
	Solution s;
	int h = 5, w = 4;
	std::vector<int> horizontalCuts{ 1, 2, 4 }, verticalCuts{ 1, 3 };

	std::cout << "Result: " << s.maxArea_1(h, w, horizontalCuts, verticalCuts) << std::endl;

	return 0;
}

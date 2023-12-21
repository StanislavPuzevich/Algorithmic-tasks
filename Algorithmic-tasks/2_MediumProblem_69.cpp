//1637. Widest Vertical Area Between Two Points Containing No Points(Medium)
//
//--------------------------------------------------------------------------------------------- 
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
//--------------------------------------------------------------------------------------------- 
// 
//Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
//A vertical area is an area of fixed - width extending infinitely along the y - axis(i.e., infinite height).The widest vertical area is the one with the maximum width.
//Note that points on the edge of a vertical area are not considered included in the area.
//
//Example 1:​
//    Input : points = [[8, 7], [9, 9], [7, 4], [9, 7]]
//    Output : 1
//    Explanation : Both the red and the blue area are optimal.
//
//Example 2 :
//    Input : points = [[3, 1], [9, 0], [1, 0], [1, 4], [5, 3], [8, 8]]
//    Output : 3
//
//Constraints :
//    n == points.length
//    2 <= n <= 10^5
//    points[i].length == 2
//    0 <= xi, yi <= 10^9

#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) // more simple Solution
    {
        int maxWidth = -1;

        std::sort(points.begin(), points.end());

        for (int i = 1; i < points.size() - 1; i++)
            maxWidth = std::max(maxWidth, points[i][0] - points[i - 1][0]);

        return maxWidth;
    }

    int maxWidthOfVerticalArea_vers2(const std::vector<std::vector<int>>& points) // more faster Solution
    {
        int maxWidth = -1;
        std::vector<int> vec;

        for (auto i : points)
            vec.push_back(i[0]);

        std::sort(vec.begin(), vec.end());

        for(int i = 1; i < vec.size(); i++)
            maxWidth = std::max(maxWidth, vec[i] - vec[i - 1]);

        return maxWidth;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> points = { {3,1},{9,0},{1,0},{1,4},{5,3},{8,8} };

    std::cout << s.maxWidthOfVerticalArea(points) << std::endl;

    return 0;
}

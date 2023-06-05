//1232. Check If It Is a Straight Line(Easy)
//
//---------------------------------------------------------------------------- 
// https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
//---------------------------------------------------------------------------- 
// 
//You are given an array coordinates, coordinates[i] = [x, y], where[x, y] represents the coordinate of a point.Check if these points make a straight line in the XY plane.
//
//Example 1:
//    Input: coordinates = [[1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7]]
//    Output : true
//
//Example 2 :
//    Input: coordinates = [[1, 1], [2, 2], [3, 4], [4, 5], [5, 6], [7, 7]]
//    Output : false
//
//Constraints :
//    2 <= coordinates.length <= 1000
//    coordinates[i].length == 2
//    - 10 ^ 4 <= coordinates[i][0], coordinates[i][1] <= 10 ^ 4
//    coordinates contains no duplicate point.

#include <iostream>
#include <vector>

class Solution
{
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates)
    {
        if ((coordinates[1][0] - coordinates[0][0]) == 0)
        {
            for (int i = 1; i < coordinates.size(); i++)
                if ((coordinates[i][0] != coordinates[i - 1][0]))
                    return false;
        }
        else
        {
            // m = (y2-y1)/(x2-x1) math formula
            float m = static_cast<float>(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);

            for (int i = 1; i < coordinates.size(); i++)
            {
                int divisor = coordinates[i][0] - coordinates[i - 1][0];
                if (divisor == 0 || static_cast<float>(coordinates[i][1] - coordinates[i - 1][1]) / divisor != m)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    std::vector<std::vector<int>> vec = { {2,1} ,{4,2},{6,3} };

    std::cout << s.checkStraightLine(vec) << std::endl;

    return 0;
}

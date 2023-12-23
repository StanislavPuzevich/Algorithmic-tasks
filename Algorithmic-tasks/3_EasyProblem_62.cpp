//1496. Path Crossing(Easy)
//
//---------------------------------------------- 
// https://leetcode.com/problems/path-crossing/
//---------------------------------------------- 
// 
//Given a string path, where path[i] = 'N', 'S', 'E' or 'W', 
//each representing moving one unit north, south, east, or west, respectively.You start at the origin(0, 0) on a 2D plane and walk on the path specified by path.
//
//Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited.Return false otherwise.
//
//Example 1:
//    Input: path = "NES"
//    Output : false
//    Explanation : Notice that the path doesn't cross any point more than once.
//
//Example 2 :
//    Input : path = "NESWW"
//    Output : true
//    Explanation : Notice that the path visits the origin twice.
//
//Constraints :
//    1 <= path.length <= 10^4
//    path[i] is either 'N', 'S', 'E', or 'W'.

#include <iostream>
#include <string>
#include <unordered_set>

class Solution 
{
public:
    bool isPathCrossing(std::string path) 
    {
        std::unordered_set<std::string> visitedPoints;
        int currentX = 0;
        int currentY = 0;

        visitedPoints.insert(std::to_string(currentX) + ',' + std::to_string(currentY));

        for (const auto ch : path)
        {
            switch (ch)
            {
            case 'N': currentY++; break;
            case 'S': currentY--; break;
            case 'E': currentX++; break;
            case 'W': currentX--; break;
            default: break;
            }

            if (visitedPoints.count(std::to_string(currentX) + ',' + std::to_string(currentY)))
                return true;

            visitedPoints.insert(std::to_string(currentX) + ',' + std::to_string(currentY));
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::string str = "NESWW";

    std::cout << s.isPathCrossing(str) << std::endl;

    return 0;
}

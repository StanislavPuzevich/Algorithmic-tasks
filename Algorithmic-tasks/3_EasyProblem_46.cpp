//1351. Count Negative Numbers in a Sorted Matrix(Easy)
//
//--------------------------------------------------------------------------------------
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
//--------------------------------------------------------------------------------------
//
//Given a m x n matrix grid which is sorted in non - increasing order both row - wise and column - wise, return the number of negative numbers in grid.
//
//Example 1:
//    Input: grid = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
//    Output : 8
//    Explanation : There are 8 negatives number in the matrix.
//
//Example 2 :
//    Input : grid = [[3, 2], [1, 0]]
//    Output : 0
//
//Constraints :
//    m == grid.length
//    n == grid[i].length
//    1 <= m, n <= 100
//    - 100 <= grid[i][j] <= 100
//
//Follow up : Could you find an O(n + m) solution ?

#include <iostream>
#include <vector>

// O(n + m)
class Solution 
{
public:
    int countNegatives_vers1(std::vector<std::vector<int>>& grid) 
    {
        int counter = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] < 0)
                {
                    if (j == 0)
                    {
                        counter += grid[i].size() * (grid.size() - i);
                        return counter;
                    }
                    counter += grid[i].size() - j;
                    break;
                }
            }
        }

        return counter;
    }

    // O(n * m)
    int countNegatives_vers2(std::vector<std::vector<int>>& grid)
    {
        int counter = 0;

        for (auto i : grid)
            for (auto j : i)
                if (j < 0)
                    counter++;

        return counter;
    }
};

int main()
{
    Solution s;

    std::vector<std::vector<int>> grid =
    { 
        { 4,  3,  2, -1},
        { 3,  2,  1, -1},
        { 1,  1, -1, -2},
        {-1, -1, -2, -3} 
    };

    std::cout << s.countNegatives_vers1(grid) << std::endl;

    return 0;
}

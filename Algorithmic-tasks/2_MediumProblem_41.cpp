//695. Max Area of Island
//
//--------------------------------------------------
//https://leetcode.com/problems/max-area-of-island/ 
//--------------------------------------------------
// 
//You are given an m x n binary matrix grid.An island is a group of 
//1's (representing land) connected 4-directionally (horizontal or vertical.) 
//You may assume all four edges of the grid are surrounded by water.
//The area of an island is the number of cells with a value 1 in the island.
//Return the maximum area of an island in grid.If there is no island, return 0.
//
//Example 1:
//    Input: grid = 
//    [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
//     [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], 
//     [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0], 
//     [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0], 
//     [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0], 
//     [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], 
//     [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], 
//     [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]
//    Output : 6
//    Explanation : The answer is not 11, because the island must be connected 4 - directionally.
//
//Example 2 :
//    Input : grid = [[0, 0, 0, 0, 0, 0, 0, 0]]
//    Output : 0
//
//Constraints :
//    m == grid.length
//    n == grid[i].length
//    1 <= m, n <= 50
//    grid[i][j] is either 0 or 1.

#include <iostream>
#include <stack>
#include <vector>

struct Point
{
    int x, y;
};

class Solution 
{
public:
    // stack Solution
    int maxAreaOfIsland(std::vector<std::vector<int>> grid)
    {
        int max_island = 0, counter = 0;
        int size_col = grid.size(), size_row = grid[0].size();

        for (int i = 0; i < size_col; i++)
        {
            for (int j = 0; j < size_row; j++)
            {
                if (grid[i][j] == 1)
                {
                    std::stack<Point> st;
                    st.push({ i, j });
                    grid[i][j] = 0;
                    while (!st.empty())
                    {
                        Point point = st.top();
                        st.pop();
                        counter++;

                        if (point.x + 1 < size_col && grid[point.x + 1][point.y] == 1)
                        {
                            st.push({ point.x + 1, point.y });
                            grid[point.x + 1][point.y] = 0;
                        }

                        if (point.x > 0 && grid[point.x - 1][point.y] == 1)
                        {
                            st.push({ point.x - 1, point.y });
                            grid[point.x - 1][point.y] = 0;
                        }

                        if (point.y + 1 < size_row && grid[point.x][point.y + 1] == 1)
                        {
                            st.push({ point.x, point.y + 1 });
                            grid[point.x][point.y + 1] = 0;
                        }

                        if (point.y > 0 && grid[point.x][point.y - 1] == 1)
                        {
                            st.push({ point.x, point.y - 1});
                            grid[point.x][point.y - 1] = 0;
                        }
                    }
                    max_island = std::max(max_island, counter);
                    counter = 0;
                }
            }
        }

        return max_island;
    }

    // recursive Solution
    int maxAreaOfIsland_2(std::vector<std::vector<int>>& grid)
    {
        int max_island = 0, counter;
        int size_col = grid.size(), size_row = grid[0].size();

        for (int i = 0; i < size_col; i++)
        {
            for (int j = 0; j < size_row; j++)
            {
                if (grid[i][j] == 1)
                {
                    counter = 0;
                    counter_funct(grid, counter, i, j);
                    max_island = std::max(max_island, counter);
                }
            }
        }

        return max_island;
    }

    void counter_funct(std::vector<std::vector<int>>& grid, int& counter, int i, int j)
    {
        grid[i][j] = 0;
        counter++;

        if (i > 0 && grid[i - 1][j] == 1)
            counter_funct(grid, counter, i - 1, j);

        if (i + 1 < grid.size() && grid[i + 1][j] == 1)
            counter_funct(grid, counter, i + 1, j);

        if (j > 0 && grid[i][j - 1] == 1)
            counter_funct(grid, counter, i, j - 1);

        if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
            counter_funct(grid, counter, i, j + 1);
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> vec
    {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

    /*1st method takes an array by value to leave it operable for the second method,
    which takes an array as a parameter by reference.*/

    std::cout << "Max Area of Island (1st sol): " << s.maxAreaOfIsland(vec) << std::endl;
    std::cout << "Max Area of Island (2nd sol): " << s.maxAreaOfIsland_2(vec) << std::endl;

    return 0;
}

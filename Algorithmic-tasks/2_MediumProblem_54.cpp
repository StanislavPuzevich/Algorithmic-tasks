//2352. Equal Row and Column Pairs(Medium)
//
//----------------------------------------------------------------------- 
// https://leetcode.com/problems/equal-row-and-column-pairs/description/
//----------------------------------------------------------------------- 
// 
//Given a 0 - indexed n x n integer matrix grid, return the number of pairs(ri, cj) such that row ri and column cj are equal.
//A row and column pair is considered equal if they contain the same elements in the same order(i.e., an equal array).
//
//Example 1:
//    Input: grid = [[3, 2, 1], [1, 7, 6], [2, 7, 7]]
//    Output : 1
//    Explanation : There is 1 equal row and column pair :
//        -(Row 2, Column 1) : [2, 7, 7]
//
//Example 2 :
//    Input : grid = [[3, 1, 2, 2], [1, 4, 4, 5], [2, 4, 2, 2], [2, 4, 2, 2]]
//    Output : 3
//    Explanation : There are 3 equal row and column pairs :
//        - (Row 0, Column 0) : [3, 1, 2, 2]
//        - (Row 2, Column 2) : [2, 4, 2, 2]
//        - (Row 3, Column 2) : [2, 4, 2, 2]
//
//Constraints :
//    n == grid.length == grid[i].length
//    1 <= n <= 200
//    1 <= grid[i][j] <= 10^5

#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    // consumes less memory than the 2-nd version
    int equalPairs_vers1(std::vector<std::vector<int>>& grid)
    {
        unsigned counter = 0;

        std::vector<int> temp(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
                temp[j] = grid[j][i];
            for (auto& vec : grid)
                if (vec == temp)
                    counter++;
        }

        return counter;
    }

    // runs faster than the 1-st version
    // the realization after discussion on the LeetCode forum
    int equalPairs_vers2(std::vector<std::vector<int>>& grid)
    {
        unsigned counter = 0;
        std::map<std::vector<int>, int> mp;

        for (const auto& vec : grid)
            mp[vec]++;

        std::vector<int> current(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
                current[j] = grid[j][i];

            counter += mp[current];
        }

        return counter;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> grid =
    {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}
    };

    std::cout << s.equalPairs_vers2(grid) << std::endl;

    return 0;
}

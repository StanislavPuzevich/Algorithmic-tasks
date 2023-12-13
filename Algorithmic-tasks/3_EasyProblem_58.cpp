//1582. Special Positions in a Binary Matrix(Easy)
//
//--------------------------------------------------------------------
//https://leetcode.com/problems/special-positions-in-a-binary-matrix/
//--------------------------------------------------------------------
//
//Given an m x n binary matrix mat, return the number of special positions in mat.
//A position(i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0 - indexed).
//
//Example 1:
//    Input: mat = 
//    [[1, 0, 0], 
//     [0, 0, 1], 
//     [1, 0, 0]]
//    Output : 1
//    Explanation : (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
//
//Example 2 :
//    Input : mat = 
//    [[1, 0, 0], 
//     [0, 1, 0], 
//     [0, 0, 1]]
//    Output : 3
//    Explanation : (0, 0), (1, 1) and (2, 2) are special positions.
//
//Constraints :
//    m == mat.length
//    n == mat[i].length
//    1 <= m, n <= 100
//    mat[i][j] is either 0 or 1.

#include <iostream>
#include <vector>

class Solution
{
public:
    int numSpecial(std::vector<std::vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int answ = 0;

        for (int i = 0; i < m; i++)
        {
            int counter = 0;
            int pos = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    pos = j;
                    counter++;
                }
            }
            if (counter == 1)
            {
                counter = 0;
                for (int row = 0; row < m; row++)
                    if (mat[row][pos] == 1) counter++;
                if (counter == 1) answ++;
            }

        }

        return answ;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> mat =
    {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    std::cout << s.numSpecial(mat) << std::endl;

    return 0;
}

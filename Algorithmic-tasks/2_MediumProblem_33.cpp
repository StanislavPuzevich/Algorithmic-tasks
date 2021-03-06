//304. Range Sum Query 2D - Immutable
//
//------------------------------------------------------------
//https://leetcode.com/problems/range-sum-query-2d-immutable/
//------------------------------------------------------------
//
//Given a 2D matrix matrix, handle multiple queries of the following type :
//Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner(row1, col1) and lower right corner(row2, col2).
//
//Implement the NumMatrix class :
//NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
//int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper
//left corner(row1, col1) and lower right corner(row2, col2).
//
//Example 1:
//    Input
//    ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
//    [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]] ], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
//    Output
//    [null, 8, 11, 12]
//
//Explanation:
//    NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]] );
//    numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
//    numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
//    numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
//
//
//Constraints:
//    m == matrix.length
//    n == matrix[i].length
//    1 <= m, n <= 200
//    - 10^5 <= matrix[i][j] <= 10^5
//    0 <= row1 <= row2 < m
//    0 <= col1 <= col2 < n
//    At most 104 calls will be made to sumRegion.

#include <iostream>
#include <vector>

// Bruteforce(TLE) O(row*col)
// This algorithm works but does not fit in time. Suitable for small matrices
class NumMatrix_1
{
public:
    std::vector<std::vector<int>>result;

    NumMatrix_1(std::vector<std::vector<int>>& matrix)
    {
        result = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {                                                    
        int sum = 0;
        for (int i = row1; i <= row2; i++)
            for (int j = col1; j <= col2; j++)
                sum += result[i][j];

        return sum;
    }
};

// O(row)
// This algorithm is faster than the previous one, but also not perfect
class NumMatrix_2
{
public:
    std::vector<std::vector<int>>result;

    NumMatrix_2(std::vector<std::vector<int>>& matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            std::vector<int> temp;
            temp.push_back(matrix[i][0]);
            for (int j = 1; j < col; j++)
                temp.push_back(temp[j - 1] + matrix[i][j]);
            result.push_back(temp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0, minus = 0;

        for (int i = row1; i <= row2; i++)
        {
            sum += result[i][col2];
            if (col1 > 0)
                minus += result[i][col1 - 1];
        }

        return sum - minus;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    std::vector<std::vector<int>> matrix
    {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5},
    };

    NumMatrix_2 matr(matrix);
    matr.sumRegion(2, 1, 4, 3); 
    matr.sumRegion(1, 1, 2, 2); 
    matr.sumRegion(1, 2, 2, 4);

    return 0;
}
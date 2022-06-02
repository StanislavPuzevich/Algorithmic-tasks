//867. Transpose Matrix
// 
//-------------------------------------------------
// https://leetcode.com/problems/transpose-matrix/
//------------------------------------------------- 
// 
//Given a 2D integer array matrix, return the transpose of matrix.
//The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
//
//Example 1:
//    Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//    Output : [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
//
//Example 2 :
//    Input : matrix = [[1, 2, 3], [4, 5, 6]]
//    Output : [[1, 4], [2, 5], [3, 6]]
//
//Constraints :
//    m == matrix.length
//    n == matrix[i].length
//    1 <= m, n <= 1000
//    1 <= m * n <= 105
//    - 10^9 <= matrix[i][j] <= 10^9

#include <iostream>
#include <vector>


class Solution
{
public:
    std::vector<std::vector<int>> transpose_1(std::vector<std::vector<int>>& matrix)
    {
        std::vector<std::vector<int>> result (matrix[0].size(), std::vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                result[j][i] = matrix[i][j];

        return result;
    }

    // for case when N == M
    void transpose_2(std::vector<std::vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i; j < matrix[i].size(); j++)
                std::swap(matrix[i][j], matrix[j][i]);
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>>vec
    {
        {1,2,3},
        {4,5,6},
    };

    vec = s.transpose_1(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            std::cout << vec[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
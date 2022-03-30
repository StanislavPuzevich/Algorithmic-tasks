//74. Search a 2D Matrix
//
//Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.This matrix has the following properties :
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//
//Example 1:
//Input: matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 3
//Output : true
//
//Example 2 :
//Input : matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target = 13
//Output : false
//
//Constraints :
//    m == matrix.length
//    n == matrix[i].length
//    1 <= m, n <= 100
//    - 104 <= matrix[i][j], target <= 104

#include <iostream>
#include <vector>

class Solution 
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        int m = 0, n = 1, j = 0;
        while (n < matrix.size())
        {
            if (matrix[m][j] <= target && target <= matrix[n][j])
            {
                if (target == matrix[m][j] || target == matrix[n][j])
                    return true;
                else break;
            }
            m++;
            n++;
        }
  
        while (j < matrix[m].size())
        {
            if (target == matrix[m][j])
                return true;
            j++;
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>>matrix
    {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60},
    };

    std::cout << "Result: " << s.searchMatrix(matrix, 11) << std::endl;

    return 0;
}
//1572. Matrix Diagonal Sum(Easy)
//
//---------------------------------------------------- 
// https://leetcode.com/problems/matrix-diagonal-sum/
//---------------------------------------------------- 
// 
//Given a square matrix mat, return the sum of the matrix diagonals.
//Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
//
//Example 1:
//	Input: mat = [[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]]
//	Output : 25
//	Explanation : Diagonals sum : 1 + 5 + 9 + 3 + 7 = 25
//	Notice that element mat[1][1] = 5 is counted only once.
//
//Example 2 :
//	Input : mat = [[1, 1, 1, 1],
//	[1, 1, 1, 1],
//	[1, 1, 1, 1],
//	[1, 1, 1, 1]]
//	Output : 8
//
//Example 3 :
//	Input : mat = [[5]]
//	Output : 5
//
//Constraints :
//	n == mat.length == mat[i].length
//	1 <= n <= 100
//	1 <= mat[i][j] <= 100

#include <iostream>
#include <vector>

class Solution
{
public:
	int diagonalSum_vers1(std::vector<std::vector<int>>& mat) 
	{
		int sum = 0;

		for (int i = 0, j = i, ii = mat.size() - 1; i < mat.size(); i++, j++, ii--)
		{
			if (i == ii)
				sum += mat[i][j];
			else
				sum += (mat[i][j] + mat[ii][j]);
		}

		return sum;
	}

	int diagonalSum_vers2(std::vector<std::vector<int>>& mat)
	{
		int sum = 0;

		for (int i = 0; i < mat.size(); i++)
			for (int j = 0; j < mat.size(); j++)
				if (i == j || i + j == mat.size() - 1)
					sum += mat[i][j];

		return sum;
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> mat
	{
		{7, 3, 1, 9},
		{3, 4, 6, 9},
		{6, 9, 6, 6}, 
		{9, 5, 8, 5}
	};

	std::cout << s.diagonalSum_vers2(mat) << std::endl;

	return 0;
}

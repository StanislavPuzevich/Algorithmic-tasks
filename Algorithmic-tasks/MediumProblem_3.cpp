//59. Spiral Matrix II
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
//
//Constraints:
//1 <= n <= 20
 
#include <iostream>
#include <vector>
#include <iomanip> 


std::vector<std::vector<int>> generateMatrix(int n)
{
	std::vector<std::vector<int>>res(n, std::vector<int>(n));

	int k = 0, x = 1;

	while (x <= n * n)
	{
		int i = 0 + k, j = 0 + k;
		bool check = true;
		while (j < n - 1 - k)
		{
			res[i][j] = x++;
			j++;
		}
		while (i < n - 1 - k)
		{
			res[i][j] = x++;
			i++;
		}
		while (j > 0 + k)
		{
			res[i][j] = x++;
			j--;
		}
		while (i > 0 + k)
		{
			res[i][j] = x++;
			i--;
			check = false;
		}
		if (check)
			res[i][j] = x++;
		k++;
	}
	return res;
}

void showMatrix(std::vector<std::vector<int>> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
			std::cout << std::setw(5) << v[i][j];
		std::cout << std::endl << std::endl;
	}
}

int main()
{
	int n;

	std::cout << "Enter the number: ";
	std::cin >> n;

	showMatrix(generateMatrix(n));

	return 0;
}
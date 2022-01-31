//1672. Richest Customer Wealth
//You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank.
//Return the wealth that the richest customer has.
//A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
//
//Constraints:
//m == accounts.length
//n == accounts[i].length
//1 <= m, n <= 50
//1 <= accounts[i][j] <= 100
//
//Example 3:
//Input: accounts = [[2, 8, 7], [7, 1, 3], [1, 9, 5]]
//Output : 17
 
#include <iostream>
#include <vector>


int maximumWealth(std::vector<std::vector<int>>& accounts)
{
	int max_sum = 0, sum;
	for (int i = 0; i < accounts.size(); i++)
	{
		sum = 0;
		for (int j = 0; j < accounts[i].size(); j++)
			sum += accounts[i][j];
		if (sum > max_sum)
			max_sum = sum;
	}
	return max_sum;
}

int main()
{
	std::vector<std::vector<int>> accounts
	{
		{2, 8, 7},
		{7, 1, 3},
		{1, 9, 5}
	};

	std::cout << "RESULT: " << maximumWealth(accounts) << std::endl;
	
	return 0;
}

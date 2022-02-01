//121. Best Time to Buy and Sell StockY
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//You want to maximize your profit by choosing a single day to buy one stockand choosing a different day in the future to sell that stock.
//
//Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit, return 0.
 
//Constraints:
//1 <= prices.length <= 10^5
//0 <= prices[i] <= 10^4

//Example 1:
//
//Input: prices = [7, 1, 5, 3, 6, 4]
//Output : 5
//Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

//O(n)!!!

#include <iostream>
#include <vector>


int maxProfit(std::vector<int>& prices)
{
	int difference = 0, max = 0, min = 10000;

	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < min)
			min = prices[i];
		difference = prices[i] - min;
		if (difference > max)
			max = difference;
	}
	return max;
}

int main()
{
	std::vector<int> prices{ 7,1,5,3,6,4 };

	std::cout << "RESULT: " << maxProfit(prices) << std::endl;

	return 0;
}
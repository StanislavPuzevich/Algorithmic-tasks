//509. Fibonacci Number
//
//------------------------------------------------
//https://leetcode.com/problems/fibonacci-number/
//------------------------------------------------
//
//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
//such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
//
//F(0) = 0, F(1) = 1
//F(n) = F(n - 1) + F(n - 2), for n > 1.
//Given n, calculate F(n).
//
//Example 1:
//	Input: n = 2
//	Output : 1
//	Explanation : F(2) = F(1) + F(0) = 1 + 0 = 1.
//
//Example 2 :
//	Input : n = 3
//	Output : 2
//	Explanation : F(3) = F(2) + F(1) = 1 + 1 = 2.
//	
//Example 3 :
//	Input : n = 4
//	Output : 3
//	Explanation : F(4) = F(3) + F(2) = 2 + 1 = 3.
//
//Constraints :
//	0 <= n <= 30

#include <iostream>

class Solution 
{
public:
	// 1-st version of the 1-st solution using recursion
	int fib_1(int n)
	{
		if (n == 1) return 1;
		if (n == 0) return 0;
		return fib_1(n - 1) + fib_1(n - 2);
	}

	// 2-nd version(improved) of the 1-st solution using recursion
	int fib_2(int n)
	{
		if (n <= 1) return n;
		return fib_2(n - 1) + fib_2(n - 2);
	}

	// 2-nd  solution using 2 approaches
	int fib_3(int n)
	{
		if (n <= 1) return n;

		int prev = 0, result = 1;
		for (int i = 1; i < n; i++)
		{
			int temp = prev;
			prev = result;
			result = prev + temp;
		}

		return result;
	}
};

int main()
{
	Solution s;

	std::cout << "Result: " << s.fib_3(30) << std::endl;

	return 0;
}
//50. Pow(x, n)
//Implement pow(x, n), which calculates x raised to the power n(i.e., xn).
//
//Example 2:
//	Input: x = 2.10000, n = 3
//	Output : 9.26100
//
//Example 3 :
//	Input : x = 2.00000, n = -2
//	Output : 0.25000
//	Explanation : 2 ^(-2) = 1 / 2^2 = 1 / 4 = 0.25
//
//Constraints :
//	-100.0 < x < 100.0
//	- 2^31 <= n <= 2^31 - 1
//	- 10^4 <= xn <= 10^4

#include <iostream>               


double myPow(double x, int n)
{
	if (n > 0)
		return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
	else if (n < 0)
		return n % 2 == 0 ? 1 / myPow(x * x, abs(n / 2)) : 1 / (x * myPow(x * x, abs(n / 2)));
	return 1;
}


int main()                                                 
{
	std::cout << "RESULT: " << myPow(3, -5) << std::endl;
	return 0;
}

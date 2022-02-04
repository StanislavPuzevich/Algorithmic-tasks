// Pow(x, n)

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
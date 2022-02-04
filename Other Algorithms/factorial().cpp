// Факториал

#include <iostream>               

int factorial(int n)
{
	int res = n;
	for (int i = 1; i < n; i++)
		res *= i;
	return res;
}

int main()                                                 
{           
	std::cout << "RESULT: " << factorial(5)<< std::endl;
	return 0;
}
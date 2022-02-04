// Факториал

#include <iostream>               

int factorial_rec(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial_rec(n - 1);
}

int main()                                                 
{           
	std::cout << "RESULT: " << factorial_rec(11)<< std::endl;
	return 0;
}
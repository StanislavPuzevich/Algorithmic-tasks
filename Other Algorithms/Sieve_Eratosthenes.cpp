//Sieve of Eratosthenes
//search for prime numbers in the interval

#include <iostream>


int main()
{
	int const SIZE = 1000;
	int mas[SIZE] = { 0 };

	for (int i = 2; i * i < SIZE; i++)
		if (mas[i] == 0)
			for (int k = i * i; k < SIZE; k += i)
				mas[k] = 1;

	for (int i = 0; i < SIZE; i++)
		if (mas[i] == 0)
			std::cout << i << " ";
	
	return 0;
}

// Алгоритм корня квадратного sqrt() 

#include <iostream>               

int sqrt(int n)
{
	int right = n, left = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (n > mid * mid)
			left = mid + 1;
		else if (n < mid * mid)
			right = mid - 1;
		else
		{
			right = mid;
			break;
		}
	}
	return right;
}


int main()                                                 
{           
	std::cout << "RESULT: " << sqrt(1342) << std::endl;
	return 0;
}

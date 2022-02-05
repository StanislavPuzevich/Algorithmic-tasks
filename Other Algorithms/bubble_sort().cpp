// bubble sorting /bubble_sort()

#include <iostream>   
#include <Algorithm> 
#include <vector> 

void bubble_sort(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
		for (int j = i + 1; j < vec.size(); j++)
			if (vec[i] > vec[j])
				std::swap(vec[i], vec[j]);
}

int main()                                                 
{
	std::vector<int>vec{ 95, 17, 54, 80, 82, 6, 12, 78, 46, 20, 10, 51, 71, 37, 97, 90, 3, 21, 26, 70 };

	bubble_sort(vec);

	for (auto& i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
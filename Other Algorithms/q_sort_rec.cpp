// quick sorting /_sort_recursive();

#include <iostream>   
#include <Algorithm> 
#include <vector> 


size_t partition(std::vector<int>& vec, size_t left, size_t right)
{
	size_t i = left;
	size_t j = right;
	size_t mid = vec[(left + right) / 2];

	while (left <= right)
	{
		while (vec[i] < mid)
			i++;

		while (vec[j] > mid)
			j--;

		if (i >= j)
			break;

		std::swap(vec[i++], vec[j--]);
	}
	return j;
}

void q_sort_rec(std::vector<int>& vec, size_t left, size_t right)
{
	if (left < right)
	{
		auto q = partition(vec, left, right);
		q_sort_rec(vec, left, q);
		q_sort_rec(vec, q + 1, right);
	}
}

int main()                                                 
{
	std::vector<int>vec{ 95, 17, 54, 80, 82, 6, 12, 78, 46, 20, 10, 51, 71, 37, 97, 90, 3, 21, 26, 70 };

	q_sort_rec(vec, 0, vec.size() - 1);

	for (auto& i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
//1675. Minimize Deviation in Array
//
//You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times :
//
//If the element is even, divide it by 2.
//For example, if the array is[1, 2, 3, 4], then you can do this operation on the last element, and the array will be[1, 2, 3, 2].
//If the element is odd, multiply it by 2.
//For example, if the array is[1, 2, 3, 4], then you can do this operation on the first element, and the array will be[2, 2, 3, 4].
//The deviation of the array is the maximum difference between any two elements in the array.
//
//Return the minimum deviation the array can have after performing some number of operations.
//
//Example 1:
//Input: nums = [1, 2, 3, 4]
//Output : 1
//Explanation : You can transform the array to[1, 2, 3, 2], then to[2, 2, 3, 2], then the deviation will be 3 - 2 = 1.

//Example 2:
//
//Input: nums = [4, 1, 5, 20, 3]
//Output : 3
//Explanation : You can transform the array after two operations to[4, 2, 5, 5, 3], then the deviation will be 5 - 2 = 3.

#include <iostream>   
#include <vector>
#include <algorithm>
#include <queue>


int minimumDeviation(std::vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] % 2 == 1)
            nums[i] *= 2;

    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end());

    int answ = max - min;

    std::priority_queue<int>qu;

    for (int i = 0; i < nums.size(); i++)
        qu.push(nums[i]);

    while (qu.top() % 2 == 0)
    {
        int top = qu.top();
        qu.pop();

        if (answ > (top - min)) answ = top - min;

        top /= 2;

        if (min > top) min = top;

        qu.push(top);
    }

    if (answ > (qu.top() - min)) answ = qu.top() - min;

    return answ;
}


int main()
{
    std::vector<int> vec{ 399,908,648,357,693,502,331,649,596,698 };

    std::cout << minimumDeviation(vec) << std::endl;

    return 0;
}
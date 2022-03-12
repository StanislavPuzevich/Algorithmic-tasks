//167. Two Sum II - Input Array Is Sorted
//
//Given a 1 - indexed array of integers numbers that is already sorted in non - decreasing order, find two numbers such that they add up to a specific target number.
//Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
//Return the indices of the two numbers, index1and index2, added by one as an integer array[index1, index2] of length 2.
//The tests are generated such that there is exactly one solution.You may not use the same element twice.
//Your solution must use only constant extra space.
//
//Example 1:
//Input: numbers = [2, 7, 11, 15], target = 9
//Output : [1, 2]
//Explanation : The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return[1, 2].
//
//Example 2 :
//    Input : numbers = [2, 3, 4], target = 6
//    Output : [1, 3]
//    Explanation : The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return[1, 3].
//
//Constraints :
//    2 <= numbers.length <= 3 * 104
//    - 1000 <= numbers[i] <= 1000
//    numbers is sorted in non - decreasing order.
//    - 1000 <= target <= 1000
//    The tests are generated such that there is exactly one solution.

#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<int> twoSum_1(std::vector<int>& numbers, int target)   //1st solution
    {
        for (int i = 0; i < numbers.size() - 1; i++)
            for(int j = i + 1; j < numbers.size();j++)
                if (numbers[i] + numbers[j] == target)
                    return { i + 1,j + 1 };
        return {};
    }

    std::vector<int> twoSum_2(std::vector<int>& numbers, int target)   //2nd solution is FASTER
    {
        int low = 0, hight = numbers.size() - 1;

        while (low < hight)
        {
            if (numbers[low] + numbers[hight] > target)
                hight--;
            else if (numbers[low] + numbers[hight] < target)
                low++;
            else 
                return { low + 1, hight + 1 };
        }
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{ -1,0,3,5,7,9,11,13,16,19,25,37,57,80,92 };
    vec = s.twoSum_2(vec,20);

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
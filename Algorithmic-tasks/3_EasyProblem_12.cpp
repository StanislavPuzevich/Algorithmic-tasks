//338. Counting Bits
//
//Given an integer n, return an array ans of length n + 1 such that for each i(0 <= i <= n), ans[i] is the number of 
//1's in the binary representation of i.
//
//Example 2:
//Input: n = 5
//Output : [0, 1, 1, 2, 1, 2]
//Explanation :
//    0 -- > 0
//    1 -- > 1
//    2 -- > 10
//    3 -- > 11
//    4 -- > 100
//    5 -- > 101
//
//Constraints:
//0 <= n <= 105

#include <iostream>   
#include <vector>


class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        int count;
        std::vector<int> result;

        for (int i = 0; i < n + 1; i++)
        {
            count = 0;
            int d = i;
            while (d > 0)
            {
                count += d % 2;
                d /= 2;
            }
            result.push_back(count);
        }
        return result;
    }
};

int main()
{   
    Solution s;
    std::vector<int> result;
    
    result = s.countBits(8);
    for (auto i : result)
        std::cout << i << " ";

    return 0;
}
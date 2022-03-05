//202. Happy Number
//
//Write an algorithm to determine if a number n is happy.
//
//A happy number is a number defined by the following process :
//Starting with any positive integer, replace the number by the sum of the squares of its digits.
//Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//Those numbers for which this process ends in 1 are happy.
//Return true if n is a happy number, and false if not.
//
//Example 1:
//Input: n = 19
//Output : true
//Explanation :
//    12 + 92 = 82
//    82 + 22 = 68
//    62 + 82 = 100
//    12 + 02 + 02 = 1
// 
//Constraints:
//1 <= n <= 231 - 1

#include <iostream>
#include <cmath>
#include <vector>

class Solution
{
public:
    bool isHappy(int n)
    {
        std::vector<int> vec;
        int sum = 0;
        while (sum != 1)
        {
            sum = 0;
            while (n)
            {
                sum += std::pow(n % 10, 2);
                n /= 10;
            }
            if (std::find(vec.begin(), vec.end(), sum) != vec.end())
                return false;
            vec.push_back(sum);
            n = sum;
        }
        return true;
    }
};


int main()
{   
    Solution s;
    
    std::cout << "Result: " << s.isHappy(57336546) << std::endl;

    return 0;
}
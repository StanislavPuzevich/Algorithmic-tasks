//326. Power of Three
//
//----------------------------------------------
//https://leetcode.com/problems/power-of-three/
//----------------------------------------------
// 
//Given an integer n, return true if it is a power of three.Otherwise, return false.
//An integer n is a power of three, if there exists an integer x such that n == 3^x.
//
//Example 1:
//    Input: n = 27
//    Output : true
//
//Example 2 :
//    Input : n = 0
//    Output : false
//
//Example 3 :
//    Input : n = 9
//    Output : true
//
//Constraints :
//    -2^31 <= n <= 2^31 - 1

#include <iostream>
#include <sstream>
#include <vector>

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        while (n % 3 == 0 && n > 3)
            n /= 3;

        return n == 3 || n == 1;
    }
};

int main()
{
    Solution s;
    int n;

    std::cout << "Enter the n: ";
    std::cin >> n;

    std::cout << "Result: " << s.isPowerOfThree(n) << std::endl;

    return 0;
}
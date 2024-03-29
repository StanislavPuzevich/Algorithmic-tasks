﻿//263. Ugly Number
// 
//-------------------------------------------
//https://leetcode.com/problems/ugly-number/ 
//-------------------------------------------
//
//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//Given an integer n, return true if n is an ugly number.
//
//Example 1:
//Input: n = 6
//Output : true
//Explanation : 6 = 2 × 3
//
//Example 2 :
//    Input : n = 1
//    Output : true
//    Explanation : 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
//
//Example 3 :
//    Input : n = 14
//    Output : false
//    Explanation : 14 is not ugly since it includes the prime factor 7.
//
//Constraints :
//    -2^31 <= n <= 2^31 - 1

#include <iostream>

class Solution 
{
public:
    bool isUgly(int n) 
    {
        if (n == 0)return false;

        while (true)
        {
            if (n % 5 == 0) n /= 5;
            else if (n % 3 == 0) n /= 3;
            else if (n % 2 == 0) n /= 2;
            else if (n == 1) return true;
            else return false;
        }
    }
};

int main()
{
    Solution s;
    int n;

    std::cout << "Enter the number: " << std::endl;
    std::cin >> n;

    std::cout << "Result: " << s.isUgly(n) << std::endl;

    return 0;
}
//70. Climbing Stairs(Easy)
//
//------------------------------------------------ 
// https://leetcode.com/problems/climbing-stairs/
//------------------------------------------------
// 
//You are climbing a staircase.It takes n steps to reach the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Example 1 :
//    Input : n = 2
//    Output : 2
//    Explanation : There are two ways to climb to the top.
//    1. 1 step + 1 step
//    2. 2 steps
//
//Example 2 :
//    Input : n = 3
//    Output : 3
//    Explanation : There are three ways to climb to the top.
//    1. 1 step + 1 step + 1 step
//    2. 1 step + 2 steps
//    3. 2 steps + 1 step
//
//Constraints :
//    1 <= n <= 45

#include <iostream>

class Solution 
{
public:
    int climbStairs(int n) 
    {
        int first = 0;
        int second = 1;

        while (n > 0)
        {
            int temp = second;
            second += first;
            first = temp;
            n--;
        }

        return second;
    }
};

int main()
{
    Solution s;

    std::cout << s.climbStairs(45) << std::endl;

    return 0;
}

//9. Palindrome Number(Easy)
//
//--------------------------------------------------------------
// https://leetcode.com/problems/palindrome-number/description/
//-------------------------------------------------------------- 
// 
//Given an integer x, return true if x is a palindrome, and false otherwise.
//
//Example 1:
//Input: x = 121
//Output : true
//Explanation : 121 reads as 121 from left to right and from right to left.
//
//Example 2 :
//    Input : x = -121
//    Output : false
//    Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.
//
//Example 3 :
//    Input : x = 10
//    Output : false
//    Explanation : Reads 01 from right to left.Therefore it is not a palindrome.
//
//Constraints :
//    -231 <= x <= 231 - 1
//
//Follow up : Could you solve it without converting the integer to a string ?

#include <iostream>
#include <vector>

class Solution 
{
public:
    bool isPalindrome_vers1(int x) 
    {
        if (x < 0) return false;

        std::vector<int> vec;

        while (x)
        {
            vec.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0, j = vec.size() - 1; i < j; i++, j--)
            if (vec[i] != vec[j])
                return false;

        return true;
    }

    // The main loop looks difficulty, but it works
    bool isPalindrome_vers2(int x)
    {
        if (x < 0) return false;

        int count = 0;
        int temp = x;

        while (temp)
        {
            temp /= 10;
            count++;
        }

        for (int i = pow(10, count - 1), j = 10; i > j; i /= 10, j *= 10)
        {
            if (x / i % 10 != (x % j) / (j / 10))
                return false;
        }

        return true;
    }

    // The fastest and clear function
    bool isPalindrome_vers3(int x)
    {
        if (x < 0) return false;

        long temp = 0;
        int copy = x;

        while (copy)
        {
            temp *= 10;
            temp += copy % 10;
            copy /= 10;
        }

        return temp == x ? true : false;
    }
};

int main()
{
    Solution s;

    std::cout << s.isPalindrome_vers3(123454321) << std::endl;

    return 0;  
}

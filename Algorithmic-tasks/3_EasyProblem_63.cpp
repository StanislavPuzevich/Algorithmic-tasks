//1758. Minimum Changes To Make Alternating Binary String(Easy)
//
//----------------------------------------------------------------------------------
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
//----------------------------------------------------------------------------------
// 
//You are given a string s consisting only of the characters '0' and '1'.In one operation, you can change any '0' to '1' or vice versa.
//The string is called alternating if no two adjacent characters are equal.For example, the string "010" is alternating, while the string "0100" is not.
//Return the minimum number of operations needed to make s alternating.
//
//Example 1:
//    Input: s = "0100"
//    Output : 1
//    Explanation : If you change the last character to '1', s will be "0101", which is alternating.
//
//Example 2 :
//    Input : s = "10"
//    Output : 0
//    Explanation : s is already alternating.
//
//Example 3 :
//    Input : s = "1111"
//    Output : 2
//    Explanation : You need two operations to reach "0101" or "1010".
//
//Constraints :
//    1 <= s.length <= 10^4
//    s[i] is either '0' or '1'.

#include <iostream>
#include <algorithm>

class Solution
{
public:
    int minOperations(const std::string& s)
    {
        int minOperFirst = 0;
        for (int i = 0; i < s.length(); i++)
            if (i % 2 && s[i] == '1' || !(i % 2) && s[i] == '0')
                minOperFirst++;

        int minOperSecond = 0;
        for (int i = 0; i < s.length(); i++)
            if (i % 2 && s[i] == '0' || !(i % 2) && s[i] == '1')
                minOperSecond++;

        return minOperFirst < minOperSecond ? minOperFirst : minOperSecond;
    }

    int minOperations_vers2(const std::string& s) // Solution after reading forum LeetCode
    {
        int cost10 = 0;

        for (int i = 0; i < s.length(); i++)
            if (s[i] - '0' == i % 2)
                cost10++;

        int cost01 = s.length() - cost10;

        return  std::min(cost10, cost01); 
    }
};

int main()
{
    Solution s;
    std::string str = "100000011110111100";

    std::cout << s.minOperations_vers2(str) << std::endl;

    return 0;
}

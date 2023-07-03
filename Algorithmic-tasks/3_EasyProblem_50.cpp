//859. Buddy Strings(Easy)
//
//---------------------------------------------- 
// https://leetcode.com/problems/buddy-strings/
//---------------------------------------------- 
// 
//Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
//Swapping letters is defined as taking two indices i and j(0 - indexed) such that i != j and swapping the characters at s[i] and s[j].
//For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
//
//Example 1:
//    Input: s = "ab", goal = "ba"
//    Output : true
//    Explanation : You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
//
//Example 2 :
//    Input : s = "ab", goal = "ab"
//    Output : false
//    Explanation : The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
//
//Example 3 :
//    Input : s = "aa", goal = "aa"
//    Output : true
//    Explanation : You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
//
//Constraints :
//    1 <= s.length, goal.length <= 2 * 10^4
//    s and goal consist of lowercase letters.

#include <iostream>
#include <algorithm>

class Solution 
{
public:
    bool buddyStrings(std::string s, std::string goal) 
    {
        char first;
        int pos;
        bool counter = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                if (!counter)
                {
                    first = s[i];
                    counter = true;
                    pos = i;
                }
                else
                {
                    char temp = s[i];
                    s[i] = first;
                    s[pos] = temp;

                    return s == goal ? true : false;
                }
            }
        }

        if (!counter)
        {
            std::sort(s.begin(), s.end());
            for (int i = 1; i < s.length(); i++)
                if (s[i] == s[i - 1])
                    return true;
        }

        return false;
    }
};

int main()
{
    Solution s;

    std::cout << s.buddyStrings("abcd", "abed") << std::endl;

    return 0;
}

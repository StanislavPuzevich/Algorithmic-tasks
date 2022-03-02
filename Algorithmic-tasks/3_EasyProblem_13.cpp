//392. Is Subsequence
//
//Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//A subsequence of a string is a new string that is formed from the original string by deleting some(can be none) of the characters
//without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//
//Example 1:
//Input: s = "abc", t = "ahbgdc"
//Output : true

//Constraints:
//0 <= s.length <= 100
//0 <= t.length <= 104
//s and t consist only of lowercase English letters.

#include <iostream>   

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        if (s.empty()) return true;
        char* p1 = &s[0], * p2 = &t[0];
        bool check = false;
        while (*p1 != '\0' && *p2 != '\0')
        {
            if (*p1 == *p2)
            {
                p1++;
                check = true;
            }
            else check = false;
            p2++;
        }
        if (*p1 != '\0')
            return false;
        return check;
    }
};

int main()
{   
    Solution sol;
    std::string s = "abcg";
    std::string t = "ahbgdc";
    
    std::cout << "Result: " << sol.isSubsequence(s, t) << std::endl;

    return 0;
}
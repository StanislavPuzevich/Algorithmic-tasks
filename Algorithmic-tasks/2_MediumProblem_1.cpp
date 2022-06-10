//3. Longest Substring Without Repeating Characters
//
//------------------------------------------------------------------------------
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//------------------------------------------------------------------------------
//
//Given a string s, find the length of the longest substring without repeating characters.
//
//Example 1:
//    Input: s = "abcabcbb"
//    Output : 3
//    Explanation : The answer is "abc", with the length of 3.
//
//Example 2 :
//    Input : s = "bbbbb"
//    Output : 1
//    Explanation : The answer is "b", with the length of 1.
//
//Example 3 :
//    Input : s = "pwwkew"
//    Output : 3
//    Explanation : The answer is "wke", with the length of 3.
//    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//Constraints :
//    0 <= s.length <= 5 * 10^4
//    s consists of English letters, digits, symbolsand spaces.

#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring_2(std::string s)  // 2nd version 10.06.2022
    {
        int max = 0;
        std::string str;

        for (char i : s)
        {
            if (str.find(i) == -1)
                str += i;
            else
            {
                max = std::max(max, (int)str.length());
                str.erase(0, str.find(i) + 1);
                str += i;
            }
        }

        return max > str.length() ? max : str.length();
    }
	
    int lengthOfLongestSubstring_1(std::string s)   // 1st version 28.01.2022
    {
        int max = 0, count = 0;
        std::string res;

        for (int i = 0; i < s.length(); i++)
        {
            if (res.find(s[i]) == -1)
            {
                res += s[i];
                count++;
                if (count > max)
                    max = count;
            }
            else
            {
                res.erase(res.begin(), res.begin() + res.find(s[i]) + 1);
                res += s[i];
                count = res.length();
            }
        }
        return max;
    }
};

int main()
{
    Solution s;

    std::cout << s.lengthOfLongestSubstring_2("pwwkew") << std::endl;

    return 0;
}

//14. Longest Common Prefix(Easy)
//
//------------------------------------------------------------------ 
// https://leetcode.com/problems/longest-common-prefix/description/ 
//------------------------------------------------------------------ 
// 
//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".
//
//Example 1:
//    Input: strs = ["flower", "flow", "flight"]
//    Output : "fl"
//
//Example 2 :
//    Input : strs = ["dog", "racecar", "car"]
//    Output : ""
//    Explanation : There is no common prefix among the input strings.
//
//Constraints :
//    1 <= strs.length <= 200
//    0 <= strs[i].length <= 200
//    strs[i] consists of only lowercase English letters.

#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    std::string longestCommonPrefix_vers1(std::vector<std::string>& strs) 
    {
        std::string res;
        
        std::sort(strs.begin(), strs.end(), [](auto& first, auto& second) {return first.length() < second.length(); });

        for (int j = 0; j < strs[0].length(); j++)
        {
            char ch = strs[0][j];

            for (auto i : strs)
                if (i[j] != ch)
                    return res;

            res += ch;
        }

        return res;
    }

    // this function was written after discussing on the forum
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        std::string res;

        std::sort(strs.begin(), strs.end());

        auto first_str = *(strs.begin());
        auto last_str = *(strs.end() - 1);

        for (int i = 0; i < first_str.length(); i++)
        {
            if (first_str[i] != last_str[i]) break;
            res += last_str[i];
        }

        return res;
    }
};

int main()
{
    Solution s;

    std::vector<std::string> vec{ "racecar","rac"};

    std::cout << s.longestCommonPrefix(vec) << std::endl;

    return 0;  
}

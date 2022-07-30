//916. Word Subsets
//
//-------------------------------------------- 
//https://leetcode.com/problems/word-subsets/ 
//-------------------------------------------- 
// 
//You are given two string arrays words1 and words2.
//A string b is a subset of string a if every letter in b occurs in a including multiplicity.
//For example, "wrr" is a subset of "warrior" but is not a subset of "world".
//A string a from words1 is universal if for every string b in words2, b is a subset of a.
//Return an array of all the universal strings in words1.You may return the answer in any order.
//
//Example 1:
//    Input: words1 = ["amazon", "apple", "facebook", "google", "leetcode"], words2 = ["e", "o"]
//    Output : ["facebook", "google", "leetcode"]
//
//Example 2 :
//    Input : words1 = ["amazon", "apple", "facebook", "google", "leetcode"], words2 = ["l", "e"]
//    Output : ["apple", "google", "leetcode"]
//
//Constraints :
//    1 <= words1.length, words2.length <= 10^4
//    1 <= words1[i].length, words2[i].length <= 10
//    words1[i] and words2[i] consist only of lowercase English letters.
//    All the strings of words1 are unique.

#include <iostream>
#include <vector>

class Solution          // 1st solution, but it's quite slow
{
private:
    bool helper(std::string s1, std::string s2)
    {
        for (char ch : s2)
        {
            if (s1.find(ch) == std::string::npos)
                return false;
            else s1.erase(s1.find(ch), 1);
        }

        return true;
    }

public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) 
    {
        std::vector<std::string> result;
        bool check;

        for (std::string s1 : words1)
        {
            check = true;
            for (std::string s2 : words2)
            {
                if (!helper(s1, s2))
                {
                    check = false;
                    break;
                }
            }
            if (check) result.push_back(s1);
        }

        return result;
    }
};

class Solution2         // 2nd solution is mach faster
{
public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2)
    {
        std::vector<std::string> result;

        std::vector<int> res_w2(26, 0);
        for (std::string s2 : words2)
        {
            std::vector<int> temp(26, 0);
            for (char ch : s2)
            {
                temp[ch - 'a']++;
                res_w2[ch - 'a'] = std::max(res_w2[ch - 'a'], temp[ch - 'a']);
            }
        }

        bool check;
        for (std::string s1 : words1)
        {
            check = true;
            std::vector<int> str(26, 0);

            for (char ch : s1)
                str[ch - 'a']++;

            for (int i = 0; i < str.size(); i++)
                if (res_w2[i] > str[i])
                {
                    check = false;
                    break;
                }

            if (check) result.push_back(s1);
        }

        return result;
    }
};

int main()
{
    Solution2 s;
    std::vector<std::string> vec1 = { "amazon", "apple", "facebook", "google", "leetcode" };
    std::vector<std::string> vec2 = { "l", "e" };
    std::vector<std::string> res = s.wordSubsets(vec1, vec2);

    std::cout << "Result: " << std::endl;
    for (std::string str : res)
        std::cout << str << '\t';
    std::cout << std::endl;

    return 0;
}
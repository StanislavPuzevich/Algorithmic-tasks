//890. Find and Replace Pattern
//
//---------------------------------------------------------
//https://leetcode.com/problems/find-and-replace-pattern/
//---------------------------------------------------------
// 
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern.You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x),
//we get the desired word. 
//Recall that a permutation of letters is a bijection from letters to letters : every letter maps to another letter,
//and no two letters map to the same letter.
//
//Example 1 :
//    Input : words = ["abc", "deq", "mee", "aqq", "dkd", "ccc"], pattern = "abb"
//    Output : ["mee", "aqq"]
//    Explanation : "mee" matches the pattern because there is a permutation{ a->m, b->e, ... }.
//    "ccc" does not match the pattern because{ a->c, b->c, ... } is not a permutation, since a and b map to the same letter.
//
//Example 2 :
//    Input : words = ["a", "b", "c"], pattern = "a"
//    Output : ["a", "b", "c"]
//
//Constraints :
//    1 <= pattern.length <= 20
//    1 <= words.length <= 50
//    words[i].length == pattern.length
//    pattern and words[i] are lowercase English letters.

#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution 
{
public:
    // This problem was solved after a small hint found on the internet
    std::vector<int> helper(std::string str)
    {
        std::vector<int> vec;
        std::unordered_map<char, int> mp;

        int ind = 0;
        for (char ch : str)
        {
            if (mp.find(ch) == mp.end())
            {
                mp.insert({ ch,ind++ });
                vec.push_back(mp[ch]);
            }
            else
                vec.push_back(mp[ch]);
        }

        return vec;
    }

    std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) 
    {
        std::vector<std::string> result;
        std::vector<int> patt = helper(pattern);

        for (std::string str : words)
        {
            std::vector<int> temp = helper(str);
            if (patt == temp)
                result.push_back(str);
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> words = { "abc","deq","mee","aqq","dkd","ccc" };
    std::vector<std::string> result;
    std::string pattern = "abb";

    result = s.findAndReplacePattern(words, pattern);
    std::cout << "Result:" << std::endl;
    for (std::string str : result)
        std::cout << str << '\t';

    return 0;
}
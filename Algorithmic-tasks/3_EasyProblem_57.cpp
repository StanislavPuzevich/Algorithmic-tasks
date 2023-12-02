//1160. Find Words That Can Be Formed by Characters(Easy)
//
//---------------------------------------------------------------------------- 
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
//---------------------------------------------------------------------------- 
// 
//You are given an array of strings words and a string chars.
//
//A string is good if it can be formed by characters from chars(each character can only be used once).
//
//Return the sum of lengths of all good strings in words.
//
//Example 1:
//    Input: words = ["cat", "bt", "hat", "tree"], chars = "atach"
//    Output : 6
//    Explanation : The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
//
//Example 2 :
//    Input : words = ["hello", "world", "leetcode"], chars = "welldonehoneyr"
//    Output : 10
//    Explanation : The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
//
//Constraints :
//    1 <= words.length <= 1000
//    1 <= words[i].length, chars.length <= 100
//    words[i] and chars consist of lowercase English letters.

#include <iostream>
#include <unordered_map>

class Solution
{
public:
    int countCharacters(const std::vector<std::string>& words, const std::string& chars)
    {
        bool is_good;
        int counter = 0;
        std::unordered_map<char, int> ump;

        for (const auto ch : chars)
            ump[ch]++;

        for (const auto str : words)
        {
            is_good = true;
            std::string temp = "";
            for (const auto ch : str)
            {
                if (ump[ch] == 0)
                {
                    is_good = false;
                    break;
                }

                temp += ch;
                ump[ch]--;
            }

            for (const auto ch : temp)
                    ump[ch]++;

            if (is_good)
                counter += temp.length();

            temp.clear();
        }

        return counter;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> words = { "hello","world","leetcode" };
    std::string chars = "welldonehoneyr";

    std::cout << s.countCharacters(words, chars) << std::endl;

    return 0;
}

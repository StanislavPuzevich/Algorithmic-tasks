//49. Group Anagrams
//
//Given an array of strings strs, group the anagrams together.You can return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically 
//using all the original letters exactly once.
//
//Example 1:
//Input: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//Output : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
//
//Constraints :
//    1 <= strs.length <= 104
//    0 <= strs[i].length <= 100
//    strs[i] consists of lowercase English letters.

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution 
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::map<std::string, std::vector<std::string>> hashes;

        for (int i = 0; i < strs.size(); i++)
        {
            std::string temp = strs[i];
            sort(temp.begin(), temp.end());
            hashes[temp].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> result;

        for (auto i : hashes)
            result.push_back(i.second);

        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> str{ "eat","tea","tan","ate","nat","bat" };
    std::vector<std::vector<std::string>>res;

    res = s.groupAnagrams(str);
    for (auto i : res)
    {
        for (auto j : i)
            std::cout << j;
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
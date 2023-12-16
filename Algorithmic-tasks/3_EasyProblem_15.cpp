//242. Valid Anagram(Easy)
//
//----------------------------------------------
// https://leetcode.com/problems/valid-anagram/
//---------------------------------------------- 
// 
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//
//Example 1:
//    Input: s = "anagram", t = "nagaram"
//    Output : true
//
//Example 2 :
//    Input : s = "rat", t = "car"
//    Output : false
//
//Constraints :
//    1 <= s.length, t.length <= 5 * 10^4
//    s and t consist of lowercase English letters.
//
//Follow up : What if the inputs contain Unicode characters ? How would you adapt your solution to such a case ?

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

class Solution 
{
public:
    bool isAnagram(std::string s, std::string t) // faster solution 16/12/23
    {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, int> ump1;
        std::unordered_map<char, int> ump2;
        for (int i = 0; i < s.length(); i++)
        {
            ump1[s[i]]++;
            ump2[t[i]]++;
        }

        return ump1 == ump2;
    }

    bool method4_isAnagram(std::string s, std::string t) // 28.07.2022 MAX short solution!
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        
        return s == t;
    }
    
    bool method1_isAnagram(std::string s, std::string t) // 07.03.2022 Runtime:6-8ms  USING VECTOR
    {
        std::vector<int>vec1(26, 0);
        std::vector<int>vec2(26, 0);

        for (int i = 0; i < s.length(); i++)
            vec1[(int)s[i] - 'a']++;

        for (int i = 0; i < t.length(); i++)
            vec2[(int)t[i] - 'a']++;

        if (vec1 == vec2)
            return true;
        return false;
    }

    bool method2_isAnagram(std::string s, std::string t) // 07.03.2022 Runtime:22-32ms   USING SORT
    {
        std::vector<char> vec1;
        std::vector<char> vec2;

        for (int i = 0; i < s.length(); i++)
            vec1.push_back(s[i]);

        for (int i = 0; i < t.length(); i++)
            vec2.push_back(t[i]);

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        if (vec1 == vec2)
            return true;
        return false;
    }

    bool method3_isAnagram(std::string s, std::string t) // 07.03.2022 Runtime:18-24ms   USING MAP
    {
        if (s.length() != t.length()) return false;

        std::map<char, int> mp1;
        std::map<char, int> mp2;

        for (auto i : s)
            mp1[i]++;

        for (auto i : t)
            mp2[i]++;

        for (auto i : s)
            if (mp1[i] != mp2[i])
                return false;
        return true;
    }
};

int main()
{   
    Solution s;
    
    std::cout << "Result: " << s.method1_isAnagram("anagram", "nagaram") << std::endl
        << s.method2_isAnagram("anagram", "nagaram") << std::endl
        << s.method3_isAnagram("anagram", "nagaram") << std::endl;

    return 0;
}

//567. Permutation in String
//
//Given two strings s1and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
//
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output : true
//Explanation : s2 contains one permutation of s1("ba").
//
//Example 2 :
//Input : s1 = "ab", s2 = "eidboaoo"
//Output : false
//
//Constraints :
//   1 <= s1.length, s2.length <= 104
//   s1 and s2 consist of lowercase English letters.

#include <iostream>   
#include <vector> 
#include <string>


bool checkInclusion(std::string s1, std::string s2)
{
    size_t lenght = s1.length();
    if (lenght > s2.length()) return false;

    std::vector<int>v1(26, 0), v2(26, 0);

    for (size_t i = 0; i < lenght; i++)
    {
        v1[s1[i] - 'a']++;
        v2[s2[i] - 'a']++;
    }

    if (v1 == v2) return true;

    for (size_t i = lenght; i < s2.length(); i++)
    {
        v2[s2[i - lenght] - 'a']--;
        v2[s2[i] - 'a']++;

        if (v1 == v2) return true;
    }
    return false;
}


int main()                                                 
{
    std::string s1, s2;

    std::cout << "Enter 2 string:" << std::endl;
    getline(std::cin, s1);
    getline(std::cin, s2);

    std::cout << checkInclusion(s1, s2) << std::endl;

	return 0;
}
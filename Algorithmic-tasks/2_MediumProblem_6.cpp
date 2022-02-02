//438. Find All Anagrams in a String
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

//Constraints:
//
//1 <= s.length, p.length <= 3 * 104
//s and p consist of lowercase English letters.
//
//Example 1 :
//
//	Input : s = "cbaebabacd", p = "abc"
//	Output : [0, 6]
//	Explanation :
//	The substring with start index = 0 is "cba", which is an anagram of "abc".
//	The substring with start index = 6 is "bac", which is an anagram of "abc".

#include <iostream>       
#include <string>          
#include <vector> 
#include <stack>
                         

class Solution
{
public:
	std::vector<int> findAnagrams(std::string s, std::string p)
	{
		if (s.length() < p.length())return{};

		std::vector<int>temp1(26, 0), temp2(26, 0);

		for (size_t i = 0; i < p.length(); i++)
		{
			temp1[s[i] - 'a']++;
			temp2[p[i] - 'a']++;
		}

		std::vector<int>res;
		if (temp1 == temp2) res.push_back(0);

		for (size_t i = p.length(); i < s.length(); i++)
		{
			temp1[s[i - p.length()] - 'a']--;
			temp1[s[i] - 'a']++;

			if (temp2 == temp1) res.push_back(i - p.length() + 1);
		}
		return res;
	}
};


int main()                                                 
{             
	Solution s;
	std::string str, str2;
	std::vector<int>res;
													
	std::cout << "Enter the 1st string: " << std::endl;      
	getline(std::cin, str);           

	std::cout << "Enter the 2nd string: " << std::endl;
	getline(std::cin, str2);

	res = s.findAnagrams(str, str2);

	for (auto& i : res)
		std::cout << i << " ";

	return 0;
}
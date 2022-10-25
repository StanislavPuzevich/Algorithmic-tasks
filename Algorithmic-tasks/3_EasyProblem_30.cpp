//1662. Check If Two String Arrays are Equivalent
//
//-------------------------------------------------------------------------
//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
//-------------------------------------------------------------------------
//
//Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
//A string is represented by an array if the array elements concatenated in order forms the string.
//
//Example 1:
//	Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
//	Output : true
//
//Explanation :
//	word1 represents string "ab" + "c" -> "abc"
//	word2 represents string "a" + "bc" -> "abc"
//	The strings are the same, so return true.
//
//Example 2 :
//	Input : word1 = ["a", "cb"], word2 = ["ab", "c"]
//	Output : false
//
//Example 3 :
//	Input : word1 = ["abc", "d", "defg"], word2 = ["abcddefg"]
//	Output : true
//
//Constraints :
//	1 <= word1.length, word2.length <= 10^3
//	1 <= word1[i].length, word2[i].length <= 10^3
//	1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
//	word1[i] and word2[i] consist of lowercase letters.

#include <iostream>
#include <vector>

class Solution 
{
public:
	bool arrayStringsAreEqual_1(std::vector<std::string>& word1, std::vector<std::string>& word2)
	{
		std::string s1, s2;

		for (auto i : word1) s1 += i;
		for (auto i : word2) s2 += i;

		return s1 == s2;
	}

	bool arrayStringsAreEqual_2(std::vector<std::string>& word1, std::vector<std::string>& word2)
	{
		std::string s1;

		for (auto i : word1) s1 += i;
		
		int n = 0;
		for (auto i : word2)
			for (auto j : i)
			{
				if (s1[n] != j)
					return false;
				n++;
			}

		if (n < s1.length()) return false;

		return true;
	}
};

int main()
{
	Solution s;
	std::vector<std::string> str1{ {"abc"}, {"d"}, {"defg"} };
	std::vector<std::string> str2{ {"abcddef"} };

	s.arrayStringsAreEqual_1(str1, str2);
	
	return 0;
}
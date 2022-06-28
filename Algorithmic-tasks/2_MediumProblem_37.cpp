//1647. Minimum Deletions to Make Character Frequencies Unique
//
//--------------------------------------------------------------------------------------
//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
//--------------------------------------------------------------------------------------
//
//A string s is called good if there are no two different characters in s that have the same frequency.
//
//Given a string s, return the minimum number of characters you need to delete to make s good.
//
//The frequency of a character in a string is the number of times it appears in the string.For example, in the string "aab",
//the frequency of 'a' is 2, while the frequency of 'b' is 1.
//
//Example 1: 
//	Input: s = "aab"
//	Output : 0
//	Explanation : s is already good.
//
//Example 2 :
//	Input : s = "aaabbbcc"
//	Output : 2
//	Explanation : You can delete two 'b's resulting in the good string "aaabcc".
//	Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
//
//Example 3 :
//	Input : s = "ceabaacb"
//	Output : 2
//	Explanation : You can delete both 'c's resulting in the good string "eabaab".
//	Note that we only care about characters that are still in the string at the end(i.e.frequency of 0 is ignored).
//
//Constraints :
//	1 <= s.length <= 10^5
//	s contains only lowercase English letters.

#include <iostream>
#include <queue>
#include <algorithm>

class Solution
{
public:
	int minDeletions(std::string s)   // It's not the best solution.
	{
		std::priority_queue<int> sizes;
		std::sort(s.begin(), s.end());

		char *p1 = &s[0], *p2 = &s[1];
		int count = 1, res = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (*p1 == *p2)
			{
				count++;
				p2++;
			}
			else
			{
				sizes.push(count);
				count = 1;
				p1 = p2++;
			}
		}

		int temp;
		while (sizes.size() != 1)
		{
			temp = sizes.top();
			sizes.pop();
			if (temp == sizes.top())
			{
				temp--;
				if (temp)
					sizes.push(temp);
				res++;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;

	std::cout << s.minDeletions("abcabc") << std::endl;
	
	return 0;
}

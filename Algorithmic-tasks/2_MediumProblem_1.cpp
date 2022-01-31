/*3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

 
#include <iostream>
#include <string>

int lengthOfLongestSubstring(std::string s)
{
	int max = 0, count = 0;
	std::string res;

	for (int i = 0; i < s.length(); i++)
	{
		if (res.find(s[i]) == -1)
		{
			res += s[i];
			count++;
			if (count > max)
				max = count;
		}
		else
		{
			res.erase(res.begin(), res.begin() + res.find(s[i]) + 1);
			res += s[i];
			count = res.length();
		}
	}
	return max;
}

int main()
{
	std::string s;

	std::cout << "Enter the string: ";
	getline(std::cin, s);

	std::cout << "RESULT: " << lengthOfLongestSubstring(s) << std::endl;

	return 0;
}

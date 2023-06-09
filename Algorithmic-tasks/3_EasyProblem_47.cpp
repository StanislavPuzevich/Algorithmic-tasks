//744. Find Smallest Letter Greater Than Target(Easy)
//
//------------------------------------------------------------------------- 
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
//------------------------------------------------------------------------- 
// 
//You are given an array of characters letters that is sorted in non - decreasing order, and a character target.There are at least two different characters in letters.
//Return the smallest character in letters that is lexicographically greater than target.If such a character does not exist, return the first character in letters.
//
//Example 1:
//    Input: letters = ["c", "f", "j"], target = "a"
//    Output : "c"
//    Explanation : The smallest character that is lexicographically greater than 'a' in letters is 'c'.
//
//Example 2 :
//    Input : letters = ["c", "f", "j"], target = "c"
//    Output : "f"
//    Explanation : The smallest character that is lexicographically greater than 'c' in letters is 'f'.
//
//Example 3 :
//    Input : letters = ["x", "x", "y", "y"], target = "z"
//    Output : "x"
//    Explanation : There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
//
//Constraints :
//    2 <= letters.length <= 10^4
//    letters[i] is a lowercase English letter.
//    letters is sorted in non - decreasing order.
//    letters contains at least two different characters.
//    target is a lowercase English letter.

#include <iostream>
#include <vector>

class Solution 
{
public:
    // the most compact and understandable realization
    char nextGreatestLetter_vers1(std::vector<char>& letters, char target) 
    {
        for (auto ch : letters)
            if (ch > target)
                return ch;

        return *letters.begin();
    }

    char nextGreatestLetter_vers2(std::vector<char>& letters, char target)
    {
        if (letters[letters.size() - 1] >= target)
            for (auto ch : letters)
                if (ch > target)
                    return ch;

        return *letters.begin();
    }

    // the fastest realization
    char nextGreatestLetter_vers3(std::vector<char>& letters, char target)
    {
        if (letters[letters.size() - 1] >= target || letters[0] <= target)
        {
            int i = 0;
            int j = letters.size() - 1;

            while (i <= j)
            {
                int mid = (i + j) / 2;
                if (mid > 0 && letters[mid] > target && letters[mid - 1] <= target) return letters[mid];
                else if (letters[mid] > target) j = mid - 1;
                else i = mid + 1;
            }
        }

        return *letters.begin();
    }
};

int main()
{
    Solution s;

    std::vector letters = { 'a','b','c','d','e','f','g','h','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    std::cout << s.nextGreatestLetter_vers3(letters, 'a') << std::endl;

    return 0;
}

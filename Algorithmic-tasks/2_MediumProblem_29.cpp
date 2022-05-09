//17. Letter Combinations of a Phone Number
//
//Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.
//Return the answer in any order.
//A mapping of digit to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.
//
//Example 1:
//    Input: digits = "23"
//    Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//
//Example 2 :
//    Input : digits = ""
//    Output : []
//
//Example 3 :
//    Input : digits = "2"
//    Output : ["a", "b", "c"]
//
//Constraints :
//    0 <= digits.length <= 4
//    digits[i] is a digit in the range['2', '9'].

#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::vector<std::string> result;
        if (digits.length() == 0)return result;
        else if (digits.length() == 1)
        {
            switch (digits[0])
            { 
            case '2': return { "a","b","c" };
            case '3': return { "d","e","f" };
            case '4': return { "g","h","i" };
            case '5': return { "j","k","l" };
            case '6': return { "m","n","o" };
            case '7': return { "p","q","r","s" };
            case '8': return { "t","u","v" };
            case '9': return { "w","x","y","z" };
            default: return result;
            }
        }
        else
        {
            std::vector<std::string> temp1 = letterCombinations(digits.substr(0, 1));
            std::vector<std::string> temp2 = letterCombinations(digits.substr(1, digits.length() - 1));
            for (auto i : temp1)
                for (auto j : temp2)
                    result.push_back(i + j);
        }

        return result;
    }
};

int main()
{
    Solution s;

    std::vector<std::string> result = s.letterCombinations("234");

    std::cout << "Result: " << std::endl;
    for (auto i : result)
        std::cout << i << '\t';
    std::cout << std::endl;

    return 0;
}

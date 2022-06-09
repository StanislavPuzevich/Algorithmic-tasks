//22. Generate Parentheses
//
//----------------------------------------------------
//https://leetcode.com/problems/generate-parentheses/
//----------------------------------------------------
//
//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//Example 1:
//    Input: n = 3
//    Output : ["((()))", "(()())", "(())()", "()(())", "()()()"]
//
//Example 2 :
//    Input : n = 1
//    Output : ["()"]
//
//Constraints :
//    1 <= n <= 8


#include <iostream>
#include <vector>
#include <string>

class Solution 
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> result;
        std::string str;
        solve_function(result, str, n, 0, 0);

        return result;
    }

    void solve_function(std::vector<std::string>& res, std::string& str, int n, int left_br, int right_br)
    {
        if (right_br > left_br || left_br > n || right_br > n) return;

        if (str.length() == n * 2)
        {
            res.push_back(str);
            return;
        }

        str += '(';
        solve_function(res, str, n, left_br + 1, right_br);
        str.pop_back();

        str += ')';
        solve_function(res, str, n, left_br, right_br + 1);
        str.pop_back();
    }
};

int main()
{
    Solution s;
    std::vector<std::string> result;

    result = s.generateParenthesis(8);
    for (std::string i : result)
        std::cout << i << std::endl;
    std::cout << std::endl;

    return 0;
}
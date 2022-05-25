//32. Longest Valid Parentheses
//
//--------------------------------------------------------
//https://leetcode.com/problems/longest-valid-parentheses/
//--------------------------------------------------------
//
//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//Example 1:
//    Input: s = "(()"
//    Output : 2
//    Explanation : The longest valid parentheses substring is "()".
//
//Example 2 :
//    Input : s = ")()())"
//    Output : 4
//    Explanation : The longest valid parentheses substring is "()()".
//
//Example 3 :
//    Input : s = ""
//    Output : 0
//
//Constraints :
//    0 <= s.length <= 3 * 10^4
//    s[i] is '(', or ')'.

#include <iostream>
#include <string>
#include <stack>
#include <vector>


class Solution
{
public:
    int longestValidParentheses_1(std::string s)    // 1-st solution
    {
        std::vector<int> vec1;
        std::vector<char> vec2;
        vec1.push_back(-1);
        vec2.push_back('.');

        int i = 0, max = 0;

        while (i < s.length())
        {
            vec1.push_back(i);
            vec2.push_back(s[i]);

            if ((s[i] == ')') && (std::find(vec2.begin(), vec2.end(), '(') != vec2.end()))
            {
                int temp = vec1[vec1.size() - 1] - vec1[vec1.size() - 3];
                max = std::max(temp, max);
                vec1.erase(vec1.end() - 2, vec1.end());
                vec2.erase(vec2.end() - 2, vec2.end());
            }
            i++;
        }

        return max;
    }

    int longestValidParentheses_2(std::string s)    // 2-nd solution after analyzing the example on the Internet
    {
        int max = 0, top = -1;
        std::stack<int> st;
        st.push(top);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty()) st.push(i);
                else max = std::max(max, (i - st.top()));
            }
        }
        return max;
    }
};


int main()
{
    Solution s;
   
    std::cout << "Result: " << s.longestValidParentheses_1(")()())") << std::endl;

    return 0;
}
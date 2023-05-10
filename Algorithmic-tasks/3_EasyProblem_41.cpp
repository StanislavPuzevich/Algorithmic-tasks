//20. Valid Parentheses(Easy)
// 
//-------------------------------------------------------------- 
// https://leetcode.com/problems/valid-parentheses/description/
//-------------------------------------------------------------- 
//
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
//
//Example 1:
//	Input: s = "()"
//	Output : true
//
//Example 2 :
//
//	Input : s = "()[]{}"
//	Output : true
//
//Example 3 :
//	Input : s = "(]"
//	Output : false
//
//Constraints :
//	1 <= s.length <= 10^4
//	s consists of parentheses only '()[]{}'.

#include <iostream>
#include <stack>

class Solution 
{
public:
	bool isValid_vers1(std::string s) 
	{
		std::stack<char> st;

		for (auto& i : s)
		{
			if (i == '(' || i == '{' || i == '[')
				st.push(i);
			else if (st.empty()) return false;
			else
			{
				switch (i)
				{ 
				case ')': 
					if (st.top() == '(') { st.pop(); break; }
					else return false;
				case '}':
					if (st.top() == '{') { st.pop(); break; }
					else return false;
				case ']':
					if (st.top() == '[') { st.pop(); break; }
					else return false;
				}
			}
		}

		return st.empty();
	}

	//more understandable
	bool isValid_vers2(std::string s)
	{
		std::stack<char> st;

		for (auto& i : s)
		{
			switch (i)
			{
			case '(': st.push(')'); break;
			case '{': st.push('}'); break;
			case '[': st.push(']'); break;

			case ')':
			case '}':
			case ']':
				if (st.empty() || st.top() != i) return false;
				st.pop();
				break;
			}
		}

		return st.empty();
	}
};

int main()
{
	Solution s;
	
	std::cout << s.isValid_vers2("()") << std::endl;
	std::cout << s.isValid_vers2("]") << std::endl;
	std::cout << s.isValid_vers2("()[[]]{{(})}") << std::endl;

	return 0;
}

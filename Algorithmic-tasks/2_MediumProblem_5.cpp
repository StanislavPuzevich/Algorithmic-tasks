//8. String to Integer(atoi)
//Implement the myAtoi(string s) function, which converts a string to a 32 - bit signed integer(similar to C / C++'s atoi function).
//
//The algorithm for myAtoi(string s) is as follows :
//1. Read inand ignore any leading whitespace.
//2. Check if the next character(if not already at the end of the string) is '-' or '+'.Read this character in if it is either.This determines if the final 
//result is negative or positive respectively.Assume the result is positive if neither is present.
//3. Read in next the characters until the next non - digit character or the end of the input is reached.The rest of the string is ignored.
//4. Convert these digits into an integer(i.e. "123" -> 123, "0032" -> 32).If no digits were read, then the integer is 0. 
//Change the sign as necessary(from step 2).
//5. If the integer is out of the 32 - bit signed integer range[-2^31, 2^31 - 1], then clamp the integer so that it remains in the range.Specifically, 
//integers less than - 2^31 should be clamped to - 2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
//5. Return the integer as the final result.
//
//Note:
//Only the space character ' ' is considered a whitespace character.
//Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
//
//Constraints :
//	0 <= s.length <= 200
//	s consists of English letters(lower - caseand upper - case), digits(0 - 9), ' ', '+', '-', and '.'.

//Example 1:
// Input: s = "42"
// Output : 42
// Explanation : The underlined characters are what is read in, the caret is the current reader position.
// Step 1 : "42" (no characters read because there is no leading whitespace)
// ^
// Step 2 : "42" (no characters read because there is neither a '-' nor '+')
// ^
// Step 3 : "42" ("42" is read in)
// ^
// The parsed integer is 42.
// Since 42 is in the range[-2^31, 2^31 - 1], the final result is 42.

#include <iostream>       
#include <string>          
                         

int myAtoi(std::string s)              //*****************в эту функцию можно передавать любое ДЕРЬМО, она всё равно не сломается******************
{                                     //Эта задача была придумана человеком с очень интересной фантазией, только 16.4% решающих эту задачу, смогли её решить
	bool positive = true;         //и у неё максимальное количество дизлайков)
	double long result = 0;
	int i = 0;

	while (s[i] == ' ')
		i++;

	if (s[i] == '-' || s[i] == '+')
	{
		positive = s[i] == '-' ? false : true;
		i++;
	}

	while (s[i] - '0' >= 0 && s[i] - '0' <= 9)
	{
		result += (double)s[i] - '0';
		result *= 10;
		i++;
	}

	result /= 10;

	if (!positive)
		result = -result;
	if (result < std::pow(-2, 31))
		return pow(-2, 31);
	else if (result > std::pow(2, 31) - 1)
		return pow(2, 31) - 1;

	return result;
}


int main()                                                     //Examples input:
{                                                              // "   +0 123"
	std::string str;                                       // "20000000000000000000"
							       // "+1"
	std::cout << "Enter the string: " << std::endl;        // "000 +4"
	getline(std::cin, str);                                // "wfaw 46436"

	std::cout << "RESULT: " << myAtoi(str) << std::endl;

	return 0;
}

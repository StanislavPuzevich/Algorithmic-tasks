//415. Add Strings
//
//Given two non - negative integers, num1and num2 represented as string, return the sum of num1 and num2 as a string.
//You must solve the problem without using any built - in library for handling large integers(such as BigInteger).
//You must also not convert the inputs to integers directly.
//
//Example 1:
//Input: num1 = "11", num2 = "123"
//Output : "134"
//
//Example 2 :
//    Input : num1 = "456", num2 = "77"
//    Output : "533"
//
//Constraints :
//    1 <= num1.length, num2.length <= 104
//    num1 and num2 consist of only digits.
//    num1 and num2 don't have any leading zeros except for the zero itself.

#include <iostream>
#include <string>


class Solution
{
public:
    std::string addStrings(std::string num1, std::string num2)
    {
        std::string result;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int check = 0;

        while (i >= 0 && j >= 0)
        {
            int temp = check + num1[i] + num2[j];
            check = 0;
            if (temp >= 106)
            {
                result.push_back(temp - 58);
                check = 1;
            }
            else
                result.push_back(temp - 48);
            i--;
            j--;
        }
        while (i >= 0)
        {
            int temp = check + num1[i];
            check = 0;
            if (temp > 57)
            {
                result.push_back(temp - 10);
                check = 1;
            }
            else
                result.push_back(temp);
            i--;
        }
        while (j >= 0)
        {
            int temp = check + num2[j];
            check = 0;
            if (temp > 57)
            {
                result.push_back(temp - 10);
                check = 1;
            }
            else
                result.push_back(temp);
            j--;
        }
        if (check)
            result.push_back('1');

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;
    std::string s1, s2;

    std::cout << "Enter the 1st string: " << std::endl;
    getline(std::cin, s1);
    std::cout << "Enter the 2nd string: " << std::endl;
    getline(std::cin, s2);

    std::cout << "The Sum of strings: " << s.addStrings(s1, s2) << std::endl;

    return 0;
}
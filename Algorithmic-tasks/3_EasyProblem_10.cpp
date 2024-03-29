﻿//171. Excel Sheet Column Number
//
//Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//
//Example 3:
//Input: columnTitle = "ZY"
//Output : 701
//
//
//Constraints :
//    1 <= columnTitle.length <= 7
//    columnTitle consists only of uppercase English letters.
//    columnTitle is in the range["A", "FXSHRXW"].

#include <iostream>   
#include <string>


class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        int result = 0, temp;

        for (int i = 0; i < columnTitle.length(); i++)
            result = result * 26 + (columnTitle[i] - 'A' + 1);

        return result;
    }
};


int main()
{
    Solution s;
    std::string str("ABCDI");

    std::cout << s.titleToNumber(str) << std::endl;

    return 0;
}
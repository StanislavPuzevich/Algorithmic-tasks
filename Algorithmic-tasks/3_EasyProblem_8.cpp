//119. Pascal's Triangle II
//
//Given an integer rowIndex, return the rowIndexth(0 - indexed) row of the Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//
//Example 1:
//Input: rowIndex = 3
//Output : [1, 3, 3, 1]
//
//Example 2 :
//Input : rowIndex = 0
//Output : [1]
//
//Constraints :
//    0 <= rowIndex <= 33

#include <iostream>   
#include <vector>


class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;

        for (int i = 0; i <= rowIndex; i++)
        {
            temp.push_back(1);

            for (int j = 1; j <= i; j++)
            {
                if (j == i)
                    temp.push_back(1);
                else
                    temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result.push_back(temp);
            temp.clear();
        }
        return result.back();
    }
};


int main()
{
    Solution s;
    int n = 3;
    std::vector<int> result = s.getRow(n);

    for (int i = 0; i < result.size(); i++)
            std::cout << result[i] << ", ";
    std::cout << std::endl;

    return 0;
}
//118. Pascal's Triangle
//
//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//
//Example 1:
//Input: numRows = 5
//Output : [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
//
//Example 2 :
//Input : numRows = 1
//Output : [[1]]
//
//Constraints :
//    1 <= numRows <= 30

#include <iostream>   
#include <vector>


class Solution 
{
public:
    std::vector<std::vector<int>> generate(int numRows) 
    {
        std::vector<std::vector<int>> result;

        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> temp;
            temp.push_back(1);

            for (int j = 1; j <= i; j++)
            {
                if(j == i)  
                    temp.push_back(1);
                else
                    temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};


int main()
{
    Solution s;
    int n = 5;
    std::vector<std::vector<int>> result = s.generate(n);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j] << ", ";
        std::cout << std::endl;
    }

    return 0;
}
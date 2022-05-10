//216. Combination Sum III
// 
//---------------------------------------------------------------------------
// The link to the task: https://leetcode.com/problems/combination-sum-iii/
//---------------------------------------------------------------------------
//
//Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
//Only numbers 1 through 9 are used.
//Each number is used at most once.
//Return a list of all possible valid combinations.The list must not contain the same combination twice, and the combinations may be returned in any order.
//
//Example 1:
//Input: k = 3, n = 7
//Output : [[1, 2, 4]]
//Explanation :
//    1 + 2 + 4 = 7
//    There are no other valid combinations.
//
//Example 2 :
//    Input : k = 3, n = 9
//    Output : [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
//    Explanation :
//    1 + 2 + 6 = 9
//    1 + 3 + 5 = 9
//    2 + 3 + 4 = 9
//    There are no other valid combinations.
//
//Example 3 :
//    Input : k = 4, n = 1
//    Output : []
//    Explanation : There are no valid combinations.
//    Using 4 different numbers in the range[1, 9], the smallest sum we can get is 1 + 2 + 3 + 4 = 10 and since 10 > 1, there are no valid combination.
//
//Constraints:
//2 <= k <= 9
//1 <= n <= 60

#include <iostream>
#include <vector>

//final version
class Solution
{
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        function(result, temp, k, n, 0, 1);
        return result;
    }

    void function(std::vector<std::vector<int>>& result, std::vector<int> &temp, int k, int n, int sum, int i)
    {
        if (k == 0)
        {
            if (sum == n)
                result.push_back(temp);
            return;
        }

        while (i < n && i < 10)
        {
            temp.push_back(i);
            if (sum > n)
                break;
            function(result, temp, k - 1, n, sum + i, i + 1);
            temp.pop_back();
            i++;
        }
    }
};

//first version
class Solution_2
{
public:
    std::vector<std::vector<int>> combinationSum3_2(int k, int n)
    {
        if (n == 1)return {};
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        int i = 1, sum = 0;
        function_2(result, temp, k, n, sum, i);
        return result;
    }

    void function_2(std::vector<std::vector<int>>& result, std::vector<int>& temp, int k, int n, int sum, int i)
    {
        if (k == 0 && sum == n)
        {
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        else if (k == 0)
        {
            temp.pop_back();
            return;
        }
        else if (sum > n)
        {
            temp.pop_back();
            return;
        }

        while (i < n && i < 10)
        {
            temp.push_back(i);
            if (sum > n)
                break;
            function_2(result, temp, k - 1, n, sum + i, i + 1);
            i++;
        }
        temp.pop_back();
    }
};

int main()
{
    Solution s;

    std::vector<std::vector<int>> result = s.combinationSum3(3, 9);

    std::cout << "Result:" << std::endl;
    for (auto i : result)
    {
        for (auto j : i)
            std::cout << j << "  ";
        std::cout << std::endl;
    }

    return 0;
}
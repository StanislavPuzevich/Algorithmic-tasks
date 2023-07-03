//40. Combination Sum II(Medium)
//
//--------------------------------------------------- 
// https://leetcode.com/problems/combination-sum-ii/
//--------------------------------------------------- 
// 
//Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sum to target.
//Each number in candidates may only be used once in the combination.
//Note: The solution set must not contain duplicate combinations.
//
//Example 1 :
//    Input : candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
//    Output :
//    [
//        [1, 1, 6],
//        [1, 2, 5],
//        [1, 7],
//        [2, 6]
//    ]
//
//Example 2:
//    Input: candidates = [2, 5, 2, 1, 2], target = 5
//    Output :
//    [
//        [1, 2, 2],
//        [5]
//    ]
//
//Constraints :
//    1 <= candidates.length <= 100
//    1 <= candidates[i] <= 50
//    1 <= target <= 30

#include <iostream>
#include <vector>
#include <algorithm>

// Time Limit Exceeded
class Solution1
{
    std::vector<std::vector<int>> result;

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::vector<int> vec;

        combinationSum2Helper(candidates, vec, target, 0);

        return result;
    }

    void combinationSum2Helper(const std::vector<int>& candidates, std::vector<int>& vec, const int target, const int indx)
    {
        if (indx == candidates.size() || target <= 0)
        {
            if (target == 0)
            {
                std::vector<int> copy = vec;
                std::sort(copy.begin(), copy.end());
                if (std::find(result.begin(), result.end(), copy) == result.end())
                    result.push_back(copy);
            }
            return;
        }

        vec.push_back(candidates[indx]);
        combinationSum2Helper(candidates, vec, target - candidates[indx], indx + 1);

        vec.pop_back();
        combinationSum2Helper(candidates, vec, target, indx + 1);
    }
};

class Solution2
{
    std::vector<std::vector<int>> result;

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::vector<int> vec;

        std::sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, vec, target, 0);

        return result;
    }

    void combinationSum2Helper(const std::vector<int>& candidates, std::vector<int>& vec, const int target, const int indx)
    {
        if (target == 0)
            result.push_back(vec);
       
        for (int i = indx; i < candidates.size() && candidates[i] <= target; i++)
        {
            if (i != indx && candidates[i] == candidates[i - 1])
                continue;

            vec.push_back(candidates[i]);
            combinationSum2Helper(candidates, vec, target - candidates[i], i + 1);
            vec.pop_back();
        }
    }
};

int main()
{
    Solution2 s;
    std::vector candidates = { 2,5,2,1,2 };
    std::vector<std::vector<int>> answ = s.combinationSum2(candidates, 5);

    for (const auto& vec : answ)
    {
        for (const auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}

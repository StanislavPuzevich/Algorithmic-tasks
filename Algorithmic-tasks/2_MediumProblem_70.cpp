//1578. Minimum Time to Make Rope Colorful(Medium)
//
//-------------------------------------------------------------------
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
//-------------------------------------------------------------------
//
//Alice has n balloons arranged on a rope.You are given a 0 - indexed string colors where colors[i] is the color of the ith balloon.
//
//Alice wants the rope to be colorful.She does not want two consecutive balloons to be of the same color,
//so she asks Bob for help.Bob can remove some balloons from the rope to make it colorful.
//You are given a 0 - indexed integer array neededTime where neededTime[i] is the time(in seconds) that Bob needs to remove the ith balloon from the rope.
//
//Return the minimum time Bob needs to make the rope colorful.
//
//Example 1:
//    Input: colors = "abaac", neededTime = [1, 2, 3, 4, 5]
//    Output : 3
//    Explanation : In the above image, 'a' is blue, 'b' is red, and 'c' is green.
//    Bob can remove the blue balloon at index 2. This takes 3 seconds.
//    There are no longer two consecutive balloons of the same color.Total time = 3.
//
//Example 2 :
//    Input : colors = "abc", neededTime = [1, 2, 3]
//    Output : 0
//    Explanation : The rope is already colorful.Bob does not need to remove any balloons from the rope.
//    
//Example 3 :
//    Input : colors = "aabaa", neededTime = [1, 2, 3, 4, 1]
//    Output : 2
//    Explanation : Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
//    There are no longer two consecutive balloons of the same color.Total time = 1 + 1 = 2.
//
//Constraints :
//    n == colors.length == neededTime.length
//    1 <= n <= 10^5
//    1 <= neededTime[i] <= 10^4
//    colors contains only lowercase English letters.

#include <iostream>
#include <vector>

class Solution 
{
public:
    int minCost(const std::string& colors, const std::vector<int>& neededTime) 
    {
        int resultMinCost = 0;
        int maxCost = neededTime[0];
        int currentSum = neededTime[0];
        bool check = false;

        for (int left = 0, right = 1; right < neededTime.size(); right++)
        {
            if (colors[left] == colors[right])
            {
                maxCost = std::max(maxCost, neededTime[right]);
                currentSum += neededTime[right];
                check = true;
            }
            else if (check)
            {
                resultMinCost += (currentSum - maxCost);
                left = right;
                currentSum = neededTime[left];
                maxCost = neededTime[left];
                check = false;
            }
            else
            {
                left++;
                currentSum = neededTime[left];
                maxCost = neededTime[left];
            }
        }

        if (check) resultMinCost += (currentSum - maxCost);

        return resultMinCost;
    }

    int minCost_vers2(const std::string& colors, const std::vector<int>& neededTime)  // Solution after reading LeetCode forum
    {
        int resultMinCost = 0;
        int maxNeededTime = neededTime[0];

        for (int i = 1; i < neededTime.size(); i++)
        {
            if (colors[i] == colors[i - 1])
            {
                resultMinCost += std::min(maxNeededTime, neededTime[i]);
                maxNeededTime = std::max(maxNeededTime, neededTime[i]);
            }
            else
                maxNeededTime = neededTime[i];
        }

        return resultMinCost;
    }
};

int main()
{
    Solution s;
    std::string str = "aaabbbabbbb";
    std::vector<int> vec = { 3,5,10,7,5,3,5,5,4,8,1 };

    std::cout << s.minCost_vers2(str, vec) << std::endl;

    return 0;
}

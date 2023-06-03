//1376. Time Needed to Inform All Employees(Medium)
//
//-------------------------------------------------------------------------------- 
// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
//-------------------------------------------------------------------------------- 
// 
//A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.
//
//Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i - th employee, manager[headID] = -1. Also, 
//it is guaranteed that the subordination relationships have a tree structure.
//
//The head of the company wants to inform all the company employees of an urgent piece of news.He will inform his direct subordinates, and they will inform their subordinates,
//and so on until all employees know about the urgent news.
//
//The i - th employee needs informTime[i] minutes to inform all of his direct subordinates(i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).
//
//Return the number of minutes needed to inform all the employees about the urgent news.
//
// 
//Example 1:
//    Input: n = 1, headID = 0, manager = [-1], informTime = [0]
//    Output : 0
//    Explanation : The head of the company is the only employee in the company.
//
//Example 2 :
//    Input : n = 6, headID = 2, manager = [2, 2, -1, 2, 2, 2], informTime = [0, 0, 1, 0, 0, 0]
//    Output : 1
//    Explanation : The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
//    The tree structure of the employees in the company is shown.
//
//Example 3: (the most understandable example)----------------------------------------------------------------------------------------------------------------------
//    For those who are confused wiith this baddddddddd description, the manager list[2, 2, -1, 2, 2, 2] actually means
//    [position 2 is my manager, position 2 is my manager, I am the head, position 2 is my manager, position 2 is my manager, position 2 is my manager]
//    and therefore the time is informTime[2]
//    the following testcase might give a better perspective :
//    n = 22, headID = 7,
//        manager = [12, 7, 18, 11, 13, 21, 12, -1, 6, 5, 14, 13, 14, 9, 20, 13, 11, 1, 1, 2, 3, 19]
//        informTime = [0, 540, 347, 586, 0, 748, 824, 486, 0, 777, 0, 202, 653, 713, 454, 0, 0, 0, 574, 735, 721, 772]
//
//        in this case, manager[7] have subordinates manager[1] and manager[1] has subordinates manager[18], manager[17]
//        the expected answer of the testcase should be 9132
//
//Constraints :
//    1 <= n <= 10^5
//    0 <= headID < n
//    manager.length == n
//    0 <= manager[i] < n
//    manager[headID] == -1
//    informTime.length == n
//    0 <= informTime[i] <= 1000
//    informTime[i] == 0 if employee i has no subordinates.
//    It is guaranteed that all the employees can be informed.

#include <iostream>
#include <vector>
#include <unordered_map>

// Solution after discussion on the LeetCode forum
class Solution
{
public:
    int numOfMinutes(int n, int headID, std::vector<int>& managers, std::vector<int>& informTime) 
    {
        std::unordered_map<int, std::vector<int>> ump;

        for (int i = 0; i < managers.size(); i++)
        {
            if (managers[i] == -1) continue;

            ump[managers[i]].push_back(i);
        }

        return helperFunction(headID, informTime, ump);
    }

    int helperFunction(int manager, std::vector<int>& informTime, std::unordered_map<int, std::vector<int>>& ump)
    {
        int maxTime = 0;

        if (ump.find(manager) != ump.end())
            for (auto subordinate : ump[manager])
                maxTime = std::max(maxTime, helperFunction(subordinate, informTime, ump));

        return maxTime + informTime[manager];
    }
};

int main()
{
    Solution s;
    std::vector managers = { 12,7,18,11,13,21,12,-1,6,5,14,13,14,9,20,13,11,1,1,2,3,19 };
    std::vector informTime = { 0,540,347,586,0,748,824,486,0,777,0,202,653,713,454,0,0,0,574,735,721,772 };

    std::cout << s.numOfMinutes(22, 7, managers, informTime) << std::endl;

    return 0;
}

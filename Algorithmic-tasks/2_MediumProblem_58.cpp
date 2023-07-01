//2305. Fair Distribution of Cookies(Medium)
//
//------------------------------------------------------------- 
// https://leetcode.com/problems/fair-distribution-of-cookies/
//------------------------------------------------------------- 
// 
//You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag.
//You are also given an integer k that denotes the number of children to distribute all the bags of cookies to.
//All the cookies in the same bag must go to the same child and cannot be split up.
//
//The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
//Return the minimum unfairness of all distributions.
//
//Example 1:
//    Input: cookies = [8, 15, 10, 20, 8], k = 2
//    Output : 31
//    Explanation : One optimal distribution is[8, 15, 8] and [10, 20]
//                  - The 1st child receives[8, 15, 8] which has a total of 8 + 15 + 8 = 31 cookies.
//                  - The 2nd child receives[10, 20] which has a total of 10 + 20 = 30 cookies.
//                  The unfairness of the distribution is max(31, 30) = 31.
//                  It can be shown that there is no distribution with an unfairness less than 31.
//
//Example 2 :
//    Input : cookies = [6, 1, 3, 2, 2, 4, 1, 2], k = 3
//    Output : 7
//    Explanation : One optimal distribution is[6, 1], [3, 2, 2], and [4, 1, 2]
//                  - The 1st child receives[6, 1] which has a total of 6 + 1 = 7 cookies.
//                  - The 2nd child receives[3, 2, 2] which has a total of 3 + 2 + 2 = 7 cookies.
//                  - The 3rd child receives[4, 1, 2] which has a total of 4 + 1 + 2 = 7 cookies.
//                  The unfairness of the distribution is max(7, 7, 7) = 7.
//                  It can be shown that there is no distribution with an unfairness less than 7.
//
//Constraints :
//    2 <= cookies.length <= 8
//    1 <= cookies[i] <= 10^5
//    2 <= k <= cookies.length

#include <iostream>
#include <vector>

class Solution 
{
private:
    int answ = INT_MAX;

    void helper(const std::vector<int>& cookies, std::vector<int>& temp, const int indx, const int fair)
    {
        if (indx == cookies.size())
        {
            int max = INT_MIN;
            for (const auto i : temp)
                max = std::max(max, i);

            answ = std::min(answ, max);
            return;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            if (i > 0 && temp[i - 1] == temp[i]) continue;
            if (temp[i] >= fair) continue;

            temp[i] += cookies[indx];
            helper(cookies, temp, indx + 1, fair);
            temp[i] -= cookies[indx];
        }
    }

public:
    int distributeCookies(std::vector<int>& cookies, int k) 
    {   
        int sum = 0;
        for (const auto i : cookies)
            sum += i;
        int fair = sum / k;

        std::vector<int> temp(k, 0);
        helper(cookies, temp, 0, fair);
        return answ;
    }
};

int main()
{
    Solution s;
    std::vector cookies = { 8,15,10,20,8 };

    std::cout << s.distributeCookies(cookies, 2) << std::endl;

    return 0;
}

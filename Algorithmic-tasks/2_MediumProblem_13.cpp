//1288. Remove Covered Intervals
//
//Given an array intervals where intervals[i] = [li, ri] represent the interval[li, ri), remove all intervals that are covered by another 
//interval in the list.
//The interval[a, b) is covered by the interval[c, d) ifand only if c <= a and b <= d.
//Return the number of remaining intervals.
//
//Example 1:
//Input: intervals = [[1, 4], [3, 6], [2, 8]]
//Output : 2
//Explanation : Interval[3, 6] is covered by[2, 8], therefore it is removed.
//
//Constraints :
//    1 <= intervals.length <= 1000
//    intervals[i].length == 2
//    0 <= li <= ri <= 105
//    All the given intervals are unique

#include <iostream>   
#include <vector>


int removeCoveredIntervals(std::vector<std::vector<int>>& intervals)
{
    bool check;
    std::vector<std::vector<int>> res;

    for (int i = 0; i < intervals.size(); i++)
    {
        check = false;
        for (int j = intervals.size() - 1; j >= 0; j--)
        {
            if (j != i && intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1])
            {
                check = true;
                break;
            }
        }
        if (!check) res.push_back(intervals[i]);
    }
    return res.size();
}


int main()
{
    std::vector<std::vector<int>> vec
    {
        { 1, 4 },
        { 2, 4 },
        { 1, 2 },
        { 3, 4 },
    };

    std::cout << removeCoveredIntervals(vec) << std::endl;

    return 0;
}

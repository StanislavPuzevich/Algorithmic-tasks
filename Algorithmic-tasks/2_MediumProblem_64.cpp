//435. Non - overlapping Intervals(Medium)
//
//Given an array of intervals intervals where intervals[i] = [starti, endi], 
//return the minimum number of intervals you need to remove to make the rest of the intervals non - overlapping.
//
//Example 1:
//    Input: intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
//    Output : 1
//    Explanation : [1, 3] can be removed and the rest of the intervals are non - overlapping.
//
//Example 2 :
//    Input : intervals = [[1, 2], [1, 2], [1, 2]]
//    Output : 2
//    Explanation : You need to remove two[1, 2] to make the rest of the intervals non - overlapping.
//
//Example 3 :
//    Input : intervals = [[1, 2], [2, 3]]
//    Output : 0
//    Explanation : You don't need to remove any of the intervals since they're already non - overlapping.
//
//Constraints :
//    1 <= intervals.length <= 10^5
//    intervals[i].length == 2
//    - 5 * 10^4 <= starti < endi <= 5 * 10^4

#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
        int counter = 0;

        int left = 0;
        int right = 1;

        if (intervals.size() == right) return 0;

        std::sort(intervals.begin(), intervals.end(), 
            [](const std::vector<int>& first, const std::vector<int>& second) { return first[1] < second[1]; });

        while (right < intervals.size())
        {
            if (intervals[left][1] > intervals[right][0])
                counter++;
            else
                left = right;

            right++;
        }

        return counter;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> intervals =
    { {-52,31}, {-73,-26}, {82,97}, {-65,-11}, {-62,-49}, {95,99}, {58,95}, {-31,49}, {66,98}, {-63,2}, {30,47}, {-40,-26} };

    std::cout << s.eraseOverlapIntervals(intervals) << std::endl;

    return 0;
}

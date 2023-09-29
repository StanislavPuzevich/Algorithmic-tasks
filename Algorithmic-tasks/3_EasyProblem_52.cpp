#include <iostream>
#include <vector>

class Solution
{
public:
    bool isMonotonic_vers1(std::vector<int>& nums)
    {
        if (nums[0] < nums[nums.size() - 1])
        {
            for (int i = 1; i < nums.size(); ++i)
                if (nums[i - 1] > nums[i])
                    return false;
        }
        else
        {
            for (int i = 1; i < nums.size(); ++i)
                if (nums[i - 1] < nums[i])
                    return false;
        }

        return true;
    }

    bool isMonotonic_vers2(std::vector<int>& nums)
    {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
                decreasing = false;
            else if (nums[i] < nums[i - 1])
                increasing = false;

            if (!decreasing && !increasing)
                break;
        }

        return increasing || decreasing;
    }
};

int main()
{
    Solution s;
    std::vector vec = { 1,2,2,3 };

    std::cout << s.isMonotonic_vers1(vec) << std::endl;

    return 0;
}

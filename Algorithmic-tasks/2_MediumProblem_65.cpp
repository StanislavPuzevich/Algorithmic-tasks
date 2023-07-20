//735. Asteroid Collision(Medium)
//
//--------------------------------------------------- 
// https://leetcode.com/problems/asteroid-collision/
//--------------------------------------------------- 
// 
// We are given an array asteroids of integers representing asteroids in a row.
// 
// For each asteroid, the absolute value represents its size, and the sign represents its direction(positive meaning right,
// negative meaning left).Each asteroid moves at the same speed.
// 
// Find out the state of the asteroids after all collisions.If two asteroids meet, the smaller one will explode.If both are the same size, both will explode.
// Two asteroids moving in the same direction will never meet.
//
//Example 1:
//    Input: asteroids = [5, 10, -5]
//    Output : [5, 10]
//    Explanation : The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
//
//Example 2 :
//    Input : asteroids = [8, -8]
//    Output : []
//    Explanation : The 8 and -8 collide exploding each other.
//
//Example 3 :
//    Input : asteroids = [10, 2, -5]
//    Output : [10]
//    Explanation : The 2 and -5 collide resulting in - 5. The 10 and -5 collide resulting in 10.
//
//Constraints :
//    2 <= asteroids.length <= 10^4
//    -1000 <= asteroids[i] <= 1000
//    asteroids[i] != 0

#include <iostream>
#include <vector>
#include <stack>

class Solution 
{
public:
    std::vector<int> asteroidCollision_vers1(std::vector<int>& asteroids)
    {
        std::stack<int> st;
        st.push(asteroids[0]);

        int i = 1;
        while (i < asteroids.size())
        {
            if (st.empty() || (asteroids[i] * st.top()) > 0 || st.top() < 0)
                st.push(asteroids[i]);
            else if (st.top() + asteroids[i] < 0)
            {
                st.pop();
                continue;
            }
            else if (st.top() + asteroids[i] == 0)
                st.pop();

            i++;
        }

        std::vector<int> result(st.size());
        for (int i = st.size() - 1; i > -1; i--)
        {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }

    // Brute force solution
    std::vector<int> vec;

    std::vector<int> asteroidCollision_vers2(std::vector<int>& asteroids)
    {
        vec = asteroids;
        asteroidCollisionHelper(0, 1);
        return vec;
    }

    void asteroidCollisionHelper(int left, int right)
    {
        if (right >= vec.size()) return;

        std::vector<int> copy;
        if (vec[left] > 0 && vec[right] < 0)
        {
            if (vec[left] > abs(vec[right]))
            {
                if (right + 1 < vec.size())
                {
                    copy.insert(copy.begin(), vec.begin(), vec.begin() + left + 1);
                    copy.insert(copy.end(), vec.begin() + right + 1, vec.end());
                    vec = copy;
                    asteroidCollisionHelper(left, right);
                }
                else
                {
                    copy.insert(copy.begin(), vec.begin(), vec.begin() + right);
                    vec = copy;
                    return;
                }
            }
            else if (vec[left] < abs(vec[right]))
            {
                if (left > 0)
                {
                    copy.insert(copy.begin(), vec.begin(), vec.begin() + left);
                    copy.insert(copy.end(), vec.begin() + right, vec.end());
                    vec = copy;
                    asteroidCollisionHelper(left - 1, right - 1);
                }
                else
                {
                    copy.insert(copy.begin(), vec.begin() + right, vec.end());
                    vec = copy;
                    asteroidCollisionHelper(left + 1, right + 1);
                }
            }
            else
            {
                if (left > 0 && right + 1 < vec.size())
                {
                    copy.insert(copy.begin(), vec.begin(), vec.begin() + left);
                    copy.insert(copy.end(), vec.begin() + right + 1, vec.end());
                    vec = copy;
                    asteroidCollisionHelper(left - 1, right - 1);
                }
                else if (left == 0 && right + 1 < vec.size())
                {
                    copy.insert(copy.begin(), vec.begin() + right + 1, vec.end());
                    vec = copy;
                    asteroidCollisionHelper(left, right);
                }
                else if (left > 0 && right + 1 == vec.size())
                {
                    copy.insert(copy.begin(), vec.begin(), vec.begin() + left);
                    vec = copy;
                    return;
                }
                else
                {
                    vec = copy;
                    return;
                }
            }
        }
        else
            asteroidCollisionHelper(left + 1, right + 1);
    }
};

int main()
{
    Solution s;
    std::vector asteroids ={ 5,10,-5 };
    std::vector<int> result = s.asteroidCollision_vers1(asteroids);

    for (const auto i : result)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

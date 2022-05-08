//Sieve of Erat1209. Remove All Adjacent Duplicates in String II
// 
//You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacentand equal letters from sand removing them,
//causing the leftand the right side of the deleted substring to concatenate together.
//We repeatedly make k duplicate removals on s until we no longer can.
//Return the final string after all such duplicate removals have been made.It is guaranteed that the answer is unique.
//
//Example 1:
//    Input: s = "abcd", k = 2
//    Output : "abcd"
//    Explanation : There's nothing to delete.
//
//Example 2 :
//    Input : s = "deeedbbcccbdaa", k = 3
//    Output : "aa"
//    Explanation :
//    First delete "eee" and "ccc", get "ddbbbdaa"
//    Then delete "bbb", get "dddaa"
//    Finally delete "ddd", get "aa"
//
//Example 3 :
//    Input : s = "pbbcggttciiippooaais", k = 2
//    Output : "ps"
//
//Constraints :
//    1 <= s.length <= 105
//    2 <= k <= 104
//    s only contains lower case English letters.

#include <iostream>
#include <unordered_map>
#include <stack>

class Solution
{
public:
    //This function is fast
    std::string removeDuplicates_1(std::string s, int k)
    {
        std::stack<std::pair<char, int>> st;
        for (auto i : s)
        {
            if (!st.empty())
            {
                if (st.top().first == i)
                {
                    st.top().second++;
                    if (st.top().second == k)
                        st.pop();
                }
                else
                    st.push(std::pair(i, 1));
            }
            else
                st.push(std::pair(i, 1));
        }
        s.clear();
        while (!st.empty())
        {
            s.append(st.top().second, st.top().first);
            st.pop();
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    //This is slow function
    std::string removeDuplicates_2(std::string s, int k)
    {
        bool check = true;
        int counter = 1;
        while (check)
        {
            std::string temp;
            temp += s[0];
            check = false;
            for (int i = 1; i < s.length(); i++)
            {
                while (s[i] == s[i - 1])
                {
                    temp += s[i];
                    counter++;
                    if (counter == k)
                    {
                        temp.erase(temp.length() - counter, counter);
                        counter = 1;
                        check = true;
                        i++;
                        break;
                    }
                    i++;
                }
                temp += s[i];
                counter = 1;
            }
            s = temp;
        }
        if (s[s.length()-1] == '\0')
            s = s.erase(s.length() - 1, 1);
            
        return s;
    }

    /*This function does a little different.
    It just removes all Adjacent Duplicates, and creates a string of characters in any order*/
    std::string removeDuplicates_3(std::string s, int k)
    {
        std::unordered_map<char, int> map;
        std::string result;

        for (auto i : s)
            map[i]++;

        for (auto& elem : map)
        {
            elem.second %= k;
            while (elem.second > 0)
            {
                result += elem.first;
                elem.second--;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::string str = "pbbcggttciiippooaais";
    int n = 2;

    std::cout << "Result: " << s.removeDuplicates_1(str, n) << std::endl;

    return 0;
}
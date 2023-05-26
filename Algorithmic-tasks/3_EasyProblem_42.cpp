//703. Kth Largest Element in a Stream(Easy)
//
//---------------------------------------------------------------------------- 
// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
//---------------------------------------------------------------------------- 
// 
//Design a class to find the kth largest element in a stream. Note that it is the k^th largest element in the sorted order, not the k^th distinct element.
// 
//Implement KthLargest class :
//    KthLargest(int k, int[] nums) Initializes the object with the integer kand the stream of integers nums.
//    int add(int val) Appends the integer val to the streamand returns the element representing the k^th largest element in the stream.
//
//Example 1:
//    Input
//    ["KthLargest", "add", "add", "add", "add", "add"]
//    [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
//
//    Output
//    [null, 4, 5, 5, 8, 8]
//
//    Explanation
//    KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
//    kthLargest.add(3);   // return 4
//    kthLargest.add(5);   // return 5
//    kthLargest.add(10);  // return 5
//    kthLargest.add(9);   // return 8
//    kthLargest.add(4);   // return 8
//
//Constraints:
//    1 <= k <= 10^4
//    0 <= nums.length <= 10^4
//    -10^4 <= nums[i] <= 10^4
//    -10^4 <= val <= 10^4
//    At most 10^4 calls will be made to add.
//    It is guaranteed that there will be at least k elements in the array when you search for the k^th element.

#include <iostream>
#include <vector>
#include <queue>
#include <set>

// This realization was written after discussing on the LeetCode forum, passed all tests and works very quickly
class KthLargest_vers3
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_pq;
    int m_k;

public:
    KthLargest_vers3(int k, std::vector<int>& nums) : m_k(k)
    {
        for (auto i : nums) helper(i);
    }

    int add(int val)
    {
        helper(val);
        return m_pq.top();
    }

    void helper(int x)
    {
        if (m_pq.size() < m_k)
        {
            m_pq.push(x);
            return;
        }

        if (x > m_pq.top())
        {
            m_pq.pop();
            m_pq.push(x);
        }
    }
};

// This realization is faster than the first, works without errors, but also slow.
class KthLargest_vers2
{
public:
    std::multiset<int> m_st;
    int m_k;

    KthLargest_vers2(int k, std::vector<int>& nums) : m_k(k)
    {
        for (auto& i : nums)
            m_st.insert(i);
    }

    int add(int val)
    {
        m_st.insert(val);

        auto it = m_st.end();
        int temp = m_k;

        while (temp)
        {
            it--;
            temp--;
        }
        return *it;
    }
};

// This realization works but so slowly, if we call the function many times, we will get an error "Time Limit Exceeded"
class KthLargest_vers1
{
public:
    std::vector<int> m_vec;
    int m_k;
    KthLargest_vers1(int k, std::vector<int>& nums) : m_vec(nums), m_k(k)
    {

    }

    int add(int val)
    {
        m_vec.push_back(val);
        std::sort(m_vec.begin(), m_vec.end());
        return m_vec[m_vec.size() - m_k];
    }
};

void print_tests(int n, std::vector<int>& vec)
{
    KthLargest_vers1 k1(n, vec);
    KthLargest_vers2 k2(n, vec);
    KthLargest_vers3 k3(n, vec);

    std::cout << k1.add(3)  << std::endl;  // return 4
    std::cout << k1.add(5)  << std::endl;  // return 5
    std::cout << k1.add(10) << std::endl;  // return 5
    std::cout << k1.add(9)  << std::endl;  // return 8
    std::cout << k1.add(4)  << std::endl;  // return 8
                            
    std::cout << k2.add(3)  << std::endl;  // return 4
    std::cout << k2.add(5)  << std::endl;  // return 5
    std::cout << k2.add(10) << std::endl;  // return 5
    std::cout << k2.add(9)  << std::endl;  // return 8
    std::cout << k2.add(4)  << std::endl;  // return 8
                            
    std::cout << k3.add(3)  << std::endl;  // return 4
    std::cout << k3.add(5)  << std::endl;  // return 5
    std::cout << k3.add(10) << std::endl;  // return 5
    std::cout << k3.add(9)  << std::endl;  // return 8
    std::cout << k3.add(4)  << std::endl;  // return 8
}

int main()
{
    std::vector vect = { 4, 5, 8, 2 };
   
    print_tests(3, vect);

    return 0;
}

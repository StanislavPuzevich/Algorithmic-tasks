//1161. Maximum Level Sum of a Binary Tree(Medium)
//
//-------------------------------------------------------------------------------- 
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
//-------------------------------------------------------------------------------- 
// 
//Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
//Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
//
//Example 1:
//    Input: root = [1, 7, 0, 7, -8, null, null]
//    Output : 2
//    Explanation :
//        Level 1 sum = 1.
//        Level 2 sum = 7 + 0 = 7.
//        Level 3 sum = 7 + -8 = -1.
//        So we return the level with the maximum sum which is level 2.
//
//Example 2 :
//    Input : root = [989, null, 10250, 98693, -89388, null, null, null, -32127]
//    Output : 2
//
//Constraints :
//    The number of nodes in the tree is in the range[1, 10^4].
//    - 10^5 <= Node.val <= 10^5

#include <iostream>
#include <unordered_map>
#include <queue>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// consumes less memory than the 2-nd Soluton
class Solution_vers1
{
    std::unordered_map<int, int> ump;

public:
    int maxLevelSum(TreeNode* root) 
    {
        int answ = 0;
        int max = INT_MIN;
        int counter = 1;
    
        helper(root, counter);

        for (const auto& it : ump)
            if (max < it.second)
            {
                max = it.second;
                answ = it.first;
            }

        return answ;
    }

    void helper(TreeNode* root, int count)
    {
        if (!root) return;

        helper(root->left, count + 1);
        ump[count] += root->val;
        helper(root->right, count + 1);
    }
};

// Solution after discussion on the LeetCode forum
// runs faster than the 1-st Solution
class Solution_vers2
{
public:
    int maxLevelSum(TreeNode* root)
    {
        std::queue<TreeNode*> qu;
        qu.push(root);

        int answ = 0;
        int level = 0;
        int max = INT_MIN;

        while (!qu.empty())
        {
            level++;
            int size = qu.size();
            int sum = 0;

            for (int i = 0; i < size; i++)
            {
                auto node = qu.front();
                qu.pop();
                sum += node->val;

                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }

            if (max < sum)
            {
                max = sum;
                answ = level;
            }
        }

        return answ;
    }
};

int main()
{
    Solution_vers2 s;
    TreeNode fifth (-8);
    TreeNode fourth(7);
    TreeNode second(7, &fourth, &fifth);
    TreeNode third (0);
    TreeNode first (1, &second, &third);

    std::cout << s.maxLevelSum(&first) << std::endl;

    return 0;
}

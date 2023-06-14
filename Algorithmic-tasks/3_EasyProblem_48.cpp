//530. Minimum Absolute Difference in BST(Easy)
//
//------------------------------------------------------------------- 
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
//------------------------------------------------------------------- 
// 
//Given the root of a Binary Search Tree(BST), return the minimum absolute difference between the values of any two different nodes in the tree.
//
//Example 1:
//    Input: root = [4, 2, 6, 1, 3]
//    Output : 1
//
//Example 2 :
//    Input : root = [1, 0, 48, null, null, 12, 49]
//    Output : 1
//
//Constraints :
//    The number of nodes in the tree is in the range[2, 10^4].
//    0 <= Node.val <= 10^5
//
//Note : This question is the same as 783 : https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// without extra memory
// The solution after discussion on the LeetCode forum
class Solution_vers3
{
    int minDiff = INT_MAX;
    int pre;

public:
    int getMinimumDifference(TreeNode* root)
    {
        pre = -1;
        helper(root);
        return minDiff;
    }

    void helper(TreeNode* root)
    {
        if (!root) return;

        helper(root->left);
        if (pre != -1) minDiff = std::min(abs(pre - root->val), minDiff);
        pre = root->val;
        helper(root->right);
    }
};

// 15ms
class Solution_vers2
{
public:
    int getMinimumDifference(TreeNode* root) 
    {
        int minDiff = INT_MAX;
        std::vector<int> vec;
        helper(root, vec);

        for (int i = 1; i < vec.size(); i++)
            minDiff = std::min(abs(vec[i] - vec[i - 1]), minDiff);

        return minDiff;
    }

    void helper(TreeNode* root, std::vector<int>& vec)
    {
        if (!root) return;

        helper(root->left, vec);
        vec.push_back(root->val);
        helper(root->right, vec);
    }
};

// 12ms
class Solution_vers1
{
public:
    int getMinimumDifference(TreeNode* root)
    {
        int minDiff = INT_MAX;
        std::vector<int> vec;
        helper(root, vec);

        std::sort(vec.begin(), vec.end());

        for (int i = 1; i < vec.size(); i++)
            if (vec[i] - vec[i - 1] < minDiff)
                minDiff = vec[i] - vec[i - 1];

        return minDiff;
    }

    void helper(TreeNode* root, std::vector<int>& vec)
    {
        if (!root) return;

        vec.push_back(root->val);

        helper(root->left, vec);
        helper(root->right, vec);
    }
};

int main()
{
    Solution_vers3 s;
    TreeNode fifth (3);
    TreeNode fourth(1);
    TreeNode second(2, &fourth, &fifth);
    TreeNode third (6);
    TreeNode first (4, &second, &third);

    std::cout << s.getMinimumDifference(&first) << std::endl;

    return 0;
}

//111. Minimum Depth of Binary Tree(Easy)
//
//------------------------------------------------------------- 
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
//------------------------------------------------------------- 
// 
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//Note: A leaf is a node with no children.
//
//Example 1 :
//    Input : root = [3, 9, 20, null, null, 15, 7]
//    Output : 2
//
//Example 2 :
//    Input : root = [2, null, 3, null, 4, null, 5, null, 6]
//    Output : 5
//
//Constraints :
//    The number of nodes in the tree is in the range[0, 10^5].
//    - 1000 <= Node.val <= 1000

#include <iostream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
    int counterDeprh = INT_MAX;

public:
    int minDepth(TreeNode* root) 
    {
        minDepthHElper(root, 1);
        return counterDeprh != INT_MAX ? counterDeprh : 0;
    }

    void minDepthHElper(TreeNode* root, int currentCounter)
    {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr)
        {
            counterDeprh = std::min(counterDeprh, currentCounter);
            return;
        }

        currentCounter++;
        minDepthHElper(root->left, currentCounter);
        minDepthHElper(root->right, currentCounter);

        root->left = nullptr;
        root->right = nullptr;
    }
};

int main()
{
    Solution s;
    TreeNode fifth  (7);
    TreeNode fourth (15);
    TreeNode third  (20, &fourth, &fifth);
    TreeNode second (9);
    TreeNode first  (3,&second,&third);

    std::cout << s.minDepth(&first) << std::endl;

    return 0;
}

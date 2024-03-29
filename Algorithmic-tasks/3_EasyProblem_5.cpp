﻿//104. Maximum Depth of Binary Tree
//
//Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//Example 1:
//Input: root = [3, 9, 20, null, null, 15, 7]
//Output : 3
//
//Constraints :
//    The number of nodes in the tree is in the range[0, 104].
//    - 100 <= Node.val <= 100

#include <iostream>   

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        return left > right ? left : right;
    }
};

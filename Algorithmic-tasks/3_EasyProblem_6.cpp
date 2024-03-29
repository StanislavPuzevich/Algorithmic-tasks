﻿//144. Binary Tree Preorder Traversal
//
//Given the root of a binary tree, return the preorder traversal of its nodes' values.
//
//Constraints:
//The number of nodes in the tree is in the range[0, 100].
//- 100 <= Node.val <= 100
//
//Follow up : Recursive solution is trivial, could you do it iteratively ?

#include <iostream>   
#include <vector>


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

    void rec(TreeNode* root, std::vector<int>& result)
    {
        if (!root) return;
        result.push_back(root->val);
        rec(root->left, result);
        rec(root->right, result);
    }

    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int>result;
        rec(root, result);
        return result;
    }
};

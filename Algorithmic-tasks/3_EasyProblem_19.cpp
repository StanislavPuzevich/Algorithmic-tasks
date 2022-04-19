//897. Increasing Order Search Tree
//
//Given the root of a binary search tree, rearrange the tree in in - order so that the leftmost node in the tree is now the root of the tree,
//and every node has no left childand only one right child.
//
//Example 1:
//Input: root = [5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]
//Output : [1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9]
// 
//Example 2:
//Input : root = [5, 1, 7]
//Output : [1, null, 5, null, 7]
//
// Constraints :
//    The number of nodes in the given tree will be in the range[1, 100].
//    0 <= Node.val <= 1000

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
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode* temp = new TreeNode(0);
        rec_func(root, temp);
        return temp->right;
    }

    TreeNode* rec_func(TreeNode* root, TreeNode* temp)
    {
        if (root == nullptr)return temp;

        TreeNode* next = rec_func(root->left, temp);
        next->right = new TreeNode(root->val);

        return rec_func(root->right, next->right);
    }
};
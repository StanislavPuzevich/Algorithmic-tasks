//199. Binary Tree Right Side View
//
//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//Example 1:
//Input: root = [1, 2, 3, null, 5, null, 4]
//Output : [1, 3, 4]
//
//Constraints :
//    The number of nodes in the tree is in the range[0, 100].
//    - 100 <= Node.val <= 100

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
    void func(TreeNode* root, int level, std::vector<int>& vec)
    {
        if (root == nullptr) return;

        if (level == vec.size())
            vec.push_back(root->val);

        func(root -> right, level + 1, vec);
        func(root -> left, level + 1, vec);
    }

    std::vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> result;
        int lev = 0;
        func(root, lev, result);
        return result;
    }
};
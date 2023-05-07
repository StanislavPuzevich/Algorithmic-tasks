//145. Binary Tree Postorder Traversal(Easy)
//
//---------------------------------------------------------------------------- 
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
//---------------------------------------------------------------------------- 
// 
//Given the root of a binary tree, return the postorder traversal of its nodes' values.
//
//Example 1:
//    Input: root = [1, null, 2, 3]
//    Output : [3, 2, 1]
//
//Example 2 :
//    Input : root = []
//    Output : []
//
//Example 3 :
//    Input : root = [1]
//    Output : [1]
//
//Constraints :
//    The number of the nodes in the tree is in the range[0, 100].
//    - 100 <= Node.val <= 100
//
//Follow up : Recursive solution is trivial, could you do it iteratively ?

#include <iostream>
#include <vector>

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
public:
    std::vector<int> result;
    std::vector<int> postorderTraversal(TreeNode* root) 
    {
        helper(root);

        return result;
    }

    void helper(TreeNode* root)
    {
        if (root == nullptr)
            return;

        helper(root->left);
        helper(root->right);
        result.push_back(root->val);
    }
};

int main()
{
    TreeNode n3(3);
    TreeNode n2(2, &n3, nullptr);
    TreeNode n1(1, nullptr, &n2);
    Solution s;
    std::vector<int> vec = s.postorderTraversal(&n1);

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

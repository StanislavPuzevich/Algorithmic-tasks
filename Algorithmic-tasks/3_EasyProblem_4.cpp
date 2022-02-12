//94. Binary Tree Inorder Traversal
//
//Given the root of a binary tree, return the inorder traversal of its nodes' values.
//
//Example 1:
//Input: root = [1, null, 2, 3]
//Output : [1, 3, 2]
//
//Constraints :
// The number of nodes in the tree is in the range[0, 100].
// - 100 <= Node.val <= 100
//
//Follow up : Recursive solution is trivial, could you do it iteratively ?

#include <iostream>   
#include <vector> 
#include <stack>


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
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        if (root == nullptr) return{};

        std::vector<int> result;
        std::stack<TreeNode*> st;
        st.push(root);

        TreeNode* temp = root;
        while (temp != nullptr || !st.empty())
        {
            while (temp != nullptr)
            {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            result.push_back(temp->val);
            temp = temp->right;
        }
    }
};
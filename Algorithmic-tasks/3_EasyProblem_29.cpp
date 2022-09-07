//606. Construct String from Binary Tree
//
//----------------------------------------------------------------- 
//https://leetcode.com/problems/construct-string-from-binary-tree/ 
//----------------------------------------------------------------- 
// 
//Given the root of a binary tree, construct a string consisting of parenthesisand integers from a binary tree with the preorder traversal way,
//and return it.
//Omit all the empty parenthesis pairs that do not affect the one - to - one mapping relationship between the string and 
//the original binary tree.
//
//Example 1:
//Input: root = [1, 2, 3, 4]
//Output : "1(2(4))(3)"
//Explanation : Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs.
//And it will be "1(2(4))(3)"
//
//Example 2 :
//    Input : root = [1, 2, 3, null, 4]
//    Output : "1(2()(4))(3)"
//    Explanation : Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one - to - one mapping relationship between the input and the output.
//
//Constraints :
//    The number of nodes in the tree is in the range[1, 104].
//    - 1000 <= Node.val <= 1000

#include <iostream>
#include <string>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution1                 //The 1-st solution
{
private:
    std::string convert(int n)
    {
        std::string number;

        bool flag = false;
        if (n < 0)
        {
            flag = true;
            n += (abs(n) * 2);
        }

        while (n)
        {
            number += (n % 10 + '0');
            n /= 10;
        }
        if (flag) number += '-';
        std::reverse(number.begin(), number.end());

        return number;
    }

    void deep_function(std::string& res, TreeNode* root)
    {
        if (!root) return;

        if (root->val) res += convert(root->val);
        else res += '0';

        if (root->left || root->right)
        {
            res += '(';
            deep_function(res, root->left);
            res += ')';

            if (root->right)
            {
                res += '(';
                deep_function(res, root->right);
                res += ')';
            }
        }
    }

public:
    std::string tree2str(TreeNode* root)
    {
        std::string result;

        deep_function(result, root);

        return result;
    }
};

class Solution2                 //The 2-nd solution (more compact and easy to understand) 
{
public:
    std::string tree2str(TreeNode* root)
    {
        std::string result = std::to_string(root->val);

        if (root->left || root->right)
        {
            result += '(';
            if (root->left)
                result += tree2str(root->left);
            result += ')';

            if (root->right)
                result += '(' + tree2str(root->right) + ')';
        }

        return result;
    }
};

int main()
{
    Solution2 s;

    TreeNode second(10);
    TreeNode third(5);
    TreeNode first(7, &second, &third);

    std::cout << "Result: " << std::endl << s.tree2str(&first) << std::endl;

    return 0;
}
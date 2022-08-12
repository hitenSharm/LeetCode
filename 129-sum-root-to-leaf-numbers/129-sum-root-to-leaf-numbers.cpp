/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    

    int traverse(TreeNode* root,int res)
    {
        if (!root)return 0;

        res = res * 10 + root->val;

        if (!root->left and !root->right)
        {        
            return res;
        }
        return traverse(root->left, res)+traverse(root->right, res);        
    }

    int sumNumbers(TreeNode* root) {
        //o(n) & o(1)+aux space
        return traverse(root,0);        
    }
};
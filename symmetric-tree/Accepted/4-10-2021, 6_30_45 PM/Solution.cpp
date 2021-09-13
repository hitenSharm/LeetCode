// https://leetcode.com/problems/symmetric-tree

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
    
    bool chk(TreeNode* l,TreeNode* r)
    {
        if(!l || !r)
        return l==r;
        
        if(l->val!=r->val)
        return false;
        
        return (chk(l->left,r->right) && chk(l->right,r->left));
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
        return true;
        
        return chk(root->left,root->right);
        
    }
};
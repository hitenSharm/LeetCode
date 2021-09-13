// https://leetcode.com/problems/balanced-binary-tree

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
    
    int goLeft(TreeNode* root)
    {
        if(!root)return 0;
        return 1+goLeft(root->left);
    }
    
    int goRight(TreeNode* root)
    {
        if(!root)return 0;
        return 1+goRight(root->right);
    }
    
    bool isBalanced(TreeNode* root) {
        int left=goLeft(root);
        int right=goRight(root);
        if(abs(left-right)<=1)return true;
        
        return false;
    }
};
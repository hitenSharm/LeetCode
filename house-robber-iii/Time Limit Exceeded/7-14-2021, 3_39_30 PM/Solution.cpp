// https://leetcode.com/problems/house-robber-iii

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
    int rob(TreeNode* root) {
        if(root == NULL)return 0;
        
        int val=0;
        val+=root->val;
        if(root->left)
        {
            val+=rob(root->left->left) + rob(root->left->right);
        }
        if(root->right)
        {
            val+=rob(root->right->left) + rob(root->right->right);
        }
        int val2=0;
        if(root->left)
        {
            val2+=rob(root->left);
        }
        if(root->right)
        {
            val2+=rob(root->right);
        }
        return max(val,val2);
    }
};
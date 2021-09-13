// https://leetcode.com/problems/range-sum-of-bst

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
    
    void inOrder(TreeNode* root, int &low, int &high,int &ans)
    {
        if(!root)
        return ;
        
        inOrder(root->left,low,high,ans);
        
        if(root->val<=high && root->val>=low)
        ans+=root->val;
        
        inOrder(root->right,low,high,ans);
        
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        inOrder(root,low,high,ans);
        return ans;
    }
};
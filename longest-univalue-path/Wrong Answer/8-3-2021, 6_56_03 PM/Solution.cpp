// https://leetcode.com/problems/longest-univalue-path

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

    int ans=INT_MIN;

    int calc(TreeNode* root,unordered_set<TreeNode*>& vis,int value)
    {
        if(!root || value!=root->val)return 0;
        if(vis.find(root)!=vis.end())
        {
            return (calc(root->left,vis,root->val)+calc(root->right,vis,root->val));
        }
        vis.insert(root);
        int temp=(1+calc(root->left,vis,root->val)+calc(root->right,vis,root->val));
        ans=max(ans,temp-1);
        return temp;
    }

    void inorder(TreeNode* root,unordered_set<TreeNode*>& vis)
    {
        if(!root)return ;
        if(vis.find(root)!=vis.end())
        {
            inorder(root->left,vis);
            inorder(root->right,vis);
        }
        calc(root,vis,root->val);
        inorder(root->left,vis);
        inorder(root->right,vis);
    }

    int longestUnivaluePath(TreeNode* root) {
        unordered_set<TreeNode*>vis;
        if(ans==INT_MIN)ans=0;
        inorder(root,vis);
        return ans;
    }
};
// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int ans=INT_MAX;
    void dfs(TreeNode* root,int depth)
    {
        if(!root)return ;
        if(!root->left and !root->right)
        {
            ans=min(ans,depth);
            return ;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int minDepth(TreeNode* root) {
        dfs(root,1);
        if(ans==INT_MAX)ans=1;
        return ans;
    }
};
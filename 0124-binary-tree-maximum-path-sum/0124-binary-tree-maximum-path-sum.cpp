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
    
    int traverse(TreeNode* root)
    {
        if(!root)return 0;
        int l=traverse(root->left);
        int r=traverse(root->right);
        ans=max(ans,root->val);
        ans=max(ans,max(l+root->val,max(r+root->val,l+r+root->val)));
        int tans=ans;
        int rt=root->val;
        return max(l+root->val,max(r+root->val,root->val));
    }
    
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;
    }
};
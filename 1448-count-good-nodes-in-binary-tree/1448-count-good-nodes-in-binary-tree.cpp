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
    int ans=0;
    
    void traverse(TreeNode* root,int maxi)
    {
        if(!root)return ;
        if(root->val>=maxi){
            ans++;
            maxi=root->val;
        }
        traverse(root->left,maxi);
        traverse(root->right,maxi);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int maxi=root->val;
        traverse(root,maxi);
        return ans;
    }
};
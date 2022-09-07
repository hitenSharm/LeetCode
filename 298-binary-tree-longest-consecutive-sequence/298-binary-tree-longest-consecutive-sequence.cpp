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
    void traverse(int prev,TreeNode* r,int len)
    {
        ans=max(ans,len);
        if(!r)return ;
        if(prev==-1 || prev+1!=r->val)
        {
            traverse(r->val,r->left,1);
            traverse(r->val,r->right,1);
        }
        if(prev+1==r->val)
        {
            traverse(r->val,r->left,len+1);
            traverse(r->val,r->right,len+1);
        }
    }
    
    int longestConsecutive(TreeNode* root) {
        traverse(-1,root,0);
        return ans;
    }
};
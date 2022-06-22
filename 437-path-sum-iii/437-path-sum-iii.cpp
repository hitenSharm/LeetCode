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
    
    void solve(TreeNode* r,int& t,long long value)
    {
        if(!r)return ;
        value+=r->val;
        if(value==t)
        {
            ans++;
        }
        solve(r->left,t,value);
        solve(r->right,t,value);
    }
    
    void traverse(TreeNode* r,int& target)
    {
        if(!r)return ;
        traverse(r->left,target);
        solve(r,target,0);
        traverse(r->right,target);
    }

    int pathSum(TreeNode* root, int targetSum) {
        traverse(root,targetSum);
        return ans;
    }
};
// https://leetcode.com/problems/merge-two-binary-trees

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    
    void dfs(TreeNode* r1,TreeNode* r2)
    {
        if(!r1 and !r2)return ;
        r1->val+=r2->val;
        if(r1->left and r2->left)dfs(r1->left,r2->left);
        if(r1->right and r2->right)dfs(r1->right,r2->right);
        
        if(!r1->left and r2->left)r1->left=r2->left;
        
        if(!r1->right and r2->right)r1->right=r2->right;
        
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        dfs(root1,root2);
        return root1;
    }
};
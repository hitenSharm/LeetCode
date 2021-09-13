// https://leetcode.com/problems/validate-binary-search-tree

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    
    int prev=-1;
    int fl=0;
    
    void inorder(TreeNode* root)
    {
        if(!root)
        return ;
        
        inorder(root->left);
        
        int data=root->val;
        
        if(prev==-1)
        prev=data;
        else
        {
            if(prev>=data)
            {
                fl=1;
                return ;
            }
            else
            prev=data;
        }
        
        inorder(root->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        if(fl==0)
        return true;
        else
        return false;
    }
};
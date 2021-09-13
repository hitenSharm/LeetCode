// https://leetcode.com/problems/validate-binary-search-tree

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    
    vector<int>arr;
    int fl=0;
    
    void inorder(TreeNode* root)
    {
        if(!root)
        return ;
        
        inorder(root->left);
        
        int data=root->val;
        arr.push_back(data);
        
        if(arr.size()>1)
        {
            int last=arr.size()-1;
            if(arr[last]<=arr[last-1])
            {
                fl=1;
                return ;
            }
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
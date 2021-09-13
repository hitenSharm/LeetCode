// https://leetcode.com/problems/validate-binary-search-tree

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root ||!root->left ||!root->right)
        return true;
        
        if((root->left && root->left->val<root->val) && (root->right && root->right->val>root->val))
        {
            //cout<<root->left->val<<" "<<root->right->val<<endl;
            return (isValidBST(root->left) && isValidBST(root->right));
        }
        else
        return false;
        
    }
};
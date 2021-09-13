// https://leetcode.com/problems/range-sum-of-bst

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        int ans=0;
        if(root->val<low)
          return ans+=rangeSumBST(root->right,low,high);
        if(root->val>high)
           return ans+=rangeSumBST(root->left,low,high);
        return ans=ans+root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};
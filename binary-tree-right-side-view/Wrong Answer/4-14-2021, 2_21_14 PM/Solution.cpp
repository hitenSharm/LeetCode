// https://leetcode.com/problems/binary-tree-right-side-view

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:

    vector<int>ans;

    vector<int> rightSideView(TreeNode* root) {
        if(!root)
        return ans;
        ans.push_back(root->val);
        rightSideView(root->right);
        return ans;
    }
};
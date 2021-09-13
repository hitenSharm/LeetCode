// https://leetcode.com/problems/binary-tree-right-side-view

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    
    map<int,vector<int>>mp;
    
    void lvl(TreeNode* root,int d)
    {
        if(!root)
        return ;
        mp[d].push_back(root->val);
        
        lvl(root->left,d+1);
        lvl(root->right,d+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return vector<int>();
        lvl(root,0);
        vector<int>ans;
        for(auto it : mp)
        {
            int temp=it.second[it.second.size()-1];
            ans.push_back(temp);
        }
        return ans;
    }
};
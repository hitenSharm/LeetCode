// https://leetcode.com/problems/binary-tree-right-side-view

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    
    vector<vector<int>>arr;
    
    void lvl(TreeNode* root,int d)
    {
        if(!root)
        return ;
        
        if(arr.size()==d)
        arr.push_back(vector<int>());
        
        arr[d].push_back(root->val);
        lvl(root->left,d+1);
        lvl(root->right,d+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return vector<int>();
        lvl(root,0);
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++)
        {
            int temp=arr[i].size();
            ans.push_back((arr[i][temp-1]));
        }
        return ans;
    }
};
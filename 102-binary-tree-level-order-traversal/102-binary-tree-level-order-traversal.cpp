#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    
    void buildArray(vector<vector<int>>& ans,TreeNode* root,int depth)
    {
        if(!root)return ;
        
        if(ans.size()<=depth)ans.push_back(vector<int>());        
        ans[depth].push_back(root->val);
        buildArray(ans,root->left,depth+1);
        buildArray(ans,root->right,depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        buildArray(ans,root,0);
        return ans;
    }
};
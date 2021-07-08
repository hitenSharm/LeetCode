#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    
    bool chk(unordered_map<int,int>& ump)
    {
        int od=0;
        for(auto it:ump)
        {
            if(it.second%2!=0)od++;
            if(od>1)
            return false;
        }
        return true;
    }
    
    void dfs(TreeNode* root,unordered_map<int,int>& ump,int& ans)
    {
        if(!root->left and !root->right)
        {
            if(chk(ump))   
            ans++;
            return ;
        }
        if(root->left)
        {
            ump[root->left->val]++;
            dfs(root->left,ump,ans);
            ump[root->left->val]--;
            if(ump[root->left->val]==0)
            ump.erase(root->left->val);
        }
        if(root->right)
        {
            ump[root->right->val]++;
            dfs(root->right,ump,ans);
            ump[root->right->val]--;
            if(ump[root->right->val]==0)
            ump.erase(root->right->val);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>ump;
        int ans=0;
        ump[root->val]++;
        dfs(root,ump,ans);
        return ans;
    }
};
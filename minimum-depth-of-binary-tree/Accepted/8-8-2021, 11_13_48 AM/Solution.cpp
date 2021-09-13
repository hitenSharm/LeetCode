// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int ans=INT_MAX;
    void dfs(TreeNode* root,int depth)
    {
        if(!root)return ;
        if(!root->left and !root->right)
        {
            ans=min(ans,depth);
            return ;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int minDepth(TreeNode* root) {
        dfs(root,1);
        if(ans==INT_MAX)ans=0;
        return ans;
    }
};
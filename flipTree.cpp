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

    int index=0;

    bool dfs(TreeNode* root,vector<int>& ans,vector<int>& path)
    {
       if(!root || index>=path.size())return true;
       if(root->val!=path[index])return false;
       if(index+1<path.size() and root->left and root->left->val!=path[index+1])
       {
           if(root->right and root->right->val!=path[index+1])return false;
           ans.push_back(root->val);
           TreeNode* temp=root->right;
           root->right=root->left;
           root->left=temp;
       }
       index++;
       return (dfs(root->left,ans,path) and dfs(root->right,ans,path));//preorder
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>ans;
        if(!dfs(root,ans,voyage))return {-1};
        return ans;
    }
};
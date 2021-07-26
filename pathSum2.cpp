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

    void dfs(TreeNode* root,int& target,vector<vector<int>>& ans,vector<int>& temp,int sumHere)
    {
        if(!root) return ;
        if(sumHere == target and !root->left and !root->right)
        {
          ans.push_back(temp);
          return ;
        }
        if(root->right)
        {
            temp.push_back(root->right->val);
            dfs(root->right,target,ans,temp,sumHere+root->right->val);
            temp.pop_back();
        }
        if(root->left)
        {
            temp.push_back(root->left->val);
            dfs(root->left,target,ans,temp,sumHere+root->left->val);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        if(root)
        {
            temp.push_back(root->val);
            dfs(root,targetSum,ans,temp,root->val);
        }
        return ans;
    }
};
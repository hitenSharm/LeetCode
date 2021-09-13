// https://leetcode.com/problems/house-robber-iii

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

unordered_map<TreeNode*,int>ump;

class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL)return 0;      
        
        if(ump.find(root)!=ump.end())
        {
            return ump[root];
        }
        
        int val=0;
        val+=root->val;
        if(root->left)
        {
            val+=rob(root->left->left) + rob(root->left->right);
        }
        if(root->right)
        {
            val+=rob(root->right->left) + rob(root->right->right);
        }
        int val2=0;
        if(root->left)
        {
            val2+=rob(root->left);
        }
        if(root->right)
        {
            val2+=rob(root->right);
        }
        return ump[root]=max(val,val2);
    }
};
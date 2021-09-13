// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    int maxi=0;
    void traverse(TreeNode* root)
    {
        if(!root)return ;
        traverse(root->right);
        maxi+=root->val;
        root->val=maxi;
        traverse(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};
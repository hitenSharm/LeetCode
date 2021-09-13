// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        int mini=min(p->val,q->val);
        int maxi=max(p->val,q->val);
        if(root->val>maxi)return lowestCommonAncestor(root->left,p,q);
        else if(root->val<mini)return lowestCommonAncestor(root->right,p,q);
        else
        return root;
        //at this point ,if left subtree mein answer hota then range bhi usski hoti
        return nullptr;
    }
};
// https://leetcode.com/problems/binary-tree-pruning

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int pruning(TreeNode* root)
    {
        if(root==NULL)return 0;
        
        int l=0;
        int r=0;
        
        if(root->left)
        l=root->left->val+pruning(root->left);
        if(root->right)
        r=root->right->val+pruning(root->right);
        
        if(l==0)
        root->left=NULL;
        if(r==0)
        root->right=NULL;
        if(l==0 and r==0)
        root=NULL;
        
        return l+r;
    }

    TreeNode* pruneTree(TreeNode* root) {
        int temp=pruning(root);
        if(temp==0 and root->val!=1)
        root=NULL;
        return root;
    }
};
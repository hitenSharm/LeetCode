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

    void pruning(TreeNode* root,TreeNode* curr)
    {
        if(!root)return ;
        
        if(root->val!=1 and ((root->left and root->left->val!=1) || !root->left) and ((root->right and root->right->val!=1) || !root->right))
        {
            if(curr and curr->left and curr->left==root)
            curr->left=NULL;
            if(curr and curr->right and curr->right==root)
            curr->right=NULL;
            return ;
        }
        pruning(root->left,root);
        pruning(root->right,root);
        
    }

    TreeNode* pruneTree(TreeNode* root) {
        pruning(root,NULL);
        return root;
    }
};
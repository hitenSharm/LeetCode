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
    
    bool isSame(TreeNode* s,TreeNode*t)
    {
        if(!s and !t)return true;
        if(!s || !t)return false;
        return (s->val==t->val) and (isSame(s->left,t->left) and isSame(s->right,t->right));
    }
    
    bool inorder(TreeNode* root,TreeNode* subRoot)
    {
        if(!subRoot and !root)return true;
        if(!root || !subRoot)return false;
        return isSame(root,subRoot)||(inorder(root->left,subRoot) || inorder(root->right,subRoot));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inorder(root,subRoot);
    }
};
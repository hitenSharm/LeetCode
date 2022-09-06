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
    
    int traverse(TreeNode* root)
    {
        if(!root)return 0;
        if(!root->left and !root->right)return root->val;
        
        int curr=root->val;
        int l=traverse(root->left);
        int r=traverse(root->right);
        if(l==0){
            root->left=nullptr;
        }
        if(r==0){
            root->right=nullptr;
        }
        return curr+l+r;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int temp=traverse(root);
        if(temp==0)root=nullptr;
        return root;
    }
};
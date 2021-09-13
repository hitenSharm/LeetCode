// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    
    bool find(TreeNode* og,int value)
    {
        if(!og)return false;
        if(value==og->val)return true;
        if(value>og->val)
        {
            return find(og->right,value);
        }
        if(value<og->val)
        {
            return find(og->left,value);
        }
        return false;
    }
    
    bool inorder(TreeNode* root,int& k,TreeNode* og)
    {
        if(!root)return false;
        inorder(root->left,k,og);
        if(find(og,k-root->val))return true;
        inorder(root->right,k,og);
        
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {        
        if(inorder(root,k,root))return true;        
        return false;
    }
};
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class BSTIterator {
public:
    vector<int>arr;
    int i=0;
    void inorder(TreeNode* root)
    {
        if(!root)return ;
        inorder(root->left);     
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        i++;
        return arr[i-1];        
    }
    
    bool hasNext() {
        if(i<arr.size())return true;
        return false;
    }
};


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
    unordered_set<int>ust;
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        //inorder and map is obvious. array and map is obvious
        //nlogn is also obvious, har element ke liye seacrh for the other element        
        if(ust.find(k-root->val)!=ust.end())return true;
        ust.insert(root->val);
        return (findTarget(root->left,k) || findTarget(root->right,k));
    }
};
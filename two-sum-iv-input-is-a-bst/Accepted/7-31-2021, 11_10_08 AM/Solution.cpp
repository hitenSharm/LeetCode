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
    unordered_map<int,int>ump;
    void inorder(TreeNode* root)
    {
        if(!root)return ;
        inorder(root->left);
        ump[root->val]++;
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {        
        inorder(root);
        for(auto it:ump)
        {
            int num=it.first;            
            ump[num]--;            
            if(ump.find(k-num)!=ump.end() and ump[k-num]>0)return true;
            ump[num]++;
        }
        return false;
    }
};
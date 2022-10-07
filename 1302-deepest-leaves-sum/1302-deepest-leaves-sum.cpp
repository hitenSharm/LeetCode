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
    int ans=0;
    int depth=-1;
    
    void trav(TreeNode* r,int d)
    {
        if(!r)return ;
        trav(r->left,d+1);
        if(depth==d)
        {
            ans+=r->val;
        }
        else if(depth<d){
            depth=d;
            ans=r->val;
        }
        trav(r->right,d+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        trav(root,0);
        return ans;
    }
};
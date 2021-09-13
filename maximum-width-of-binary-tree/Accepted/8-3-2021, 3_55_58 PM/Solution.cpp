// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});
        unsigned long long maxi=0;
        while(!q.empty())
        {
            unsigned long long len=q.size();
            unsigned long long l=q.front().second;
            unsigned long long r;
            for(unsigned long long i=0;i<len;i++)
            {
                r=q.front().second;
                if(q.front().first->left)q.push({q.front().first->left,q.front().second*2});
                if(q.front().first->right)q.push({q.front().first->right,q.front().second*2+1});
                q.pop();
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};
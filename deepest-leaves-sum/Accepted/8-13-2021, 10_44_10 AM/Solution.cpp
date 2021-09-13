// https://leetcode.com/problems/deepest-leaves-sum

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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        int ans;        
        q.push(root);
        while(!q.empty())
        {
            int temp=0;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                temp+=q.front()->val;
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();                
            }
            ans=temp;
        }
        return ans;
    }
};
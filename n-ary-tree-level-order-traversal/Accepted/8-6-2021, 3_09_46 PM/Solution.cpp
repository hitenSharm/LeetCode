// https://leetcode.com/problems/n-ary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        if(!root)return {};
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty())
        {
            int len=q.size();
            vector<int>temp;
            for(int i=0;i<len;i++)
            {
                Node* tmp=q.front();q.pop();
                temp.push_back(tmp->val);
                vector<Node*>& kids=tmp->children;
                for(int j=0;j<kids.size();j++)
                {
                    q.push(kids[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
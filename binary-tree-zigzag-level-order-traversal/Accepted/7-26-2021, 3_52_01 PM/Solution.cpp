// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int rev=0;
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        stack<TreeNode*>st;
        vector<vector<int>>ans;
        rev=1;
        while(!q.empty())
        {
            int len=q.size();            
            vector<int>temp;
            for(int i=0;i<len;i++)
            {
                if(rev==1)
                {
                    TreeNode* rt=q.front();q.pop();
                    temp.push_back(rt->val);
                    if(rt->left)
                    {
                        st.push(rt->left);
                        q.push(rt->left);
                    }
                    if(rt->right)
                    {
                        st.push(rt->right);
                        q.push(rt->right);
                    }
                }
                else
                {
                    TreeNode* forSt=st.top();st.pop();
                    temp.push_back(forSt->val);
                    TreeNode* forq=q.front();q.pop();
                    if(forq->left)q.push(forq->left);
                    if(forq->right)q.push(forq->right);
                }
            }
            ans.push_back(temp);
            if(rev==1)rev=0;
            else
            rev=1;
        }
        return ans;
    }
};
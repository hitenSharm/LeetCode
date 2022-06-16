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
    vector<int>ans;
    void recu(Node* r)
    {
        if(!r)return ;
        ans.push_back(r->val);
        for(int i=0;i<r->children.size();++i)
        {
            recu(r->children[i]);
        }        
    }
    vector<int> preorder(Node* root) {
        recu(root);
        return ans;
    }
};
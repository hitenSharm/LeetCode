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
    Node* connect(Node* root) {
       if(!root)return root;
       queue<Node*>q; 
       q.push(root);
       while(!q.empty())
       {
           int len=q.size();
           Node* temp=q.front();q.pop();
           if(temp->left)q.push(temp->left);
           if(temp->right)q.push(temp->right);
           for(int i=0;i<len-1;i++)
           {
               Node* nxt=q.front();q.pop();
               temp->next=nxt;
               temp=nxt;
               if(temp->left)q.push(temp->left);
               if(temp->right)q.push(temp->right);
           }
       }
       return root;
    }
};
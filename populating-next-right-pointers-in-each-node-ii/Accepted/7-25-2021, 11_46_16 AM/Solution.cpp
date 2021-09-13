// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
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
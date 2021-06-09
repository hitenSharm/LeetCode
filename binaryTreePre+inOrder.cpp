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

    int index=0;
    unordered_map<int,int>ump;

    TreeNode* recu(vector<int>& preorder,int l,int r)
    {
      if(l>r)
        return NULL;
      TreeNode* temp = new TreeNode(preorder[index]);      
      index++;
      if(l==r)
        return temp;
      int inOrederIndex=ump[temp->val];

      temp->left=recu(preorder,l,inOrederIndex-1);
      temp->right=recu(preorder,inOrederIndex+1,r);

      return temp;
    }
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans;
        
        for(int i=0;i<inorder.size();i++)
          ump[inorder[i]]=i;

        ans=recu(preorder,0,preorder.size()-1);
        return ans;
    }
};
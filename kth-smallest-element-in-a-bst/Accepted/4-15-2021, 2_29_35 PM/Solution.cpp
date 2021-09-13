// https://leetcode.com/problems/kth-smallest-element-in-a-bst

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:

    vector<int>arr;
    
    void inOrder(TreeNode* root,int &k)
    {
        if(!root)
        return ;

        if(arr.size()==k)
        return ;

                        
        inOrder(root->left,k);
        
        int temp=root->val;
        arr.push_back(temp);
        
        inOrder(root->right,k);
        
    }

    int kthSmallest(TreeNode* root, int k) {
          if(!root)
              return 0;
          inOrder(root,k);
          return arr[k-1];
             
    }
};
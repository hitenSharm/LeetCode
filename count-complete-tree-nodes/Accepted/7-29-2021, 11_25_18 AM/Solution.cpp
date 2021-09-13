// https://leetcode.com/problems/count-complete-tree-nodes

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int subtract=0;
    int cntHt(TreeNode* root)
    {
        if(!root)return 0;
        int cnt=1;
        while(root)
        {
            if(root->left)
            {
                cnt++;
                root=root->left;
            }
            else
            break;
        }
        return cnt;
    }
    
    void extras(TreeNode* root,int currHt,int& ht)
    {
        if(!root)return ;
        
        if(currHt==ht-1)
        {
            if(root->left and root->right)return ;
            
            if(root->left and !root->right)
            {
                subtract++;
                return ;
            }
            
            if(!root->left and !root->right)
            {
                subtract+=2;
                return ;
            }
        }
        extras(root->right,currHt+1,ht);
        extras(root->left,currHt+1,ht);
    }
    
    int countNodes(TreeNode* root) {
        int ht=cntHt(root);        
        int ans=pow(2,ht)-1;
        extras(root,1,ht);
        ans=ans-subtract;
        return ans;
    }
};